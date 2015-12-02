/**
 *  @file  AnalysisFakeRateApply.cpp
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <sauvan@llr.in2p3.fr>
 *
 *  @date    20/11/2015
 *
 *  @internal
 *     Created :  20/11/2015
 * Last update :  20/11/2015 14:09:28
 *          by :  JB Sauvan
 *
 * =====================================================================================
 */





#include <iostream>
#include <fstream>

#include "TVector2.h"
#include "TGraphAsymmErrors.h"
#include "TH2F.h"

#include "AnHiMaCMG/StudyFakeRate/interface/AnalysisFakeRateApply.h"
#include "AnHiMaCMG/Core/interface/Utilities.h"




using namespace AnHiMa;
using namespace std;



/*****************************************************************/
AnalysisFakeRateApply::AnalysisFakeRateApply():IAnalysis()
/*****************************************************************/
{


}



/*****************************************************************/
AnalysisFakeRateApply::~AnalysisFakeRateApply()
/*****************************************************************/
{
    for(auto& name_histo : m_fakeFactors)
    {
        name_histo.second.second->Delete();
    }
}



/*****************************************************************/
bool AnalysisFakeRateApply::initialize(const string& parameterFile)
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
void AnalysisFakeRateApply::execute()
/*****************************************************************/
{
    event().update();
    for(unsigned sel=0; sel<=2; sel++)
    {
        if(event().passSelection(sel))
        {
            for(const auto& sys : systematicList())
            {
                fillHistos(sel, sys);
            }
        }
    }
}

/*****************************************************************/
void AnalysisFakeRateApply::fillHistos(unsigned selection, const std::string& sys)
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
    m_histos.FillHisto(13+hoffset, event().muon().reliso05, weight, sysNum);


    // Tau histos
    m_histos.FillHisto(20+hoffset, event().tau().Pt(), weight, sysNum);    
    m_histos.FillHisto(21+hoffset, event().tau().Eta(), weight, sysNum);
    m_histos.FillHisto(22+hoffset, event().tau().Phi(), weight, sysNum);
    m_histos.FillHisto(23+hoffset, event().tau().decayMode, weight, sysNum);
    m_histos.FillHisto(24+hoffset, event().tau().againstMuon3, weight, sysNum);
    m_histos.FillHisto(25+hoffset, event().tau().againstElectronMVA5, weight, sysNum);
    m_histos.FillHisto(26+hoffset, event().tau().byCombinedIsolationDeltaBetaCorrRaw3Hits, weight, sysNum);
    m_histos.FillHisto(27+hoffset, fabs(event().tauMatch().pdgId)*(event().tau().sign_flip!=0 ? event().tau().sign_flip : 1), weight, sysNum);

    // MuTau histos
    m_histos.FillHisto(50+hoffset, event().mvis(), weight, sysNum);
    m_histos.FillHisto(51+hoffset, event().mt(), weight, sysNum);

    // Histos depending on gen_match
    m_histos.Fill1BinHisto(100+hoffset, event().tau().gen_match, 0.5, weight, sysNum);
    m_histos.Fill1BinHisto(110+hoffset, event().tau().gen_match, fakeFactor, event().weight(), sysNum);
    m_histos.Fill1BinHisto(120+hoffset, event().tau().gen_match, event().tau().Pt(), event().weight(), sysNum);
    m_histos.Fill1BinHisto(130+hoffset, event().tau().gen_match, event().tau().Eta(), event().weight(), sysNum);
    m_histos.Fill1BinHisto(140+hoffset, event().tau().gen_match, event().tau().decayMode, event().weight(), sysNum);
    m_histos.Fill1BinHisto(150+hoffset, event().tau().gen_match, fabs(event().tauMatch().pdgId)*(event().tau().sign_flip!=0 ? event().tau().sign_flip : 1), event().weight(), sysNum);
    m_histos.Fill1BinHisto(160+hoffset, event().tau().gen_match, event().mvis(), weight, sysNum);
    m_histos.Fill1BinHisto(170+hoffset, event().tau().gen_match, event().mt(), weight, sysNum);

    // Correlation plots
    //m_histos.FillHisto(200+hoffset, event().mvis(), event().tau().Pt(), weight, sysNum);
    //m_histos.FillHisto(201+hoffset, event().mvis(), event().tau().Eta(), weight, sysNum);
    //m_histos.FillHisto(202+hoffset, event().mvis(), event().tau().decayMode, weight, sysNum);
}




/*****************************************************************/
double AnalysisFakeRateApply::retrieveFakeFactor(const std::string& sys)
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
    // 1D fake factor
    if(sys=="Weight_Inclusive")
    {
        values.push_back(1.);
    }
    else if(sys=="Weight_VsPt")
    {
        values.push_back(event().tau().Pt());
    }
    else if(sys=="Weight_VsEta")
    {
        values.push_back(event().tau().Eta());
    }
    else if(sys=="Weight_VsNVtx")
    {
        values.push_back(event().n_vertices());
    }
    else if(sys=="Weight_VsDecay")
    {
        values.push_back(event().tau().decayMode);
    }
    else if(sys=="Weight_VsPdgId")
    {
        double value = fabs(event().tauMatch().pdgId);
        if((value>=6 && value<=20) || value>=22 || value==0) value = 2.; // FIXME: find a better way to discard values not used to determine the fake rates
        values.push_back( value * (event().tau().sign_flip!=0 ? event().tau().sign_flip : 1));
    }
    // 2D fake factor
    else if(sys=="Weight_VsPtEta")
    {
        values.push_back(event().tau().Pt());
        values.push_back(fabs(event().tau().Eta())); // Careful: This is absolute value of eta
    }
    else if(sys=="Weight_VsPtDecay")
    {
        values.push_back(event().tau().Pt());
        values.push_back(event().tau().decayMode);
    }
    else if(sys=="Weight_VsPtPdgId")
    {
        values.push_back(event().tau().Pt());
        double valueId = fabs(event().tauMatch().pdgId);
        if((valueId>=6 && valueId<=20) || valueId>=22 || valueId==0) valueId = 2.; // FIXME: find a better way to discard values not used to determine the fake rates
        values.push_back( valueId * (event().tau().sign_flip!=0 ? event().tau().sign_flip : 1));
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
