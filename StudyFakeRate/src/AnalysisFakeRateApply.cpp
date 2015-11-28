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
        name_histo.second->Delete();
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
        std::string name      = m_reader.params().GetValue(std::string("FakeFactor." + to_string(i+1) + ".Name").c_str(), "");
        std::string fileName  = m_reader.params().GetValue(std::string("FakeFactor." + to_string(i+1) + ".File").c_str(), "");
        std::string histoName = m_reader.params().GetValue(std::string("FakeFactor." + to_string(i+1) + ".Histo").c_str(), "");
        TFile* file = TFile::Open(fileName.c_str());
        if(!file)
        {
            std::cout<<"ERROR: Cannot open file "<<fileName<<"\n";
            return false;
        }
        TGraphAsymmErrors* histo = dynamic_cast<TGraphAsymmErrors*>(file->Get(histoName.c_str()));
        if(!histo)
        {
            std::cout<<"ERROR: Cannot load histo "<<histoName<<" in file "<<fileName<<"\n";
            return false;
        }
        //histo->SetDirectory(0);
        file->Close();
        m_fakeFactors[name] = histo;
        std::cout<<"INFO:  Fake factor #"<<i+1<<"\n";
        std::cout<<"INFO:    Name  = "<<name<<"\n";
        std::cout<<"INFO:    File  = "<<fileName<<"\n";
        std::cout<<"INFO:    Histo = "<<histoName<<"\n";
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
    m_histos.FillHisto(0+hoffset, 0.5, weight, sysNum); // Number of events
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
    m_histos.Fill1BinHisto(120+hoffset, event().tau().gen_match, event().mvis(), weight, sysNum);
    m_histos.Fill1BinHisto(130+hoffset, event().tau().gen_match, event().mt(), weight, sysNum);

    // Correlation plots
    //m_histos.FillHisto(200+hoffset, event().mvis(), event().tau().Pt(), weight, sysNum);
    //m_histos.FillHisto(201+hoffset, event().mvis(), event().tau().Eta(), weight, sysNum);
    //m_histos.FillHisto(202+hoffset, event().mvis(), event().tau().decayMode, weight, sysNum);
}




/*****************************************************************/
double AnalysisFakeRateApply::retrieveFakeFactor(const std::string& sys)
/*****************************************************************/
{
    const auto& name_histo = m_fakeFactors.find(sys);
    if(name_histo==m_fakeFactors.end())
    {
        std::cout<<"WARNING: Cannot retrieve fake factor "<<sys<<". Please define it in the config file\n";
        return 1.;
    }
    const auto& histo = name_histo->second;
    double factor = 1.;
    double value = 0.;
    if(sys=="Weight_Inclusive")
    {
        value = 0.5;
    }
    else if(sys=="Weight_VsPt")
    {
        //bin = histo->GetXaxis()->FindBin(event().tau().Pt());
        value = event().tau().Pt();
    }
    else if(sys=="Weight_VsEta")
    {
        //bin = histo->GetXaxis()->FindBin(event().tau().Eta());
        value = event().tau().Eta();
    }
    else if(sys=="Weight_VsNVtx")
    {
        value = event().n_vertices();
    }
    else if(sys=="Weight_VsDecay")
    {
        value = event().tau().decayMode;
    }
    else if(sys=="Weight_VsPdgId")
    {
        value = fabs(event().tauMatch().pdgId);
        if((value>=6 && value<=20) || value>=22 || value==0) value = 2.; // FIXME: find a better way to discard values not used to determine the fake rates
        value *= (event().tau().sign_flip!=0 ? event().tau().sign_flip : 1);
    }
    factor = histo->Eval(value);
    return factor;
}
