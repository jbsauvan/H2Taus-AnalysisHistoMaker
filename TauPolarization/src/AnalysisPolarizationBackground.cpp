/**
 *  @file  AnalysisPolarizationBackground.cpp
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <sauvan@llr.in2p3.fr>
 *
 *  @date    12/14/2015
 *
 *  @internal
 *     Created :  12/14/2015
 * Last update :  12/14/2015 04:51:55 PM
 *          by :  JB Sauvan
 *
 * =====================================================================================
 */







#include <iostream>
#include <fstream>

#include "TVector2.h"
#include "TGraphAsymmErrors.h"
#include "TH2F.h"

#include "AnHiMaCMG/TauPolarization/interface/AnalysisPolarizationBackground.h"
#include "AnHiMaCMG/Core/interface/Utilities.h"




using namespace AnHiMa;
using namespace std;



/*****************************************************************/
AnalysisPolarizationBackground::AnalysisPolarizationBackground():IAnalysis()
/*****************************************************************/
{


}



/*****************************************************************/
AnalysisPolarizationBackground::~AnalysisPolarizationBackground()
/*****************************************************************/
{

}



/*****************************************************************/
bool AnalysisPolarizationBackground::initialize(const string& parameterFile)
/*****************************************************************/
{
    bool status = IAnalysis::initialize(parameterFile);
    if(!status) return status;
    event().connectVariables(m_inputChain);

    // Read parameters
    unsigned nFakeFactors = m_reader.params().GetValue("NumberOfFakeFactors", 0);
    std::cout<<"INFO: Number of fake factors = "<<nFakeFactors<<"\n";
    for(unsigned i=0;i<nFakeFactors; i++)
    {
        std::string name       = m_reader.params().GetValue(std::string("FakeFactor." + to_string(i+1) + ".Name").c_str(), "");
        std::string fileName   = m_reader.params().GetValue(std::string("FakeFactor." + to_string(i+1) + ".File").c_str(), "");
        std::string objectName = m_reader.params().GetValue(std::string("FakeFactor." + to_string(i+1) + ".Object").c_str(), "");
        std::string type       = m_reader.params().GetValue(std::string("FakeFactor." + to_string(i+1) + ".Type").c_str(), "");
        TFile* file = TFile::Open(fileName.c_str());
        if(!file)
        {
            std::cout<<"ERROR: Cannot open file "<<fileName<<"\n";
            return false;
        }
        TObject* object = file->Get(objectName.c_str());
        if(!object)
        {
            std::cout<<"ERROR: Cannot load object "<<objectName<<" in file "<<fileName<<"\n";
            return false;
        }
        if(object->InheritsFrom("TH1")) dynamic_cast<TH1*>(object)->SetDirectory(0);
        file->Close();
        m_fakeFactors[name] = std::make_pair(type, object);
        std::cout<<"INFO:  Fake factor #"<<i+1<<"\n";
        std::cout<<"INFO:    Name   = "<<name<<"\n";
        std::cout<<"INFO:    File   = "<<fileName<<"\n";
        std::cout<<"INFO:    Object = "<<objectName<<"\n";
        std::cout<<"INFO:    Type   = "<<type<<"\n";
    }

    return true;
}


/*****************************************************************/
void AnalysisPolarizationBackground::execute()
/*****************************************************************/
{
    event().update();
    for(unsigned applyMTcut=0; applyMTcut<=1; applyMTcut++ )
    {
        for(unsigned sel=0; sel<=3; sel++)
        {
            unsigned selectionId = applyMTcut*20+sel;
            if(event().passSelectionForPolarization(selectionId))
            {
                for(const auto& sys : systematicList())
                {
                    fillHistos(selectionId, sys);
                }
            }
        }
    }
}

