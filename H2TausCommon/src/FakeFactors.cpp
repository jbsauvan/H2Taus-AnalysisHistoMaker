/**
 *  @file  FakeFactors.cpp
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <sauvan@llr.in2p3.fr>
 *
 *  @date    01/04/2016
 *
 *  @internal
 *     Created :  01/04/2016
 * Last update :  01/04/2016 03:10:22 PM
 *          by :  JB Sauvan
 *
 * =====================================================================================
 */


#include "AnHiMaCMG/Core/interface/Utilities.h"
#include "AnHiMaCMG/H2TausCommon/interface/FakeFactors.h"
#include "HTTutilities/Jet2TauFakes/interface/FakeFactor.h"
#include "TFile.h"



using namespace AnHiMa;




/*****************************************************************/
FakeFactors::FakeFactors()
/*****************************************************************/
{
}


/*****************************************************************/
FakeFactors::~FakeFactors()
/*****************************************************************/
{
    for(auto& name_ff : m_fakeFactors)
    {
        delete name_ff.second;
    }
}



/*****************************************************************/
bool  FakeFactors::addFakeFactor(const std::string& name,
        const std::string& fileName,
        const std::string& objectName)
/*****************************************************************/
{
    TFile* file = TFile::Open(fileName.c_str());
    if(!file)
    {
        std::cout<<"ERROR: Cannot open fake factor file "<<fileName<<"\n";
        return false;
    }
    FakeFactor* ff = (FakeFactor*)file->Get(objectName.c_str());
    if(!ff)
    {
        std::cout<<"ERROR: Cannot find fake factor "<<name<<"\n";
        return false;
    }
    m_fakeFactors.insert(std::make_pair(name, ff));
    return true;
}




/*****************************************************************/
double FakeFactors::retrieveFakeFactor(const std::string& name,
        const EventMuTau& event, 
        const std::string& systematic)
/*****************************************************************/
{
    const auto& name_ff = m_fakeFactors.find(name);
    if(name_ff==m_fakeFactors.end())
    {
        std::cout<<"WARNING: Cannot retrieve fake factor "<<name<<". Please define it in the config file\n";
        return 1.;
    }
    FakeFactor* ff = name_ff->second;
    const std::vector<std::string>& inputs = ff->inputs();
    std::vector<double> inputValues;
    for(const auto& input : inputs)
    {
        double value = 0.;
        if(input=="tau_pt")         value = event.tau().Pt();
        else if(input=="tau_decay") value = event.tau().decayMode;
        else if(input=="mvis")      value = event.mvis();
        else if(input=="mt")        value = event.mt();
        else if(input=="mu_iso")    value = event.muon().reliso05;
        else throw("ERROR: Input variables "+input+" has not been defined"); 
        inputValues.push_back(value);
    }
    double factor = ff->value(inputValues, systematic);
    return factor;
}


/*****************************************************************/
double FakeFactors::retrieveFakeFactor(const std::string& name,
        const EventMuMu& event, 
        const std::string& systematic)
/*****************************************************************/
{
    const auto& name_ff = m_fakeFactors.find(name);
    if(name_ff==m_fakeFactors.end())
    {
        std::cout<<"WARNING: Cannot retrieve fake factor "<<name<<". Please define it in the config file\n";
        return 1.;
    }
    FakeFactor* ff = name_ff->second;
    const std::vector<std::string>& inputs = ff->inputs();
    std::vector<double> inputValues;
    for(const auto& input : inputs)
    {
        double value = 0.;
        if(input=="tau_pt")         value = event.tau().Pt();
        else if(input=="tau_decay") value = event.tau().decayMode;
        else if(input=="mvis")      value = event.mvis();
        else if(input=="mt")        value = event.mt();
        else if(input=="mu_iso")    value = event.muon(0).reliso05; // dummy: take first muon
        else throw("ERROR: Input variables "+input+" has not been defined"); 
        inputValues.push_back(value);
    }
    double factor = ff->value(inputValues, systematic);
    return factor;
}
