/**
 *  @file  AnalysisMuTauSignal.cpp
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <jsauvan@cern.ch>
 *
 *  @date    02/08/2016
 *
 *  @internal
 *     Created :  02/08/2016
 * Last update :  02/08/2016 04:34:02 PM
 *          by :  J.-B. Sauvan
 *
 * =====================================================================================
 */







#include <iostream>
#include <fstream>

#include "TVector2.h"
#include "TGraphAsymmErrors.h"
#include "TH2F.h"

#include "AnHiMaCMG/StudyFakeRate/interface/AnalysisMuTauSignal.h"
#include "AnHiMaCMG/Core/interface/Utilities.h"




using namespace AnHiMa;
using namespace std;



/*****************************************************************/
AnalysisMuTauSignal::AnalysisMuTauSignal():IAnalysis()
/*****************************************************************/
{


}



/*****************************************************************/
AnalysisMuTauSignal::~AnalysisMuTauSignal()
/*****************************************************************/
{

}



/*****************************************************************/
bool AnalysisMuTauSignal::initialize(const string& parameterFile)
/*****************************************************************/
{
    bool status = IAnalysis::initialize(parameterFile);
    if(!status) return status;
    event().connectVariables(m_inputChain);

    // Read parameters

    return true;
}


/*****************************************************************/
void AnalysisMuTauSignal::execute()
/*****************************************************************/
{
    event().update();
    unsigned isoSelection = 1; // medium isolation
    for(unsigned applyMTcut=0; applyMTcut<=1; applyMTcut++ )
    {
        for(unsigned sign=0; sign<=1; sign++ )
        {
            if(event().passSelectionSignal(isoSelection, applyMTcut, sign+1))
            {
                for(const auto& sys : systematicList())
                {
                    fillHistos(applyMTcut+sign*2, sys);
                }
            }
        }
    }
}

/*****************************************************************/
void AnalysisMuTauSignal::fillHistos(unsigned selection, const std::string& sys)
/*****************************************************************/
{


    short sysNum = systematicNumber(sys);
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
    m_histos.FillHisto(51+hoffset, event().mvis(), weight, sysNum);
    m_histos.FillHisto(52+hoffset, event().mvis(), weight, sysNum);
    m_histos.FillHisto(53+hoffset, event().mt(), weight, sysNum);
    m_histos.FillHisto(54+hoffset, event().mvis(), event().mt(), weight, sysNum);

}


