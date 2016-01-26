
#include "AnHiMaCMG/H2TausCommon/interface/PUWeights.h"
#include "TFile.h"
#include "TH1F.h"
#include <iostream>

using namespace AnHiMa;



/*****************************************************************/
PUWeights::PUWeights()
/*****************************************************************/
{
}



/*****************************************************************/
PUWeights::~PUWeights()
/*****************************************************************/
{
}



/*****************************************************************/
bool PUWeights::initialize(const std::string& dataFileName, const std::string& mcFileName,
        const std::string& dataHistoName, const std::string& mcHistoName)
/*****************************************************************/
{
    TFile* dataFile = TFile::Open(dataFileName.c_str());
    TFile* mcFile   = TFile::Open(mcFileName.c_str());
    if(!dataFile)
    {
        std::cout<<"ERROR: Cannot open data PU file\n";
        return false;
    }
    if(!mcFile)
    {
        std::cout<<"ERROR: Cannot open MC PU file\n";
        return false;
    }
    TH1F* dataHisto = (TH1F*)dataFile->Get(dataHistoName.c_str());
    TH1F* mcHisto   = (TH1F*)mcFile->Get(mcHistoName.c_str());
    if(!dataHisto)
    {
        std::cout<<"ERROR: Cannot load data PU histo\n";
        return false;
    }
    if(!mcHisto)
    {
        std::cout<<"ERROR: Cannot load MC PU histo\n";
        return false;
    }

    dataHisto->Scale(1./dataHisto->Integral());
    mcHisto->Scale(1./mcHisto->Integral());

    m_weights.resize(std::min(mcHisto->GetNbinsX(), dataHisto->GetNbinsX()));
    for(int b=0; b<std::min(mcHisto->GetNbinsX(), dataHisto->GetNbinsX()); b++)
    {
        if(dataHisto->GetBinContent(b+1) == 0.) continue;
        else if(mcHisto->GetBinContent(b+1) == 0.)
        {
            std::cout<<"WARNING: data PU weight filled but MC zero:\n";
            std::cout<<"         nPU = "<< b << " w_data = " << dataHisto->GetBinContent(b+1) << "\n";
        }
        else
        {
            double ratio = dataHisto->GetBinContent(b+1)/mcHisto->GetBinContent(b+1);
            m_weights[b] = ratio*0.499278;//FIXME: factor to conserve sum of weights in Zmumu+X
        }
    }

    dataFile->Close();
    mcFile->Close();

    return true;
}
