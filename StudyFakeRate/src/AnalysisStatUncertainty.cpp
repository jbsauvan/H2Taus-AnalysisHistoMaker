/**
 *  @file  AnalysisStatUncertainty.cpp
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <sauvan@llr.in2p3.fr>
 *
 *  @date    01/05/2016
 *
 *  @internal
 *     Created :  01/05/2016
 * Last update :  01/05/2016 11:26:09 AM
 *          by :  JB Sauvan
 *
 * =====================================================================================
 */







#include <iostream>
#include <fstream>

#include "TVector2.h"
#include "TGraphAsymmErrors.h"
#include "TH2F.h"

#include "AnHiMaCMG/StudyFakeRate/interface/AnalysisStatUncertainty.h"
#include "AnHiMaCMG/Core/interface/Utilities.h"




using namespace AnHiMa;
using namespace std;



/*****************************************************************/
AnalysisStatUncertainty::AnalysisStatUncertainty():IAnalysis()
/*****************************************************************/
{


}



/*****************************************************************/
AnalysisStatUncertainty::~AnalysisStatUncertainty()
/*****************************************************************/
{
}



/*****************************************************************/
bool AnalysisStatUncertainty::initialize(const string& parameterFile)
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
void AnalysisStatUncertainty::execute()
/*****************************************************************/
{
    event().update();
    for(unsigned sel=0; sel<=1; sel++)
    {
        unsigned selectionId = sel;
        if(event().passSelection(selectionId))
        {
            for(const auto& sys : systematicList())
            {
                fillHistos(selectionId, sys);
            }
        }
    }
}

/*****************************************************************/
void AnalysisStatUncertainty::fillHistos(unsigned selection, const std::string& sys)
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
    //

    // Muon histos
    m_histos.FillHisto(10+hoffset, event().muon().Pt(), weight, sysNum);    
    m_histos.FillHisto(11+hoffset, event().muon().Eta(), weight, sysNum);
    m_histos.FillHisto(12+hoffset, event().muon().Phi(), weight, sysNum);
    m_histos.FillHisto(13+hoffset, event().muon().reliso05, weight, sysNum);


    // Tau histos
    m_histos.FillHisto(20+hoffset, event().tau().Pt(), weight, sysNum);    
    m_histos.FillHisto(21+hoffset, event().tau().Eta(), weight, sysNum);
    m_histos.FillHisto(23+hoffset, event().tau().decayMode, weight, sysNum);
    m_histos.FillHisto(27+hoffset, fabs(event().tauMatch().pdgId)*(event().tau().sign_flip!=0 ? event().tau().sign_flip : 1), weight, sysNum);

    // MuTau histos
    m_histos.FillHisto(50+hoffset, event().mvis(), weight, sysNum);
    m_histos.FillHisto(51+hoffset, event().mt(), weight, sysNum);

    // Histos depending on gen_match
    m_histos.Fill1BinHisto(100+hoffset, event().tau().gen_match, event().mvis(), weight, sysNum);

}

