/**
 *  @file  EventMuMu.cpp
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <sauvan@llr.in2p3.fr>
 *
 *  @date    19/11/2015
 *
 *  @internal
 *     Created :  19/11/2015
 * Last update :  19/11/2015 09:19:52
 *          by :  JB Sauvan
 *
 * =====================================================================================
 */




#include <iostream>
#include "AnHiMaCMG/H2TausCommon/interface/EventMuMu.h"
#include <TChain.h>
#include "TMath.h"


using namespace AnHiMa;
using namespace std;


/*****************************************************************/
EventMuMu::EventMuMu():IEvent(),
    m_muons(2)
/*****************************************************************/
{

}



/*****************************************************************/
EventMuMu::~EventMuMu()
/*****************************************************************/
{
}


/*****************************************************************/
void EventMuMu::connectVariables(TChain* inputChain)
/*****************************************************************/
{
    IEvent::connectVariables(inputChain);

    // Branches to read
    inputChain->SetBranchStatus("run"                                      , true);
    inputChain->SetBranchStatus("lumi"                                     , true);
    inputChain->SetBranchStatus("event"                                    , true);
    inputChain->SetBranchStatus("nPU"                                      , true);
    inputChain->SetBranchStatus("n_vertices"                               , true);
    inputChain->SetBranchStatus("rho"                                      , true);
    inputChain->SetBranchStatus("weight"                                   , true);
    inputChain->SetBranchStatus("weight_vertex"                            , true);
    inputChain->SetBranchStatus("mt"                                       , true);
    inputChain->SetBranchStatus("mvis"                                     , true);
    inputChain->SetBranchStatus("l1_pt"                                    , true);
    inputChain->SetBranchStatus("l1_eta"                                   , true);
    inputChain->SetBranchStatus("l1_phi"                                   , true);
    inputChain->SetBranchStatus("l1_charge"                                , true);
    inputChain->SetBranchStatus("l1_mass"                                  , true);
    inputChain->SetBranchStatus("l1_reliso05"                              , true);
    inputChain->SetBranchStatus("l1_reliso05_04"                           , true);
    inputChain->SetBranchStatus("l1_dxy"                                   , true);
    inputChain->SetBranchStatus("l1_dxy_error"                             , true);
    inputChain->SetBranchStatus("l1_dz"                                    , true);
    inputChain->SetBranchStatus("l1_dz_error"                              , true);
    inputChain->SetBranchStatus("l1_weight"                                , true);
    inputChain->SetBranchStatus("l1_weight_trigger"                        , true);
    inputChain->SetBranchStatus("l1_eff_trigger_data"                      , true);
    inputChain->SetBranchStatus("l1_eff_trigger_mc"                        , true);
    inputChain->SetBranchStatus("l1_weight_rec_eff"                        , true);
    inputChain->SetBranchStatus("l1_gen_match"                             , true);
    inputChain->SetBranchStatus("l1_muonid_loose"                          , true);
    inputChain->SetBranchStatus("l1_muonid_medium"                         , true);
    inputChain->SetBranchStatus("l1_muonid_tight"                          , true);
    inputChain->SetBranchStatus("l1_muonid_tightnovtx"                     , true);
    inputChain->SetBranchStatus("l1_muonid_highpt"                         , true);
    inputChain->SetBranchStatus("l1_dxy_innertrack"                        , true);
    inputChain->SetBranchStatus("l1_dz_innertrack"                         , true);
    inputChain->SetBranchStatus("l2_pt"                                    , true);
    inputChain->SetBranchStatus("l2_eta"                                   , true);
    inputChain->SetBranchStatus("l2_phi"                                   , true);
    inputChain->SetBranchStatus("l2_charge"                                , true);
    inputChain->SetBranchStatus("l2_mass"                                  , true);
    inputChain->SetBranchStatus("l2_reliso05"                              , true);
    inputChain->SetBranchStatus("l2_reliso05_04"                           , true);
    inputChain->SetBranchStatus("l2_dxy"                                   , true);
    inputChain->SetBranchStatus("l2_dxy_error"                             , true);
    inputChain->SetBranchStatus("l2_dz"                                    , true);
    inputChain->SetBranchStatus("l2_dz_error"                              , true);
    inputChain->SetBranchStatus("l2_weight"                                , true);
    inputChain->SetBranchStatus("l2_weight_trigger"                        , true);
    inputChain->SetBranchStatus("l2_eff_trigger_data"                      , true);
    inputChain->SetBranchStatus("l2_eff_trigger_mc"                        , true);
    inputChain->SetBranchStatus("l2_weight_rec_eff"                        , true);
    inputChain->SetBranchStatus("l2_gen_match"                             , true);
    inputChain->SetBranchStatus("l2_muonid_loose"                          , true);
    inputChain->SetBranchStatus("l2_muonid_medium"                         , true);
    inputChain->SetBranchStatus("l2_muonid_tight"                          , true);
    inputChain->SetBranchStatus("l2_muonid_tightnovtx"                     , true);
    inputChain->SetBranchStatus("l2_muonid_highpt"                         , true);
    inputChain->SetBranchStatus("l2_dxy_innertrack"                        , true);
    inputChain->SetBranchStatus("l2_dz_innertrack"                         , true);
    inputChain->SetBranchStatus("tau1_pt"                                       , true);
    inputChain->SetBranchStatus("tau1_eta"                                      , true);
    inputChain->SetBranchStatus("tau1_phi"                                      , true);
    inputChain->SetBranchStatus("tau1_charge"                                   , true);
    inputChain->SetBranchStatus("tau1_mass"                                     , true);
    inputChain->SetBranchStatus("tau1_reliso05"                                 , true);
    inputChain->SetBranchStatus("tau1_reliso05_04"                              , true);
    inputChain->SetBranchStatus("tau1_dxy"                                      , true);
    inputChain->SetBranchStatus("tau1_dxy_error"                                , true);
    inputChain->SetBranchStatus("tau1_dz"                                       , true);
    inputChain->SetBranchStatus("tau1_dz_error"                                 , true);
    inputChain->SetBranchStatus("tau1_weight"                                   , true);
    inputChain->SetBranchStatus("tau1_weight_trigger"                           , true);
    inputChain->SetBranchStatus("tau1_eff_trigger_data"                         , true);
    inputChain->SetBranchStatus("tau1_eff_trigger_mc"                           , true);
    inputChain->SetBranchStatus("tau1_weight_rec_eff"                           , true);
    inputChain->SetBranchStatus("tau1_decayMode"                                , true);
    inputChain->SetBranchStatus("tau1_zImpact"                                  , true);
    inputChain->SetBranchStatus("tau1_dz_selfvertex"                            , true);
    inputChain->SetBranchStatus("tau1_againstElectronMVA5"                      , true);
    inputChain->SetBranchStatus("tau1_againstElectronMVA5category"              , true);
    inputChain->SetBranchStatus("tau1_againstElectronMVA5raw"                   , true);
    inputChain->SetBranchStatus("tau1_againstMuon3"                             , true);
    inputChain->SetBranchStatus("tau1_byCombinedIsolationDeltaBetaCorrRaw3Hits" , true);
    inputChain->SetBranchStatus("tau1_byIsolationMVA3newDMwLTraw"               , true);
    inputChain->SetBranchStatus("tau1_byIsolationMVA3oldDMwLTraw"               , true);
    inputChain->SetBranchStatus("tau1_byCombinedIsolationDeltaBetaCorr3Hits"    , true);
    inputChain->SetBranchStatus("tau1_byIsolationMVA3newDMwLT"                  , true);
    inputChain->SetBranchStatus("tau1_byIsolationMVA3oldDMwLT"                  , true);
    inputChain->SetBranchStatus("tau1_chargedIsoPtSum"                          , true);
    inputChain->SetBranchStatus("tau1_decayModeFinding"                         , true);
    inputChain->SetBranchStatus("tau1_decayModeFindingNewDMs"                   , true);
    inputChain->SetBranchStatus("tau1_neutralIsoPtSum"                          , true);
    inputChain->SetBranchStatus("tau1_puCorrPtSum"                              , true);
    inputChain->SetBranchStatus("tau1_byPileupWeightedIsolation3Hits"           , true);
    inputChain->SetBranchStatus("tau1_byPileupWeightedIsolationRaw3Hits"        , true);
    inputChain->SetBranchStatus("tau1_neutralIsoPtSumWeight"                    , true);
    inputChain->SetBranchStatus("tau1_footprintCorrection"                      , true);
    inputChain->SetBranchStatus("tau1_photonPtSumOutsideSignalCone"             , true);
    inputChain->SetBranchStatus("tau1_jet_pt"                                   , true);
    inputChain->SetBranchStatus("tau1_jet_eta"                                  , true);
    inputChain->SetBranchStatus("tau1_jet_phi"                                  , true);
    inputChain->SetBranchStatus("tau1_jet_mass"                                 , true);
    inputChain->SetBranchStatus("tau1_jet_charge"                               , true);
    inputChain->SetBranchStatus("tau1_gen_match"                                , true);
    inputChain->SetBranchStatus("tau1_gen_pt"                                   , true);
    inputChain->SetBranchStatus("tau1_gen_eta"                                  , true);
    inputChain->SetBranchStatus("tau1_gen_phi"                                  , true);
    inputChain->SetBranchStatus("tau1_gen_charge"                               , true);
    inputChain->SetBranchStatus("tau1_gen_mass"                                 , true);
    inputChain->SetBranchStatus("tau1_gen_pdgId"                                , true);



    // Connect event branches
    inputChain->SetBranchAddress("run"            , &m_run);
    inputChain->SetBranchAddress("lumi"           , &m_lumi);
    inputChain->SetBranchAddress("event"          , &m_event);
    inputChain->SetBranchAddress("nPU"            , &m_npu);
    inputChain->SetBranchAddress("n_vertices"     , &m_n_vertices);
    inputChain->SetBranchAddress("rho"            , &m_rho);
    inputChain->SetBranchAddress("weight"         , &m_weight);
    inputChain->SetBranchAddress("weight_vertex"  , &m_weight_vertex);
    inputChain->SetBranchAddress("mt"             , &m_mt);
    inputChain->SetBranchAddress("mvis"           , &m_mvis);
    // connect first muon branch
    inputChain->SetBranchAddress("l1_pt"               , &m_muons[0].pt               );
    inputChain->SetBranchAddress("l1_eta"              , &m_muons[0].eta              );
    inputChain->SetBranchAddress("l1_phi"              , &m_muons[0].phi              );
    inputChain->SetBranchAddress("l1_charge"           , &m_muons[0].charge           );
    inputChain->SetBranchAddress("l1_mass"             , &m_muons[0].mass             );
    inputChain->SetBranchAddress("l1_reliso05"         , &m_muons[0].reliso05         );
    inputChain->SetBranchAddress("l1_reliso05_04"      , &m_muons[0].reliso05_04      );
    inputChain->SetBranchAddress("l1_dxy"              , &m_muons[0].dxy              );
    inputChain->SetBranchAddress("l1_dxy_error"        , &m_muons[0].dxy_error        );
    inputChain->SetBranchAddress("l1_dz"               , &m_muons[0].dz               );
    inputChain->SetBranchAddress("l1_dz_error"         , &m_muons[0].dz_error         );
    inputChain->SetBranchAddress("l1_weight"           , &m_muons[0].weight           );
    inputChain->SetBranchAddress("l1_weight_trigger"   , &m_muons[0].weight_trigger   );
    inputChain->SetBranchAddress("l1_eff_trigger_data" , &m_muons[0].eff_trigger_data );
    inputChain->SetBranchAddress("l1_eff_trigger_mc"   , &m_muons[0].eff_trigger_mc   );
    inputChain->SetBranchAddress("l1_weight_rec_eff"   , &m_muons[0].weight_rec_eff   );
    inputChain->SetBranchAddress("l1_gen_match"        , &m_muons[0].gen_match        );
    inputChain->SetBranchAddress("l1_muonid_loose"     , &m_muons[0].muonid_loose     );
    inputChain->SetBranchAddress("l1_muonid_medium"    , &m_muons[0].muonid_medium    );
    inputChain->SetBranchAddress("l1_muonid_tight"     , &m_muons[0].muonid_tight     );
    inputChain->SetBranchAddress("l1_muonid_tightnovtx", &m_muons[0].muonid_tightnovtx);
    inputChain->SetBranchAddress("l1_muonid_highpt"    , &m_muons[0].muonid_highpt    );
    inputChain->SetBranchAddress("l1_dxy_innertrack"   , &m_muons[0].dxy_innertrack   );
    inputChain->SetBranchAddress("l1_dz_innertrack"    , &m_muons[0].dz_innertrack    );
    // connect second muon branch
    inputChain->SetBranchAddress("l2_pt"               , &m_muons[1].pt               );
    inputChain->SetBranchAddress("l2_eta"              , &m_muons[1].eta              );
    inputChain->SetBranchAddress("l2_phi"              , &m_muons[1].phi              );
    inputChain->SetBranchAddress("l2_charge"           , &m_muons[1].charge           );
    inputChain->SetBranchAddress("l2_mass"             , &m_muons[1].mass             );
    inputChain->SetBranchAddress("l2_reliso05"         , &m_muons[1].reliso05         );
    inputChain->SetBranchAddress("l2_reliso05_04"      , &m_muons[1].reliso05_04      );
    inputChain->SetBranchAddress("l2_dxy"              , &m_muons[1].dxy              );
    inputChain->SetBranchAddress("l2_dxy_error"        , &m_muons[1].dxy_error        );
    inputChain->SetBranchAddress("l2_dz"               , &m_muons[1].dz               );
    inputChain->SetBranchAddress("l2_dz_error"         , &m_muons[1].dz_error         );
    inputChain->SetBranchAddress("l2_weight"           , &m_muons[1].weight           );
    inputChain->SetBranchAddress("l2_weight_trigger"   , &m_muons[1].weight_trigger   );
    inputChain->SetBranchAddress("l2_eff_trigger_data" , &m_muons[1].eff_trigger_data );
    inputChain->SetBranchAddress("l2_eff_trigger_mc"   , &m_muons[1].eff_trigger_mc   );
    inputChain->SetBranchAddress("l2_weight_rec_eff"   , &m_muons[1].weight_rec_eff   );
    inputChain->SetBranchAddress("l2_gen_match"        , &m_muons[1].gen_match        );
    inputChain->SetBranchAddress("l2_muonid_loose"     , &m_muons[1].muonid_loose     );
    inputChain->SetBranchAddress("l2_muonid_medium"    , &m_muons[1].muonid_medium    );
    inputChain->SetBranchAddress("l2_muonid_tight"     , &m_muons[1].muonid_tight     );
    inputChain->SetBranchAddress("l2_muonid_tightnovtx", &m_muons[1].muonid_tightnovtx);
    inputChain->SetBranchAddress("l2_muonid_highpt"    , &m_muons[1].muonid_highpt    );
    inputChain->SetBranchAddress("l2_dxy_innertrack"   , &m_muons[1].dxy_innertrack   );
    inputChain->SetBranchAddress("l2_dz_innertrack"    , &m_muons[1].dz_innertrack    );
    // connect tau branches
    inputChain->SetBranchAddress("tau1_pt"                                       , &m_tau.pt                                      );
    inputChain->SetBranchAddress("tau1_eta"                                      , &m_tau.eta                                     );
    inputChain->SetBranchAddress("tau1_phi"                                      , &m_tau.phi                                     );
    inputChain->SetBranchAddress("tau1_charge"                                   , &m_tau.charge                                  );
    inputChain->SetBranchAddress("tau1_mass"                                     , &m_tau.mass                                    );
    inputChain->SetBranchAddress("tau1_reliso05"                                 , &m_tau.reliso05                                );
    inputChain->SetBranchAddress("tau1_reliso05_04"                              , &m_tau.reliso05_04                             );
    inputChain->SetBranchAddress("tau1_dxy"                                      , &m_tau.dxy                                     );
    inputChain->SetBranchAddress("tau1_dxy_error"                                , &m_tau.dxy_error                               );
    inputChain->SetBranchAddress("tau1_dz"                                       , &m_tau.dz                                      );
    inputChain->SetBranchAddress("tau1_dz_error"                                 , &m_tau.dz_error                                );
    inputChain->SetBranchAddress("tau1_weight"                                   , &m_tau.weight                                  );
    inputChain->SetBranchAddress("tau1_weight_trigger"                           , &m_tau.weight_trigger                          );
    inputChain->SetBranchAddress("tau1_eff_trigger_data"                         , &m_tau.eff_trigger_data                        );
    inputChain->SetBranchAddress("tau1_eff_trigger_mc"                           , &m_tau.eff_trigger_mc                          );
    inputChain->SetBranchAddress("tau1_weight_rec_eff"                           , &m_tau.weight_rec_eff                          );
    inputChain->SetBranchAddress("tau1_decayMode"                                , &m_tau.decayMode                               );
    inputChain->SetBranchAddress("tau1_zImpact"                                  , &m_tau.zImpact                                 );
    inputChain->SetBranchAddress("tau1_dz_selfvertex"                            , &m_tau.dz_selfvertex                           );
    inputChain->SetBranchAddress("tau1_againstElectronMVA5"                      , &m_tau.againstElectronMVA5                     );
    inputChain->SetBranchAddress("tau1_againstElectronMVA5category"              , &m_tau.againstElectronMVA5category             );
    inputChain->SetBranchAddress("tau1_againstElectronMVA5raw"                   , &m_tau.againstElectronMVA5raw                  );
    inputChain->SetBranchAddress("tau1_againstMuon3"                             , &m_tau.againstMuon3                            );
    inputChain->SetBranchAddress("tau1_byCombinedIsolationDeltaBetaCorrRaw3Hits" , &m_tau.byCombinedIsolationDeltaBetaCorrRaw3Hits);
    inputChain->SetBranchAddress("tau1_byIsolationMVA3newDMwLTraw"               , &m_tau.byIsolationMVA3newDMwLTraw              );
    inputChain->SetBranchAddress("tau1_byIsolationMVA3oldDMwLTraw"               , &m_tau.byIsolationMVA3oldDMwLTraw              );
    inputChain->SetBranchAddress("tau1_byCombinedIsolationDeltaBetaCorr3Hits"    , &m_tau.byCombinedIsolationDeltaBetaCorr3Hits   );
    inputChain->SetBranchAddress("tau1_byIsolationMVA3newDMwLT"                  , &m_tau.byIsolationMVA3newDMwLT                 );
    inputChain->SetBranchAddress("tau1_byIsolationMVA3oldDMwLT"                  , &m_tau.byIsolationMVA3oldDMwLT                 );
    inputChain->SetBranchAddress("tau1_chargedIsoPtSum"                          , &m_tau.chargedIsoPtSum                         );
    inputChain->SetBranchAddress("tau1_decayModeFinding"                         , &m_tau.decayModeFinding                        );
    inputChain->SetBranchAddress("tau1_decayModeFindingNewDMs"                   , &m_tau.decayModeFindingNewDMs                  );
    inputChain->SetBranchAddress("tau1_neutralIsoPtSum"                          , &m_tau.neutralIsoPtSum                         );
    inputChain->SetBranchAddress("tau1_puCorrPtSum"                              , &m_tau.puCorrPtSum                             );
    inputChain->SetBranchAddress("tau1_byPileupWeightedIsolation3Hits"           , &m_tau.byPileupWeightedIsolation3Hits          );
    inputChain->SetBranchAddress("tau1_byPileupWeightedIsolationRaw3Hits"        , &m_tau.byPileupWeightedIsolationRaw3Hits       );
    inputChain->SetBranchAddress("tau1_neutralIsoPtSumWeight"                    , &m_tau.neutralIsoPtSumWeight                   );
    inputChain->SetBranchAddress("tau1_footprintCorrection"                      , &m_tau.footprintCorrection                     );
    inputChain->SetBranchAddress("tau1_photonPtSumOutsideSignalCone"             , &m_tau.photonPtSumOutsideSignalCone            );
    inputChain->SetBranchAddress("tau1_jet_pt"                                   , &m_tauJetMatch.pt                              );
    inputChain->SetBranchAddress("tau1_jet_eta"                                  , &m_tauJetMatch.eta                             );
    inputChain->SetBranchAddress("tau1_jet_phi"                                  , &m_tauJetMatch.phi                             );
    inputChain->SetBranchAddress("tau1_jet_charge"                               , &m_tauJetMatch.charge                          );
    inputChain->SetBranchAddress("tau1_jet_mass"                                 , &m_tauJetMatch.mass                            );
    inputChain->SetBranchAddress("tau1_gen_match"                                , &m_tau.gen_match                               );
    inputChain->SetBranchAddress("tau1_gen_pt"                                   , &m_tauMatch.pt                                 );
    inputChain->SetBranchAddress("tau1_gen_eta"                                  , &m_tauMatch.eta                                );
    inputChain->SetBranchAddress("tau1_gen_phi"                                  , &m_tauMatch.phi                                );
    inputChain->SetBranchAddress("tau1_gen_charge"                               , &m_tauMatch.charge                             );
    inputChain->SetBranchAddress("tau1_gen_mass"                                 , &m_tauMatch.mass                               );
    inputChain->SetBranchAddress("tau1_gen_pdgId"                                , &m_tauMatch.pdgId                              );



    registerCallback((void*)this, EventMuMu::callback);

}

