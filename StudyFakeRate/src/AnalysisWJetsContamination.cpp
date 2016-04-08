/**
 *  @file  AnalysisWJetsContamination.cpp
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <sauvan@llr.in2p3.fr>
 *
 *  @date    01/04/2016
 *
 *  @internal
 *     Created :  01/04/2016
 * Last update :  01/04/2016 02:05:51 PM
 *          by :  JB Sauvan
 *
 * =====================================================================================
 */






#include <iostream>
#include <fstream>

#include "TVector2.h"
#include "TGraphAsymmErrors.h"
#include "TH2F.h"

#include "AnHiMaCMG/StudyFakeRate/interface/AnalysisWJetsContamination.h"
#include "AnHiMaCMG/Core/interface/Utilities.h"




using namespace AnHiMa;
using namespace std;



/*****************************************************************/
AnalysisWJetsContamination::AnalysisWJetsContamination():IAnalysis()
/*****************************************************************/
{


}



/*****************************************************************/
AnalysisWJetsContamination::~AnalysisWJetsContamination()
/*****************************************************************/
{

}



/*****************************************************************/
bool AnalysisWJetsContamination::initialize(const string& parameterFile)
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

        status = m_fakeFactors.addFakeFactor(name, fileName, objectName, type);
        if(!status) return status;

        std::cout<<"INFO:  Fake factor #"<<i+1<<"\n";
        std::cout<<"INFO:    Name   = "<<name<<"\n";
        std::cout<<"INFO:    File   = "<<fileName<<"\n";
        std::cout<<"INFO:    Object = "<<objectName<<"\n";
        std::cout<<"INFO:    Type   = "<<type<<"\n";
    }

    return true;
}


/*****************************************************************/
void AnalysisWJetsContamination::execute()
/*****************************************************************/
{
    event().update();
    for(unsigned sel=0; sel<=5; sel++)
    {
        unsigned selectionId = sel;
        if(event().passSelectionWJetsContamination(selectionId))
        {
            for(const auto& sys : systematicList())
            {
                fillHistos(selectionId, sys);
            }
        }
    }
}

/*****************************************************************/
void AnalysisWJetsContamination::fillHistos(unsigned selection, const std::string& sys)
/*****************************************************************/
{


    short sysNum = systematicNumber(sys);
    float weight = event().weight();
    float fakeFactor = (sys!="" ? m_fakeFactors.retrieveFakeFactor(sys, event()) : 1.);
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
    m_histos.FillHisto(22+hoffset, event().tau().decayMode, weight, sysNum);
    m_histos.FillHisto(23+hoffset, fabs(event().tauMatch().pdgId)*(event().tau().sign_flip!=0 ? event().tau().sign_flip : 1), weight, sysNum);
    m_histos.FillHisto(24+hoffset, event().tau().byCombinedIsolationDeltaBetaCorrRaw3Hits, weight, sysNum);
    m_histos.FillHisto(25+hoffset, event().tau().photonPtSumOutsideSignalCone/event().tau().Pt(), weight, sysNum);
    m_histos.FillHisto(26+hoffset, event().tauJetMatch().Pt(), weight, sysNum);    
    m_histos.FillHisto(27+hoffset, event().tau().byIsolationMVArun2v1DBoldDMwLTraw, weight, sysNum);

    // MuTau histos
    m_histos.FillHisto(50+hoffset, event().mvis(), weight, sysNum);
    m_histos.FillHisto(51+hoffset, event().mt(), weight, sysNum);

}