/*****************************************************************/
void AnalysisPolarizationBackground::fillHistos(unsigned selection, const std::string& sys)
/*****************************************************************/
{


    short sysNum = systematicNumber(sys);
    float weight = event().weight();
    float fakeFactor = (sys!="" ? retrieveFakeFactor(sys) : 1.);
    weight *= fakeFactor;
    int hoffset  = 1000*selection;


    // Event histos
    m_histos.FillHisto(0+hoffset, 1., weight, sysNum); // Number of events
    m_histos.FillHisto(1+hoffset, event().n_vertices(), weight, sysNum); 
    m_histos.FillHisto(2+hoffset, event().rho(), weight, sysNum); 
    m_histos.FillHisto(3+hoffset, fakeFactor, event().weight(), sysNum); 
    //

    // Muon histos
    m_histos.FillHisto(10+hoffset, event().muon().Pt(), weight, sysNum);    
    m_histos.FillHisto(11+hoffset, event().muon().Eta(), weight, sysNum);
    m_histos.FillHisto(12+hoffset, event().muon().Phi(), weight, sysNum);


    // Tau histos
    m_histos.FillHisto(20+hoffset, event().tau().Pt(), weight, sysNum);    
    m_histos.FillHisto(21+hoffset, event().tau().Eta(), weight, sysNum);
    m_histos.FillHisto(22+hoffset, event().tau().Phi(), weight, sysNum);
    m_histos.FillHisto(23+hoffset, event().tau().decayMode, weight, sysNum);
    m_histos.FillHisto(24+hoffset, fabs(event().tauMatch().pdgId)*(event().tau().sign_flip!=0 ? event().tau().sign_flip : 1), weight, sysNum);
    m_histos.FillHisto(25+hoffset, event().tau().nc_ratio, weight, sysNum);

    // MuTau histos
    m_histos.FillHisto(50+hoffset, event().mvis(), weight, sysNum);
    m_histos.FillHisto(51+hoffset, event().mt(), weight, sysNum);

    // Histos depending on gen_match
    m_histos.Fill1BinHisto(100+hoffset, event().tau().gen_match, 0.5, weight, sysNum);
    m_histos.Fill1BinHisto(120+hoffset, event().tau().gen_match, event().tau().Pt(), event().weight(), sysNum);
    m_histos.Fill1BinHisto(130+hoffset, event().tau().gen_match, event().tau().Eta(), event().weight(), sysNum);
    m_histos.Fill1BinHisto(140+hoffset, event().tau().gen_match, event().mvis(), weight, sysNum);
    m_histos.Fill1BinHisto(150+hoffset, event().tau().gen_match, event().tau().nc_ratio, weight, sysNum);

}




/*****************************************************************/
double AnalysisPolarizationBackground::retrieveFakeFactor(const std::string& sys)
/*****************************************************************/
{
    const auto& name_object = m_fakeFactors.find(sys);
    if(name_object==m_fakeFactors.end())
    {
        std::cout<<"WARNING: Cannot retrieve fake factor "<<sys<<". Please define it in the config file\n";
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
    if(sys.find("VsPtEta")!=std::string::npos)
    {
        values.push_back(event().tau().Pt());
        values.push_back(fabs(event().tau().Eta())); // Careful: This is absolute value of eta
    }
    else if(sys.find("VsPtDecay")!=std::string::npos)
    {
        values.push_back(event().tau().Pt());
        values.push_back(event().tau().decayMode);
    }
    else if(sys.find("VsPtPdgId")!=std::string::npos)
    {
        values.push_back(event().tau().Pt());
        double valueId = fabs(event().tauMatch().pdgId);
        if((valueId>=6 && valueId<=20) || valueId>=22 || valueId==0) valueId = 2.; // FIXME: find a better way to discard values not used to determine the fake rates
        values.push_back( valueId * (event().tau().sign_flip!=0 ? event().tau().sign_flip : 1));
    }
    // 1D fake factor
    else if(sys.find("Inclusive")!=std::string::npos)
    {
        values.push_back(1.);
    }
    else if(sys.find("VsPt")!=std::string::npos)
    {
        values.push_back(event().tau().Pt());
    }
    else if(sys.find("VsEta")!=std::string::npos)
    {
        values.push_back(event().tau().Eta());
    }
    else if(sys.find("VsNVtx")!=std::string::npos)
    {
        values.push_back(event().n_vertices());
    }
    else if(sys.find("VsDecay")!=std::string::npos)
    {
        values.push_back(event().tau().decayMode);
    }
    else if(sys.find("VsPdgId")!=std::string::npos)
    {
        double value = fabs(event().tauMatch().pdgId);
        if((value>=6 && value<=20) || value>=22 || value==0) value = 2.; // FIXME: find a better way to discard values not used to determine the fake rates
        values.push_back( value * (event().tau().sign_flip!=0 ? event().tau().sign_flip : 1));
    }

    // Retrieve fake factor depending on type of object
    if(type=="1DGraph")
    {
        factor = dynamic_cast<TGraphAsymmErrors*>(object)->Eval(values[0]);
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
