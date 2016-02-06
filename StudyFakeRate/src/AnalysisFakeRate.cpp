





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
    std::string puWeightsDataFileName  = m_reader.params().GetValue("PUWeightsDataFile", "");
    std::string puWeightsMCFileName    = m_reader.params().GetValue("PUWeightsMCFile", "");
    std::string puWeightsDataHistoName = m_reader.params().GetValue("PUWeightsDataHisto", "pileup");
    std::string puWeightsMCHistoName   = m_reader.params().GetValue("PUWeightsMCHisto", "pu_mc");
    // 
    event().setIsData(m_reader.params().GetValue("IsData", false));

    std::cout<<"IsData             = " << event().isData() << "\n";
    std::cout<<"PUWeightsDataFile  = " << puWeightsDataFileName << "\n";
    std::cout<<"PUWeightsMCFile    = " << puWeightsMCFileName << "\n";
    std::cout<<"PUWeightsDataHisto = " << puWeightsDataHistoName << "\n";
    std::cout<<"PUWeightsMCHisto   = " << puWeightsMCHistoName << "\n";

    bool ok = m_puWeights.initialize(puWeightsDataFileName, puWeightsMCFileName, puWeightsDataHistoName, puWeightsMCHistoName);
    if(!ok) return false;

    return true;
}


/*****************************************************************/
void AnalysisFakeRate::execute()
/*****************************************************************/
{
    event().update();
    for(unsigned sel=0; sel<=5; sel++)
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
void AnalysisFakeRate::fillHistos(unsigned selection, const std::string& sys)
/*****************************************************************/
{
    short sysNum = systematicNumber(sys);
    float weight = event().weight();
    //float puWeight = 1.;
    //if(sys!="NoPUReweight" && !event().isData()) // apply PU reweighting
    //{
        //puWeight = m_puWeights.weight(event().npu());
        //weight *= puWeight;
        ////std::cout<<"NPU = "<<event().npu()<<" Weight = " << puWeight<<"\n";
    //}
    int hoffset  = 1000*selection;



    // Event histos
    m_histos.FillHisto(0+hoffset, 1., weight, sysNum); // Number of events
    m_histos.FillHisto(1+hoffset, event().n_vertices(), weight, sysNum); 
    m_histos.FillHisto(2+hoffset, event().rho(), weight, sysNum); 
    m_histos.FillHisto(3+hoffset, event().npu(), weight, sysNum); 
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
     m_histos.FillHisto(51+hoffset, event().muonPair().M(), weight, sysNum);
     m_histos.FillHisto(52+hoffset, event().muonPair().Pt(), weight, sysNum);

     // Tau histos
     m_histos.FillHisto(99+hoffset,  event().tau().Pt(), weight, sysNum);
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

