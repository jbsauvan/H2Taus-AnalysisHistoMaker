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

        status = m_fakeFactors.addFakeFactor(name, fileName, objectName);
        if(!status) return status;

        std::cout<<"INFO:  Fake factor #"<<i+1<<"\n";
        std::cout<<"INFO:    Name   = "<<name<<"\n";
        std::cout<<"INFO:    File   = "<<fileName<<"\n";
        std::cout<<"INFO:    Object = "<<objectName<<"\n";
    }

    return true;
}


/*****************************************************************/
void AnalysisFakeRateApply::execute()
/*****************************************************************/
{
    event().update();
    for(unsigned applyMTcut=0; applyMTcut<=1; applyMTcut++ )
    {
        // no isolation, medium isolation, anti- medium isolation
        for(unsigned sel=0; sel<3; sel++)
        {
            unsigned selectionId = applyMTcut*20+sel;
            if(event().passSelection(selectionId))
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
void AnalysisFakeRateApply::fillHistos(unsigned selection, const std::string& sys)
/*****************************************************************/
{


    short sysNum = systematicNumber(sys);
    float weight = event().weight();
    // Retrieve fake factor name and systematic shift
    std::vector<std::string> tokens;
    tokenize(sys, tokens, "__");
    std::string fakeFactorName("");
    if(tokens.size()>0) fakeFactorName = tokens[0];
    std::string sysName("");
    if(tokens.size()>1) sysName = tokens[1];
    float fakeFactor = (sys!="" ? m_fakeFactors.retrieveFakeFactor(fakeFactorName, event(), sysName) : 1.);
    weight *= fakeFactor;
    int hoffset  = 1000*selection;


    // Event histos
    m_histos.FillHisto(0+hoffset, 1., weight, sysNum); // Number of events
    m_histos.FillHisto(1+hoffset, event().n_vertices(), weight, sysNum); 
    m_histos.FillHisto(2+hoffset, event().rho(), weight, sysNum); 
    m_histos.FillHisto(3+hoffset, fakeFactor, event().weight(), sysNum); 
    m_histos.FillHisto(4+hoffset, event().n_jets(), weight, sysNum);
    m_histos.FillHisto(5+hoffset, event().n_jets_puid(), weight, sysNum);
    m_histos.FillHisto(6+hoffset, event().n_jets_20(), weight, sysNum);
    m_histos.FillHisto(7+hoffset, event().n_jets_20_puid(), weight, sysNum);
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
    m_histos.FillHisto(25+hoffset, event().tau().againstElectronMVA6, weight, sysNum);
    m_histos.FillHisto(26+hoffset, event().tau().byCombinedIsolationDeltaBetaCorrRaw3Hits, weight, sysNum);
    m_histos.FillHisto(27+hoffset, fabs(event().tauMatch().pdgId)*(event().tau().sign_flip!=0 ? event().tau().sign_flip : 1), weight, sysNum);
    m_histos.FillHisto(28+hoffset, event().tau().byIsolationMVArun2v1DBoldDMwLTraw, weight, sysNum);

    // MuTau histos
    m_histos.FillHisto(50+hoffset, event().mvis(), weight, sysNum);
    m_histos.FillHisto(51+hoffset, event().mvis(), weight, sysNum);
    m_histos.FillHisto(52+hoffset, event().mvis(), weight, sysNum);
    m_histos.FillHisto(53+hoffset, event().mt(), weight, sysNum);
    m_histos.FillHisto(54+hoffset, event().mvis(), event().mt(), weight, sysNum);

    // Histos depending on gen_match
    //m_histos.Fill1BinHisto(100+hoffset, event().tau().gen_match, 0.5, weight, sysNum);
    //m_histos.Fill1BinHisto(110+hoffset, event().tau().gen_match, fakeFactor, event().weight(), sysNum);
    //m_histos.Fill1BinHisto(120+hoffset, event().tau().gen_match, event().tau().Pt(), event().weight(), sysNum);
    //m_histos.Fill1BinHisto(130+hoffset, event().tau().gen_match, event().tau().Eta(), event().weight(), sysNum);
    //m_histos.Fill1BinHisto(140+hoffset, event().tau().gen_match, event().tau().decayMode, event().weight(), sysNum);
    //m_histos.Fill1BinHisto(150+hoffset, event().tau().gen_match, fabs(event().tauMatch().pdgId)*(event().tau().sign_flip!=0 ? event().tau().sign_flip : 1), event().weight(), sysNum);
    //m_histos.Fill1BinHisto(160+hoffset, event().tau().gen_match, event().mvis(), weight, sysNum);
    //m_histos.Fill1BinHisto(170+hoffset, event().tau().gen_match, event().mvis(), weight, sysNum);
    //m_histos.Fill1BinHisto(180+hoffset, event().tau().gen_match, event().mvis(), weight, sysNum);
    //m_histos.Fill1BinHisto(190+hoffset, event().tau().gen_match, event().mt(), weight, sysNum);

    //m_histos.FillNtuple(500+hoffset, (double)event().run(), (double)event().event(), weight, sysNum);

}


