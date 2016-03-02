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
#include "TFile.h"
#include "TGraphAsymmErrors.h"
#include "TF1.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFormula.h"
#include <sstream>



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
    for(auto& name_histo : m_fakeFactors)
    {
        name_histo.second.second->Delete();
    }
}



/*****************************************************************/
bool  FakeFactors::addFakeFactor(const std::string& name, const std::string& fileName, const std::string& objectName, const std::string& type)
/*****************************************************************/
{
    if(type=="Combined")
    {
        m_fakeFactorFormulas[name] = objectName; 
        m_fakeFactorNames.push_back(name);
    }
    else
    {
        TFile* file = TFile::Open(fileName.c_str());
        if(!file)
        {
            std::cout<<"ERROR: Cannot open fake-factor file "<<fileName<<"\n";
            return false;
        }
        TObject* object = file->Get(objectName.c_str());
        if(!object)
        {
            std::cout<<"ERROR: Cannot load fake-factor object "<<objectName<<" in file "<<fileName<<"\n";
            return false;
        }
        if(object->InheritsFrom("TH1")) dynamic_cast<TH1*>(object)->SetDirectory(0);
        file->Close();

        // Apply random fluctuations if requested
        bool fluctuate = (name.find("Fluctuate")!=std::string::npos ? true : false);
        if(fluctuate)
        {
            if(type=="1DGraph")
            {
                TGraphAsymmErrors* graph = dynamic_cast<TGraphAsymmErrors*>(object);
                //std::cout<<"Original graph = \n";
                for(int p=0; p<graph->GetN();p++)
                {
                    //std::cout<<graph->GetY()[p]<<" ";
                    double factor = graph->GetY()[p];
                    double errorUp   = graph->GetEYhigh()[p]; 
                    double errorDown = graph->GetEYlow()[p];
                    //double errorMean = (errorUp+errorDown)/2.;
                    //factor = std::max(0.,m_random.Gaus(factor, errorMean));
                    // Get random fluctuation using Gaussian with different positive and negative sigma
                    TF1 * f = new TF1("f",[&](double*x, double *p){ return std::max(0.,(x[0]>0 ? TMath::Gaus(x[0], factor, errorUp) : TMath::Gaus(x[0], factor, errorDown))); }, factor-5.*errorDown, factor+5.*errorUp, 0); 
                    factor = f->GetRandom(); //FIXME: TRandom is used. Better to use TRandom3
                    graph->SetPoint(p, graph->GetX()[p], factor);
                    f->Delete();
                }
                //std::cout<<"\n";
                //std::cout<<"Modified graph = \n";
                //for(int p=0; p<graph->GetN();p++)
                //{
                //std::cout<<graph->GetY()[p]<<" ";
                //}
                //std::cout<<"\n";
                object = static_cast<TObject*>(graph);
            }
            else if(type=="1DHisto")
            {
                TH1F* histo = dynamic_cast<TH1F*>(object);
                for(int bx=0; bx<=histo->GetNbinsX()+1;bx++)
                {
                    double factor = histo->GetBinContent(bx);
                    double error  = histo->GetBinError(bx); 
                    factor = std::max(0.,m_random.Gaus(factor, error));
                    histo->SetBinContent(bx, factor);
                }
                object = static_cast<TObject*>(histo);
            }
            else if(type=="2DHisto")
            {
                TH2F* histo = dynamic_cast<TH2F*>(object);
                for(int bx=0; bx<=histo->GetNbinsX()+1;bx++)
                {
                    for(int by=0; by<=histo->GetNbinsY()+1;by++)
                    {
                        double factor = histo->GetBinContent(bx,by);
                        double error  = histo->GetBinError(bx,by); 
                        factor = std::max(0.,m_random.Gaus(factor, error));
                        histo->SetBinContent(bx,by, factor);
                    }
                }
                object = static_cast<TObject*>(histo);
            }
        }
        // Use Up fake factors if requested
        //bool up = (name.find("Up")!=std::string::npos ? true : false);
        //if(up)
        //{
            //if(type=="1DGraph")
            //{
                //TGraphAsymmErrors* graph = dynamic_cast<TGraphAsymmErrors*>(object);
                //for(int p=0; p<graph->GetN();p++)
                //{
                    //double factor = graph->GetY()[p];
                    //double errorUp   = graph->GetEYhigh()[p]; 
                    //graph->SetPoint(p, graph->GetX()[p], factor+errorUp);
                //}
                //object = static_cast<TObject*>(graph);
            //}
            //else if(type=="1DHisto")
            //{
                //TH1F* histo = dynamic_cast<TH1F*>(object);
                //for(int bx=0; bx<=histo->GetNbinsX()+1;bx++)
                //{
                    //double factor = histo->GetBinContent(bx);
                    //double error  = histo->GetBinError(bx); 
                    //histo->SetBinContent(bx, factor+error);
                //}
                //object = static_cast<TObject*>(histo);
            //}
            //else if(type=="2DHisto")
            //{
                //TH2F* histo = dynamic_cast<TH2F*>(object);
                //for(int bx=0; bx<=histo->GetNbinsX()+1;bx++)
                //{
                    //for(int by=0; by<=histo->GetNbinsY()+1;by++)
                    //{
                        //double factor = histo->GetBinContent(bx,by);
                        //double error  = histo->GetBinError(bx,by); 
                        //histo->SetBinContent(bx,by, factor+error);
                    //}
                //}
                //object = static_cast<TObject*>(histo);
            //}
        //}
        //// Use Down fake factors if requested
        //bool down = (name.find("Down")!=std::string::npos ? true : false);
        //if(down)
        //{
            //if(type=="1DGraph")
            //{
                //TGraphAsymmErrors* graph = dynamic_cast<TGraphAsymmErrors*>(object);
                //for(int p=0; p<graph->GetN();p++)
                //{
                    //double factor = graph->GetY()[p];
                    //double errorDown = graph->GetEYlow()[p];
                    //graph->SetPoint(p, graph->GetX()[p], std::max(0.,factor-errorDown));
                //}
                //object = static_cast<TObject*>(graph);
            //}
            //else if(type=="1DHisto")
            //{
                //TH1F* histo = dynamic_cast<TH1F*>(object);
                //for(int bx=0; bx<=histo->GetNbinsX()+1;bx++)
                //{
                    //double factor = histo->GetBinContent(bx);
                    //double error  = histo->GetBinError(bx); 
                    //histo->SetBinContent(bx,std::max(0., factor-error));
                //}
                //object = static_cast<TObject*>(histo);
            //}
            //else if(type=="2DHisto")
            //{
                //TH2F* histo = dynamic_cast<TH2F*>(object);
                //for(int bx=0; bx<=histo->GetNbinsX()+1;bx++)
                //{
                    //for(int by=0; by<=histo->GetNbinsY()+1;by++)
                    //{
                        //double factor = histo->GetBinContent(bx,by);
                        //double error  = histo->GetBinError(bx,by); 
                        //histo->SetBinContent(bx,by,std::max(0., factor-error));
                    //}
                //}
                //object = static_cast<TObject*>(histo);
            //}
        //}

        m_fakeFactors[name] = std::make_pair(type, object);
        m_fakeFactorNames.push_back(name);
    }

    return true;
}


