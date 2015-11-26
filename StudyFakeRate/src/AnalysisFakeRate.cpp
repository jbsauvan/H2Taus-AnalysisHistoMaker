/**
 *  @file  AnalysisFakeRate.cpp
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <sauvan@llr.in2p3.fr>
 *
 *  @date    19/11/2015
 *
 *  @internal
 *     Created :  19/11/2015
 * Last update :  19/11/2015 10:51:37
 *          by :  JB Sauvan
 *
 * =====================================================================================
 */





#include <iostream>
#include <fstream>

#include "TVector2.h"

#include "AnHiMaCMG/StudyFakeRate/interface/AnalysisFakeRate.h"
#include "AnHiMaCMG/Core/interface/Utilities.h"




using namespace AnHiMa;
using namespace std;



/*****************************************************************/
AnalysisFakeRate::AnalysisFakeRate():IAnalysis()
/*****************************************************************/
{

}



/*****************************************************************/
AnalysisFakeRate::~AnalysisFakeRate()
/*****************************************************************/
{
}



/*****************************************************************/
bool AnalysisFakeRate::initialize(const string& parameterFile)
/*****************************************************************/
{
    bool status = IAnalysis::initialize(parameterFile);
    if(!status) return status;
    event().connectVariables(m_inputChain);

    // Read parameters
    //string pileupParamsFile = m_reader.params().GetValue("PileupParams", "/home/llr/cms/sauvan/CMSSW/HGCAL/CMSSW_6_2_0_SLHC19/src/AnHiMaCMG/ElectronClusterThreshold/data/thresholdParameters.txt");

    return true;
}


/*****************************************************************/
void AnalysisFakeRate::execute()
/*****************************************************************/
{
    event().update();
    for(unsigned sel=0; sel<=2; sel++)
    {
        if(event().passSelection(sel)) fillHistos(sel);
    }
}

/*****************************************************************/
void AnalysisFakeRate::fillHistos(unsigned selection)
/*****************************************************************/
{

    short sysNum = 0;
    float weight = event().weight();
    int hoffset  = 1000*selection;



    // Event histos
    m_histos.FillHisto(0+hoffset, 0.5, weight, sysNum); // Number of events
    m_histos.FillHisto(1+hoffset, event().n_vertices(), weight, sysNum); 
    m_histos.FillHisto(2+hoffset, event().rho(), weight, sysNum); 
    //

    // Muon histos
     m_histos.FillHisto(10+hoffset, event().muon(0).Pt(), weight, sysNum);    
     m_histos.FillHisto(11+hoffset, event().muon(0).Eta(), weight, sysNum);
     m_histos.FillHisto(12+hoffset, event().muon(0).Phi(), weight, sysNum);
     m_histos.FillHisto(13+hoffset, event().muon(0).reliso05, weight, sysNum);

     m_histos.FillHisto(20+hoffset, event().muon(1).Pt(), weight, sysNum);    
     m_histos.FillHisto(21+hoffset, event().muon(1).Eta(), weight, sysNum);
     m_histos.FillHisto(22+hoffset, event().muon(1).Phi(), weight, sysNum);
     m_histos.FillHisto(23+hoffset, event().muon(1).reliso05, weight, sysNum);

     m_histos.FillHisto(50+hoffset, event().muonPair().M(), weight, sysNum);

     // Tau histos
     m_histos.FillHisto(100+hoffset, event().tau().Pt(), weight, sysNum);    
     m_histos.FillHisto(101+hoffset, event().tau().Eta(), weight, sysNum);
     m_histos.FillHisto(102+hoffset, event().tau().Phi(), weight, sysNum);
     m_histos.FillHisto(103+hoffset, event().tau().decayMode, weight, sysNum);
     m_histos.FillHisto(104+hoffset, event().tau().againstMuon3, weight, sysNum);
     m_histos.FillHisto(105+hoffset, event().tau().againstElectronMVA5, weight, sysNum);
     m_histos.FillHisto(106+hoffset, event().tau().byCombinedIsolationDeltaBetaCorrRaw3Hits, weight, sysNum);
     m_histos.FillHisto(107+hoffset, fabs(event().tauMatch().pdgId)*(event().tau().sign_flip!=0 ? event().tau().sign_flip : 1), weight, sysNum);

}