/*****************************************************************/
bool EventMuMu::passSelection(int selection)
/*****************************************************************/
{
    bool pass = true;
    pass &= (tau().pt > 0.);
    switch(selection)
    {
        case 0: // Tau isolation raw < 1.5 GeV
            pass &= (tau().byCombinedIsolationDeltaBetaCorrRaw3Hits < 1.5);
            break;
        case 1: // Reversed isolation raw > 1.5 GeV
            pass &= (tau().byCombinedIsolationDeltaBetaCorrRaw3Hits > 1.5);
            break;
        case 2: // No isolation
            break;
        case 3: // Tau isolation medium
            pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits >= 2);
            break;
        case 4: // Reverse tau isolation medium
            pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits < 2);
            break;
        case 5: // Reversed medium isolation only reversing the raw isolation part
            pass &= (tau().byCombinedIsolationDeltaBetaCorrRaw3Hits > 1.5 && tau().photonPtSumOutsideSignalCone/tau().Pt()<0.1);
            break;
        default:
            break;
    };
    return pass;
}


/*****************************************************************/
void EventMuMu::update()
/*****************************************************************/
{
    IEvent::update();

}

/*****************************************************************/
void EventMuMu::callback(void* object)
/*****************************************************************/
{
    EventMuMu* myself = reinterpret_cast<EventMuMu*>(object);
    myself->buildEvent();
}