/*****************************************************************/
void FakeFactors::createCombinedFakeFactorFormulas()
/*****************************************************************/
{
    for(const auto& name_formula : m_fakeFactorFormulas)
    {
        std::string formula = name_formula.second;
        //std::cerr<<name_formula.first<<" ("<<formula<<")\n";
        // find fake factors included in the formula
        for(const auto& name : m_fakeFactorNames)
        {
            std::string tag = "["+name+"]";
            if(formula.find(tag)!=std::string::npos) 
            {
                m_formulaVariables[name_formula.first].push_back(name);
                std::stringstream var;
                var << "x[" << m_formulaVariables[name_formula.first].size()-1 << "]";
                findAndReplace(formula, tag, var.str());
            }
        }
        //std::cerr<<" --> "<<formula<<"\n";
        TFormula* form = new TFormula(name_formula.first.c_str(), formula.c_str());
        m_fakeFactors[name_formula.first] = std::make_pair(std::string("Combined"), static_cast<TObject*>(form));
    }
}



/*****************************************************************/
double FakeFactors::retrieveFakeFactor(const std::string& name, const EventMuTau& event, bool fluctuate)
/*****************************************************************/
{
    const auto& name_object = m_fakeFactors.find(name);
    if(name_object==m_fakeFactors.end())
    {
        std::cout<<"WARNING: Cannot retrieve fake factor "<<name<<". Please define it in the config file\n";
        return 1.;
    }
    const auto& type_object = name_object->second;
    TObject* object = type_object.second;
    const std::string& type = type_object.first;
    double factor = 1.;
    if(type=="Combined")
    {
        //std::cerr<<"("<<name;
        //std::cerr<<"[";
        std::vector<double> vars;
        for(const auto& factor : m_formulaVariables[name])
        {
            //std::cerr<<factor<<"=";
            double var = retrieveFakeFactor(factor, event, fluctuate);
            vars.push_back(var);
            //std::cerr<<var<<", ";
        }
        //std::cerr<<"]=";
        TFormula* formula = dynamic_cast<TFormula*>(object);
        //std::cerr<<formula->EvalPar(&vars[0])<<")\n";
        return formula->EvalPar(&vars[0]);

    }
    else
    {
        std::vector<double> values;
        // CAREFUL: it has to be checked that it doesn't go in the wrong place because
        // of strings included in other strings. That's why 2D fake factors come first.
        // 2D fake factor
        if(name.find("VsPtEta")!=std::string::npos)
        {
            values.push_back(event.tau().Pt());
            values.push_back(fabs(event.tau().Eta())); // Careful: This is absolute value of eta
        }
        else if(name.find("VsPtDecay")!=std::string::npos)
        {
            values.push_back(event.tau().Pt());
            values.push_back(event.tau().decayMode);
        }
        else if(name.find("VsJetPtDecay")!=std::string::npos)
        {
            values.push_back(event.tauJetMatch().Pt());
            values.push_back(event.tau().decayMode);
        }
        else if(name.find("VsJetPtPt")!=std::string::npos)
        {
            values.push_back(event.tauJetMatch().Pt());
            values.push_back(event.tau().Pt());
        }
        else if(name.find("VsPtPdgId")!=std::string::npos)
        {
            values.push_back(event.tau().Pt());
            double valueId = fabs(event.tauMatch().pdgId);
            if((valueId>=6 && valueId<=20) || valueId>=22 || valueId==0) valueId = 2.; // FIXME: find a better way to discard values not used to determine the fake rates
            values.push_back( valueId * (event.tau().sign_flip!=0 ? event.tau().sign_flip : 1));
        }
        else if(name.find("VsMVisMT")!=std::string::npos)
        {
            values.push_back(event.mvis());
            values.push_back(event.mt());
        }
        // 1D fake factor
        else if(name.find("Inclusive")!=std::string::npos)
        {
            values.push_back(1.);
        }
        else if(name.find("VsPt")!=std::string::npos)
        {
            values.push_back(event.tau().Pt());
        }
        else if(name.find("VsEta")!=std::string::npos)
        {
            values.push_back(event.tau().Eta());
        }
        else if(name.find("VsNVtx")!=std::string::npos)
        {
            values.push_back(event.n_vertices());
        }
        else if(name.find("VsDecay")!=std::string::npos)
        {
            values.push_back(event.tau().decayMode);
        }
        else if(name.find("VsPdgId")!=std::string::npos)
        {
            double value = fabs(event.tauMatch().pdgId);
            if((value>=6 && value<=20) || value>=22 || value==0) value = 2.; // FIXME: find a better way to discard values not used to determine the fake rates
            values.push_back( value * (event.tau().sign_flip!=0 ? event.tau().sign_flip : 1));
        }
        else if(name.find("VsJetPt")!=std::string::npos)
        {
            values.push_back(event.tauJetMatch().Pt());
        }
        else if(name.find("VsMVis")!=std::string::npos)
        {
            values.push_back(event.mvis());
        }
        else if(name.find("VsMT")!=std::string::npos)
        {
            values.push_back(event.mt());
        }
        else
        {
            throw("Cannot find input variables for fake factor "+name);
        }

        // Retrieve fake factor depending on type of object
        if(type=="1DGraph")
        {
            TGraphAsymmErrors* graph = dynamic_cast<TGraphAsymmErrors*>(object);
            // Don't extrapolate. Suppose lowest point is point 0 and highest point is the last one
            if(values[0]>graph->GetX()[graph->GetN()-1]) values[0]=graph->GetX()[graph->GetN()-1];
            else if(values[0]<graph->GetX()[0]) values[0]=graph->GetX()[0];
            factor = graph->Eval(values[0]);
            // Apply randon fluctuations if requested
            if(fluctuate)
            {
                // Find closest point to retrieve relative error here
                int closest = -1;
                double dxmin = 9999.;
                for(int p=0;p<graph->GetN();p++)
                {
                    if(fabs(graph->GetX()[p]-values[0])<dxmin)
                    {
                        dxmin = fabs(graph->GetX()[p]-values[0]);
                        closest = p;
                    }
                }
                //std::cout<<"Closest point of "<<values[0]<<" is "<<graph->GetX()[closest]<<"\n";
                // Use same relative errors as the closest point
                double errorUp   = graph->GetEYhigh()[closest]*factor/graph->GetY()[closest]; 
                double errorDown = graph->GetEYlow()[closest]*factor/graph->GetY()[closest];
                double errorMean = (errorUp+errorDown)/2.;
                //std::cout<<factor<<" ("<<errorUp<<" "<<errorDown<<" "<<errorMean<<")";
                factor = std::max(0.,m_random.Gaus(factor, errorMean));
                // Get random fluctuation using Gaussian with different positive and negative sigma
                //TF1 * f = new TF1("f",[&](double*x, double *p){ return fabs(x[0]>0 ? TMath::Gaus(x[0], factor, errorUp) : TMath::Gaus(x[0], factor, errorDown)); }, factor-3.*errorDown, factor+3.*errorUp, 0); 
                //factor = f->GetRandom(); //FIXME: TRandom is used. Better to use TRandom3
                //std::cout<<" "<<factor<<"\n";
                //f->Delete();
            }
        }
        else if(type=="1DHisto")
        {
            TH1F* histo = dynamic_cast<TH1F*>(object);
            int bx = histo->GetXaxis()->FindBin(values[0]);
            factor = histo->GetBinContent(bx);
        }
        else if(type=="2DHisto")
        {
            TH2F* histo = dynamic_cast<TH2F*>(object);
            int bx = histo->GetXaxis()->FindBin(values[0]);
            int by = histo->GetYaxis()->FindBin(values[1]);
            factor = histo->GetBinContent(bx,by);
            // TODO: also add random fluctuations feature here (would need to store asymmetric errors
            // somewhere)
        }
        else
        {
            throw("Unknown type of fake factor\n");
        }
        // Apply high-mT -> low-mT correction factor
        // NOW DONE IN CONFIG
        //if(name.find("HighMT")!=std::string::npos)
        //{
            //factor *= 0.685578; // extrapolation factor derived from Z+jet MC, with pT(muon2)>5GeV
        //}
    }


    return factor;
}


