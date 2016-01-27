/**
 *  @file  AnalysisFakeRateQCDSS.cpp
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <jsauvan@cern.ch>
 *
 *  @date    01/27/2016
 *
 *  @internal
 *     Created :  01/27/2016
 * Last update :  01/27/2016 06:07:14 PM
 *          by :  J.-B. Sauvan
 *
 * =====================================================================================
 */







#include <iostream>
#include <fstream>

#include "TVector2.h"
#include "TGraphAsymmErrors.h"
#include "TH2F.h"

#include "AnHiMaCMG/StudyFakeRate/interface/AnalysisFakeRateQCDSS.h"
#include "AnHiMaCMG/Core/interface/Utilities.h"




using namespace AnHiMa;
using namespace std;



/*****************************************************************/
AnalysisFakeRateQCDSS::AnalysisFakeRateQCDSS():IAnalysis()
/*****************************************************************/
{


}



/*****************************************************************/
AnalysisFakeRateQCDSS::~AnalysisFakeRateQCDSS()
/*****************************************************************/
{

}



/*****************************************************************/
bool AnalysisFakeRateQCDSS::initialize(const string& parameterFile)
/*****************************************************************/
{
    bool status = IAnalysis::initialize(parameterFile);
    if(!status) return status;
    event().connectVariables(m_inputChain);

    return true;
}


/*****************************************************************/
void AnalysisFakeRateQCDSS::execute()
/*****************************************************************/
{
    event().update();
    for(unsigned sel=0; sel<=5; sel++)
    {
        if(event().passSelectionFakeFactorsQCDSS(sel)) fillHistos(sel);
    }
}

/*****************************************************************/
void AnalysisFakeRateQCDSS::fillHistos(unsigned selection)
/*****************************************************************/
{
    short sysNum = 0;
    float weight = event().weight();
    int hoffset  = 1000*selection;


    // Event histos
    m_histos.FillHisto(0+hoffset, 1., weight, sysNum); // Number of events
    m_histos.FillHisto(1+hoffset, event().n_vertices(), weight, sysNum); 
    m_histos.FillHisto(2+hoffset, event().rho(), weight, sysNum); 
    //

    // Muon histos
     m_histos.FillHisto(10+hoffset, event().muon().Pt(), weight, sysNum);    
     m_histos.FillHisto(11+hoffset, event().muon().Eta(), weight, sysNum);
     m_histos.FillHisto(12+hoffset, event().muon().Phi(), weight, sysNum);

     // Tau histos
     m_histos.FillHisto(100+hoffset, event().tau().Pt(), weight, sysNum);    
     m_histos.FillHisto(101+hoffset, event().tau().Eta(), weight, sysNum);
     m_histos.FillHisto(102+hoffset, event().tau().Phi(), weight, sysNum);
     m_histos.FillHisto(103+hoffset, event().tau().decayMode, weight, sysNum);
     m_histos.FillHisto(104+hoffset, event().tau().againstMuon3, weight, sysNum);
     m_histos.FillHisto(105+hoffset, event().tau().againstElectronMVA5, weight, sysNum);
     m_histos.FillHisto(106+hoffset, event().tau().byCombinedIsolationDeltaBetaCorrRaw3Hits, weight, sysNum);
     m_histos.FillHisto(107+hoffset, fabs(event().tauMatch().pdgId)*(event().tau().sign_flip!=0 ? event().tau().sign_flip : 1), weight, sysNum);
     m_histos.FillHisto(108+hoffset, event().tauJetMatch().Pt(), weight, sysNum); 

     // 2D histograms
     m_histos.FillHisto(200+hoffset, event().tau().Pt(), fabs(event().tau().Eta()), weight, sysNum);
     m_histos.FillHisto(201+hoffset, event().tau().Pt(), event().tau().decayMode, weight, sysNum);
     m_histos.FillHisto(202+hoffset, event().tau().Pt(), fabs(event().tauMatch().pdgId)*(event().tau().sign_flip!=0 ? event().tau().sign_flip : 1), weight, sysNum);
     m_histos.FillHisto(203+hoffset, event().tau().Pt(), fabs(event().tauMatch().pdgId)*(event().tau().sign_flip!=0 ? event().tau().sign_flip : 1), weight, sysNum);
     m_histos.FillHisto(204+hoffset, event().tauJetMatch().Pt(), event().tau().Pt(), weight, sysNum);
     m_histos.FillHisto(205+hoffset, event().tauJetMatch().Pt(), event().tau().decayMode, weight, sysNum);

     // arrays
     m_histos.Fill1BinHisto(300+hoffset, fabs(event().tau().Eta()), event().tau().Pt(), weight, sysNum);
     m_histos.Fill1BinHisto(310+hoffset, event().tau().decayMode, event().tau().Pt(), weight, sysNum);
     m_histos.Fill1BinHisto(320+hoffset, fabs(event().tauMatch().pdgId)*(event().tau().sign_flip!=0 ? event().tau().sign_flip : 1), event().tau().Pt(), weight, sysNum);
     m_histos.Fill1BinHisto(340+hoffset, fabs(event().tauMatch().pdgId)*(event().tau().sign_flip!=0 ? event().tau().sign_flip : 1), event().tau().Pt(), weight, sysNum);
     m_histos.Fill1BinHisto(360+hoffset, event().tau().Pt(), event().tauJetMatch().Pt(), weight, sysNum);
     m_histos.Fill1BinHisto(370+hoffset, event().tau().decayMode, event().tauJetMatch().Pt(), weight, sysNum);

}


