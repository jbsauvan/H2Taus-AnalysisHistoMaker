/**
 *  @file  FakeFactors.cpp
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <sauvan@llr.in2p3.fr>
 *
 *  @date    01/04/2016
 *
 *  @internal
 *     Created :  01/04/2016
 * Last update :  01/04/2016 03:10:22 PM
 *          by :  JB Sauvan
 *
 * =====================================================================================
 */


#include "AnHiMaCMG/H2TausCommon/interface/FakeFactors.h"
#include "TFile.h"
#include "TGraphAsymmErrors.h"
#include "TF1.h"
#include "TH2F.h"


using namespace AnHiMa;




/*****************************************************************/
FakeFactors::FakeFactors()
/*****************************************************************/
{
}


/*****************************************************************/
FakeFactors::~FakeFactors()
/*****************************************************************/
{
    for(auto& name_histo : m_fakeFactors)
    {
        name_histo.second.second->Delete();
    }
}



/*****************************************************************/
bool  FakeFactors::addFakeFactor(const std::string& name, const std::string& fileName, const std::string& objectName, const std::string& type)
/*****************************************************************/
{
    TFile* file = TFile::Open(fileName.c_str());
    if(!file)
    {
        std::cout<<"ERROR: Cannot open fake-factor file "<<fileName<<"\n";
        return false;
    }
    TObject* object = file->Get(objectName.c_str());
    if(!object)
    {
        std::cout<<"ERROR: Cannot load fake-factor object "<<objectName<<" in file "<<fileName<<"\n";
        return false;
    }
    if(object->InheritsFrom("TH1")) dynamic_cast<TH1*>(object)->SetDirectory(0);
    file->Close();
    m_fakeFactors[name] = std::make_pair(type, object);

    return true;
}



/*****************************************************************/
double FakeFactors::retrieveFakeFactor(const std::string& name, const EventMuTau& event, bool fluctuate)
/*****************************************************************/
{
    const auto& name_object = m_fakeFactors.find(name);
    if(name_object==m_fakeFactors.end())
    {
        std::cout<<"WARNING: Cannot retrieve fake factor "<<name<<". Please define it in the config file\n";
        return 1.;
    }
    const auto& type_object = name_object->second;
    TObject* object = type_object.second;
    const std::string& type = type_object.first;
    double factor = 1.;
    std::vector<double> values;
    // CAREFUL: it has to be checked that it doesn't go in the wrong place because
    // of strings included in other strings. That's why 2D fake factors come first.
    // 2D fake factor
    if(name.find("VsPtEta")!=std::string::npos)
    {
        values.push_back(event.tau().Pt());
        values.push_back(fabs(event.tau().Eta())); // Careful: This is absolute value of eta
    }
    else if(name.find("VsPtDecay")!=std::string::npos)
    {
        values.push_back(event.tau().Pt());
        values.push_back(event.tau().decayMode);
    }
    else if(name.find("VsPtPdgId")!=std::string::npos)
    {
        values.push_back(event.tau().Pt());
        double valueId = fabs(event.tauMatch().pdgId);
        if((valueId>=6 && valueId<=20) || valueId>=22 || valueId==0) valueId = 2.; // FIXME: find a better way to discard values not used to determine the fake rates
        values.push_back( valueId * (event.tau().sign_flip!=0 ? event.tau().sign_flip : 1));
    }
    // 1D fake factor
    else if(name.find("Inclusive")!=std::string::npos)
    {
        values.push_back(1.);
    }
    else if(name.find("VsPt")!=std::string::npos)
    {
        values.push_back(event.tau().Pt());
    }
    else if(name.find("VsEta")!=std::string::npos)
    {
        values.push_back(event.tau().Eta());
    }
    else if(name.find("VsNVtx")!=std::string::npos)
    {
        values.push_back(event.n_vertices());
    }
    else if(name.find("VsDecay")!=std::string::npos)
    {
        values.push_back(event.tau().decayMode);
    }
    else if(name.find("VsPdgId")!=std::string::npos)
    {
        double value = fabs(event.tauMatch().pdgId);
        if((value>=6 && value<=20) || value>=22 || value==0) value = 2.; // FIXME: find a better way to discard values not used to determine the fake rates
        values.push_back( value * (event.tau().sign_flip!=0 ? event.tau().sign_flip : 1));
    }

    // Retrieve fake factor depending on type of object
    if(type=="1DGraph")
    {
        TGraphAsymmErrors* graph = dynamic_cast<TGraphAsymmErrors*>(object);
        factor = graph->Eval(values[0]);
        if(fluctuate)
        {
            // Find closest point
            int closest = -1;
            double dxmin = 9999.;
            for(int p=0;p<graph->GetN();p++)
            {
                if(fabs(graph->GetX()[p]-values[0])<dxmin)
                {
                    dxmin = fabs(graph->GetX()[p]-values[0]);
                    closest = p;
                }
            }
            // Use same relative errors as the closest point
            double errorUp   = graph->GetEYhigh()[closest]*factor/graph->GetY()[closest]; 
            double errorDown = graph->GetEYlow()[closest]*factor/graph->GetY()[closest];
            // Get random fluctuation using Gaussian with different positive and negative sigma
            TF1 * f = new TF1("f",[&](double*x, double *p){ return (x[0]>0 ? TMath::Gaus(x[0], factor, errorUp) : TMath::Gaus(x[0], factor, errorDown)); }, factor-5.*errorDown, factor+5.*errorUp, 0); 
            factor = f->GetRandom();
            f->Delete();
        }
    }
    else if(type=="2DHisto")
    {
        TH2F* histo = dynamic_cast<TH2F*>(object);
        int bx = histo->GetXaxis()->FindBin(values[0]);
        int by = histo->GetYaxis()->FindBin(values[1]);
        factor = histo->GetBinContent(bx,by);
    }
    else
    {
        std::cout<<"ERROR: Unknown type of fake factor\n";
    }
    return factor;
}