/*****************************************************************/
double FakeFactors::retrieveFakeFactor(const std::string& name, const EventMuMu& event, bool fluctuate)
/*****************************************************************/
{
    const auto& name_object = m_fakeFactors.find(name);
    if(name_object==m_fakeFactors.end())
    {
        std::cout<<"WARNING: Cannot retrieve fake factor "<<name<<". Please define it in the config file\n";
        return 1.;
    }
    const auto& type_object = name_object->second;
    TObject* object = type_object.second;
    const std::string& type = type_object.first;
    double factor = 1.;
    if(type=="Combined")
    {
        //std::cerr<<"("<<name;
        //std::cerr<<"[";
        std::vector<double> vars;
        for(const auto& factor : m_formulaVariables[name])
        {
            //std::cerr<<factor<<"=";
            double var = retrieveFakeFactor(factor, event, fluctuate);
            vars.push_back(var);
            //std::cerr<<var<<", ";
        }
        //std::cerr<<"]=";
        TFormula* formula = dynamic_cast<TFormula*>(object);
        //std::cerr<<formula->EvalPar(&vars[0])<<")\n";
        return formula->EvalPar(&vars[0]);

    }
    else
    {
        std::vector<double> values;
        // CAREFUL: it has to be checked that it doesn't go in the wrong place because
        // of strings included in other strings. That's why 2D fake factors come first.
        // 2D fake factor
        if(name.find("VsPtEta")!=std::string::npos)
        {
            values.push_back(event.tau().Pt());
            values.push_back(fabs(event.tau().Eta())); // Careful: This is absolute value of eta
        }
        else if(name.find("VsPtDecay")!=std::string::npos)
        {
            values.push_back(event.tau().Pt());
            values.push_back(event.tau().decayMode);
        }
        else if(name.find("VsJetPtDecay")!=std::string::npos)
        {
            values.push_back(event.tauJetMatch().Pt());
            values.push_back(event.tau().decayMode);
        }
        else if(name.find("VsJetPtPt")!=std::string::npos)
        {
            values.push_back(event.tauJetMatch().Pt());
            values.push_back(event.tau().Pt());
        }
        else if(name.find("VsPtPdgId")!=std::string::npos)
        {
            values.push_back(event.tau().Pt());
            double valueId = fabs(event.tauMatch().pdgId);
            if((valueId>=6 && valueId<=20) || valueId>=22 || valueId==0) valueId = 2.; // FIXME: find a better way to discard values not used to determine the fake rates
            values.push_back( valueId * (event.tau().sign_flip!=0 ? event.tau().sign_flip : 1));
        }
        else if(name.find("VsMVisMT")!=std::string::npos)
        {
            values.push_back(event.mvis());
            values.push_back(event.mt());
        }
        // 1D fake factor
        else if(name.find("Inclusive")!=std::string::npos)
        {
            values.push_back(1.);
        }
        else if(name.find("VsPt")!=std::string::npos)
        {
            values.push_back(event.tau().Pt());
        }
        else if(name.find("VsEta")!=std::string::npos)
        {
            values.push_back(event.tau().Eta());
        }
        else if(name.find("VsNVtx")!=std::string::npos)
        {
            values.push_back(event.n_vertices());
        }
        else if(name.find("VsDecay")!=std::string::npos)
        {
            values.push_back(event.tau().decayMode);
        }
        else if(name.find("VsPdgId")!=std::string::npos)
        {
            double value = fabs(event.tauMatch().pdgId);
            if((value>=6 && value<=20) || value>=22 || value==0) value = 2.; // FIXME: find a better way to discard values not used to determine the fake rates
            values.push_back( value * (event.tau().sign_flip!=0 ? event.tau().sign_flip : 1));
        }
        else if(name.find("VsJetPt")!=std::string::npos)
        {
            values.push_back(event.tauJetMatch().Pt());
        }
        else if(name.find("VsMVis")!=std::string::npos)
        {
            values.push_back(event.mvis());
        }
        else if(name.find("VsMT")!=std::string::npos)
        {
            values.push_back(event.mt());
        }
        else
        {
            throw("Cannot find input variables for fake factor "+name);
        }

        // Retrieve fake factor depending on type of object
        if(type=="1DGraph")
        {
            TGraphAsymmErrors* graph = dynamic_cast<TGraphAsymmErrors*>(object);
            // Don't extrapolate. Suppose lowest point is point 0 and highest point is the last one
            if(values[0]>graph->GetX()[graph->GetN()-1]) values[0]=graph->GetX()[graph->GetN()-1];
            else if(values[0]<graph->GetX()[0]) values[0]=graph->GetX()[0];
            factor = graph->Eval(values[0]);
            // Apply randon fluctuations if requested
            if(fluctuate)
            {
                // Find closest point to retrieve relative error here
                int closest = -1;
                double dxmin = 9999.;
                for(int p=0;p<graph->GetN();p++)
                {
                    if(fabs(graph->GetX()[p]-values[0])<dxmin)
                    {
                        dxmin = fabs(graph->GetX()[p]-values[0]);
                        closest = p;
                    }
                }
                //std::cout<<"Closest point of "<<values[0]<<" is "<<graph->GetX()[closest]<<"\n";
                // Use same relative errors as the closest point
                double errorUp   = graph->GetEYhigh()[closest]*factor/graph->GetY()[closest]; 
                double errorDown = graph->GetEYlow()[closest]*factor/graph->GetY()[closest];
                double errorMean = (errorUp+errorDown)/2.;
                //std::cout<<factor<<" ("<<errorUp<<" "<<errorDown<<" "<<errorMean<<")";
                factor = std::max(0.,m_random.Gaus(factor, errorMean));
                // Get random fluctuation using Gaussian with different positive and negative sigma
                //TF1 * f = new TF1("f",[&](double*x, double *p){ return fabs(x[0]>0 ? TMath::Gaus(x[0], factor, errorUp) : TMath::Gaus(x[0], factor, errorDown)); }, factor-3.*errorDown, factor+3.*errorUp, 0); 
                //factor = f->GetRandom(); //FIXME: TRandom is used. Better to use TRandom3
                //std::cout<<" "<<factor<<"\n";
                //f->Delete();
            }
        }
        else if(type=="1DHisto")
        {
            TH1F* histo = dynamic_cast<TH1F*>(object);
            int bx = histo->GetXaxis()->FindBin(values[0]);
            factor = histo->GetBinContent(bx);
        }
        else if(type=="2DHisto")
        {
            TH2F* histo = dynamic_cast<TH2F*>(object);
            int bx = histo->GetXaxis()->FindBin(values[0]);
            int by = histo->GetYaxis()->FindBin(values[1]);
            factor = histo->GetBinContent(bx,by);
            // TODO: also add random fluctuations feature here (would need to store asymmetric errors
            // somewhere)
        }
        else
        {
            throw("Unknown type of fake factor\n");
        }
        // Apply high-mT -> low-mT correction factor
        // NOW DONE IN CONFIG
        //if(name.find("HighMT")!=std::string::npos)
        //{
            //factor *= 0.685578; // extrapolation factor derived from Z+jet MC, with pT(muon2)>5GeV
        //}
    }


    return factor;
}