/*****************************************************************/
void EventMuMu::buildEvent()
/*****************************************************************/
{
    // Build muon pair
    m_muons[0].SetPtEtaPhiM(muon(0).pt, muon(0).eta, muon(0).phi, muon(0).mass);
    m_muons[1].SetPtEtaPhiM(muon(1).pt, muon(1).eta, muon(1).phi, muon(1).mass);
    m_muonPair.reset(new TParticlePair<Muon>(m_muons[0],m_muons[1]));
    // Build tau 4-vectors
    m_tau.SetPtEtaPhiM(tau().pt,tau().eta,tau().phi,tau().mass);
    m_tauMatch.SetPtEtaPhiM(tauMatch().pt,tauMatch().eta,tauMatch().phi,tauMatch().mass);
    if(tauJetMatch().pt>0.) m_tauJetMatch.SetPtEtaPhiM(tauJetMatch().pt,tauJetMatch().eta,tauJetMatch().phi,tauJetMatch().mass);
    else m_tauJetMatch.SetPtEtaPhiM(0,0,0,0);
    // Recompute parton charge from pdg ID 
    m_tauMatch.computeChargeFromPdgId();
    // Compute tau sign-flip
    m_tau.sign_flip = (m_tau.charge*m_tauMatch.charge<0 ? -1 : 1);
    if(tau().charge==0 || tauMatch().charge==0) m_tau.sign_flip = 0;
}



