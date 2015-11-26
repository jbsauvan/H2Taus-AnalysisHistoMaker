/**
 *  @file  EventMuTau.cpp
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <sauvan@llr.in2p3.fr>
 *
 *  @date    20/11/2015
 *
 *  @internal
 *     Created :  20/11/2015
 * Last update :  20/11/2015 13:57:13
 *          by :  JB Sauvan
 *
 * =====================================================================================
 */






#include <iostream>
#include "AnHiMaCMG/H2TausCommon/interface/EventMuTau.h"
#include <TChain.h>
#include "TMath.h"


using namespace AnHiMa;
using namespace std;


/*****************************************************************/
EventMuTau::EventMuTau():IEvent()
/*****************************************************************/
{

}



/*****************************************************************/
EventMuTau::~EventMuTau()
/*****************************************************************/
{
}


/*****************************************************************/
void EventMuTau::connectVariables(TChain* inputChain)
/*****************************************************************/
{
    IEvent::connectVariables(inputChain);

    // Branches to read
    inputChain->SetBranchStatus("run"                                      , true);
    inputChain->SetBranchStatus("lumi"                                     , true);
    inputChain->SetBranchStatus("event"                                    , true);
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
    inputChain->SetBranchStatus("l1_muonid_loose"                          , true);
    inputChain->SetBranchStatus("l1_muonid_medium"                         , true);
    inputChain->SetBranchStatus("l1_muonid_tight"                          , true);
    inputChain->SetBranchStatus("l1_muonid_tightnovtx"                     , true);
    inputChain->SetBranchStatus("l1_muonid_highpt"                         , true);
    inputChain->SetBranchStatus("l1_dxy_innertrack"                        , true);
    inputChain->SetBranchStatus("l1_dz_innertrack"                         , true);
    inputChain->SetBranchStatus("l1_gen_match"                             , true);
    inputChain->SetBranchStatus("l2_pt"                                       , true);
    inputChain->SetBranchStatus("l2_eta"                                      , true);
    inputChain->SetBranchStatus("l2_phi"                                      , true);
    inputChain->SetBranchStatus("l2_charge"                                   , true);
    inputChain->SetBranchStatus("l2_mass"                                     , true);
    inputChain->SetBranchStatus("l2_reliso05"                                 , true);
    inputChain->SetBranchStatus("l2_reliso05_04"                              , true);
    inputChain->SetBranchStatus("l2_dxy"                                      , true);
    inputChain->SetBranchStatus("l2_dxy_error"                                , true);
    inputChain->SetBranchStatus("l2_dz"                                       , true);
    inputChain->SetBranchStatus("l2_dz_error"                                 , true);
    inputChain->SetBranchStatus("l2_weight"                                   , true);
    inputChain->SetBranchStatus("l2_weight_trigger"                           , true);
    inputChain->SetBranchStatus("l2_eff_trigger_data"                         , true);
    inputChain->SetBranchStatus("l2_eff_trigger_mc"                           , true);
    inputChain->SetBranchStatus("l2_weight_rec_eff"                           , true);
    inputChain->SetBranchStatus("l2_decayMode"                                , true);
    inputChain->SetBranchStatus("l2_zImpact"                                  , true);
    inputChain->SetBranchStatus("l2_dz_selfvertex"                            , true);
    inputChain->SetBranchStatus("l2_againstElectronMVA5"                      , true);
    inputChain->SetBranchStatus("l2_againstElectronMVA5category"              , true);
    inputChain->SetBranchStatus("l2_againstElectronMVA5raw"                   , true);
    inputChain->SetBranchStatus("l2_againstMuon3"                             , true);
    inputChain->SetBranchStatus("l2_byCombinedIsolationDeltaBetaCorrRaw3Hits" , true);
    inputChain->SetBranchStatus("l2_byIsolationMVA3newDMwLTraw"               , true);
    inputChain->SetBranchStatus("l2_byIsolationMVA3oldDMwLTraw"               , true);
    inputChain->SetBranchStatus("l2_byCombinedIsolationDeltaBetaCorr3Hits"    , true);
    inputChain->SetBranchStatus("l2_byIsolationMVA3newDMwLT"                  , true);
    inputChain->SetBranchStatus("l2_byIsolationMVA3oldDMwLT"                  , true);
    inputChain->SetBranchStatus("l2_chargedIsoPtSum"                          , true);
    inputChain->SetBranchStatus("l2_decayModeFinding"                         , true);
    inputChain->SetBranchStatus("l2_decayModeFindingNewDMs"                   , true);
    inputChain->SetBranchStatus("l2_neutralIsoPtSum"                          , true);
    inputChain->SetBranchStatus("l2_puCorrPtSum"                              , true);
    inputChain->SetBranchStatus("l2_gen_match"                                , true);
    inputChain->SetBranchStatus("l2_gen_pt"                                   , true);
    inputChain->SetBranchStatus("l2_gen_eta"                                  , true);
    inputChain->SetBranchStatus("l2_gen_phi"                                  , true);
    inputChain->SetBranchStatus("l2_gen_charge"                               , true);
    inputChain->SetBranchStatus("l2_gen_mass"                                 , true);
    inputChain->SetBranchStatus("l2_gen_pdgId"                                , true);
    //inputChain->SetBranchStatus("l2_byPileupWeightedIsolation3Hits"           , true);
    //inputChain->SetBranchStatus("l2_byPileupWeightedIsolationRaw3Hits"        , true);
    //inputChain->SetBranchStatus("l2_neutralIsoPtSumWeight"                    , true);
    //inputChain->SetBranchStatus("l2_footprintCorrection"                      , true);
    //inputChain->SetBranchStatus("l2_photonPtSumOutsideSignalCone"             , true);



    // Connect event branches
    inputChain->SetBranchAddress("run"            , &m_run);
    inputChain->SetBranchAddress("lumi"           , &m_lumi);
    inputChain->SetBranchAddress("event"          , &m_event);
    inputChain->SetBranchAddress("n_vertices"     , &m_n_vertices);
    inputChain->SetBranchAddress("rho"            , &m_rho);
    inputChain->SetBranchAddress("weight"         , &m_weight);
    inputChain->SetBranchAddress("weight_vertex"  , &m_weight_vertex);
    inputChain->SetBranchAddress("mt"             , &m_mt);
    inputChain->SetBranchAddress("mvis"           , &m_mvis);
    // connect first muon branch
    inputChain->SetBranchAddress("l1_pt"               , &m_muon.pt               );
    inputChain->SetBranchAddress("l1_eta"              , &m_muon.eta              );
    inputChain->SetBranchAddress("l1_phi"              , &m_muon.phi              );
    inputChain->SetBranchAddress("l1_charge"           , &m_muon.charge           );
    inputChain->SetBranchAddress("l1_mass"             , &m_muon.mass             );
    inputChain->SetBranchAddress("l1_reliso05"         , &m_muon.reliso05         );
    inputChain->SetBranchAddress("l1_reliso05_04"      , &m_muon.reliso05_04      );
    inputChain->SetBranchAddress("l1_dxy"              , &m_muon.dxy              );
    inputChain->SetBranchAddress("l1_dxy_error"        , &m_muon.dxy_error        );
    inputChain->SetBranchAddress("l1_dz"               , &m_muon.dz               );
    inputChain->SetBranchAddress("l1_dz_error"         , &m_muon.dz_error         );
    inputChain->SetBranchAddress("l1_weight"           , &m_muon.weight           );
    inputChain->SetBranchAddress("l1_weight_trigger"   , &m_muon.weight_trigger   );
    inputChain->SetBranchAddress("l1_eff_trigger_data" , &m_muon.eff_trigger_data );
    inputChain->SetBranchAddress("l1_eff_trigger_mc"   , &m_muon.eff_trigger_mc   );
    inputChain->SetBranchAddress("l1_weight_rec_eff"   , &m_muon.weight_rec_eff   );
    inputChain->SetBranchAddress("l1_muonid_loose"     , &m_muon.muonid_loose     );
    inputChain->SetBranchAddress("l1_muonid_medium"    , &m_muon.muonid_medium    );
    inputChain->SetBranchAddress("l1_muonid_tight"     , &m_muon.muonid_tight     );
    inputChain->SetBranchAddress("l1_muonid_tightnovtx", &m_muon.muonid_tightnovtx);
    inputChain->SetBranchAddress("l1_muonid_highpt"    , &m_muon.muonid_highpt    );
    inputChain->SetBranchAddress("l1_dxy_innertrack"   , &m_muon.dxy_innertrack   );
    inputChain->SetBranchAddress("l1_dz_innertrack"    , &m_muon.dz_innertrack    );
    inputChain->SetBranchAddress("l1_gen_match"        , &m_muon.gen_match        );
    // connect tau branches
    inputChain->SetBranchAddress("l2_pt"                                       , &m_tau.pt                                      );
    inputChain->SetBranchAddress("l2_eta"                                      , &m_tau.eta                                     );
    inputChain->SetBranchAddress("l2_phi"                                      , &m_tau.phi                                     );
    inputChain->SetBranchAddress("l2_charge"                                   , &m_tau.charge                                  );
    inputChain->SetBranchAddress("l2_mass"                                     , &m_tau.mass                                    );
    inputChain->SetBranchAddress("l2_reliso05"                                 , &m_tau.reliso05                                );
    inputChain->SetBranchAddress("l2_reliso05_04"                              , &m_tau.reliso05_04                             );
    inputChain->SetBranchAddress("l2_dxy"                                      , &m_tau.dxy                                     );
    inputChain->SetBranchAddress("l2_dxy_error"                                , &m_tau.dxy_error                               );
    inputChain->SetBranchAddress("l2_dz"                                       , &m_tau.dz                                      );
    inputChain->SetBranchAddress("l2_dz_error"                                 , &m_tau.dz_error                                );
    inputChain->SetBranchAddress("l2_weight"                                   , &m_tau.weight                                  );
    inputChain->SetBranchAddress("l2_weight_trigger"                           , &m_tau.weight_trigger                          );
    inputChain->SetBranchAddress("l2_eff_trigger_data"                         , &m_tau.eff_trigger_data                        );
    inputChain->SetBranchAddress("l2_eff_trigger_mc"                           , &m_tau.eff_trigger_mc                          );
    inputChain->SetBranchAddress("l2_weight_rec_eff"                           , &m_tau.weight_rec_eff                          );
    inputChain->SetBranchAddress("l2_decayMode"                                , &m_tau.decayMode                               );
    inputChain->SetBranchAddress("l2_zImpact"                                  , &m_tau.zImpact                                 );
    inputChain->SetBranchAddress("l2_dz_selfvertex"                            , &m_tau.dz_selfvertex                           );
    inputChain->SetBranchAddress("l2_againstElectronMVA5"                      , &m_tau.againstElectronMVA5                     );
    inputChain->SetBranchAddress("l2_againstElectronMVA5category"              , &m_tau.againstElectronMVA5category             );
    inputChain->SetBranchAddress("l2_againstElectronMVA5raw"                   , &m_tau.againstElectronMVA5raw                  );
    inputChain->SetBranchAddress("l2_againstMuon3"                             , &m_tau.againstMuon3                            );
    inputChain->SetBranchAddress("l2_byCombinedIsolationDeltaBetaCorrRaw3Hits" , &m_tau.byCombinedIsolationDeltaBetaCorrRaw3Hits);
    inputChain->SetBranchAddress("l2_byIsolationMVA3newDMwLTraw"               , &m_tau.byIsolationMVA3newDMwLTraw              );
    inputChain->SetBranchAddress("l2_byIsolationMVA3oldDMwLTraw"               , &m_tau.byIsolationMVA3oldDMwLTraw              );
    inputChain->SetBranchAddress("l2_byCombinedIsolationDeltaBetaCorr3Hits"    , &m_tau.byCombinedIsolationDeltaBetaCorr3Hits   );
    inputChain->SetBranchAddress("l2_byIsolationMVA3newDMwLT"                  , &m_tau.byIsolationMVA3newDMwLT                 );
    inputChain->SetBranchAddress("l2_byIsolationMVA3oldDMwLT"                  , &m_tau.byIsolationMVA3oldDMwLT                 );
    inputChain->SetBranchAddress("l2_chargedIsoPtSum"                          , &m_tau.chargedIsoPtSum                         );
    inputChain->SetBranchAddress("l2_decayModeFinding"                         , &m_tau.decayModeFinding                        );
    inputChain->SetBranchAddress("l2_decayModeFindingNewDMs"                   , &m_tau.decayModeFindingNewDMs                  );
    inputChain->SetBranchAddress("l2_neutralIsoPtSum"                          , &m_tau.neutralIsoPtSum                         );
    inputChain->SetBranchAddress("l2_puCorrPtSum"                              , &m_tau.puCorrPtSum                             );
    inputChain->SetBranchAddress("l2_gen_match"                                , &m_tau.gen_match                               );
    inputChain->SetBranchAddress("l2_gen_pt"                                   , &m_tauMatch.pt                                 );
    inputChain->SetBranchAddress("l2_gen_eta"                                  , &m_tauMatch.eta                                );
    inputChain->SetBranchAddress("l2_gen_phi"                                  , &m_tauMatch.phi                                );
    inputChain->SetBranchAddress("l2_gen_charge"                               , &m_tauMatch.charge                             );
    inputChain->SetBranchAddress("l2_gen_mass"                                 , &m_tauMatch.mass                               );
    inputChain->SetBranchAddress("l2_gen_pdgId"                                , &m_tauMatch.pdgId                              );
    //inputChain->SetBranchAddress("l2_byPileupWeightedIsolation3Hits"           , &m_tau.byPileupWeightedIsolation3Hits          );
    //inputChain->SetBranchAddress("l2_byPileupWeightedIsolationRaw3Hits"        , &m_tau.byPileupWeightedIsolationRaw3Hits       );
    //inputChain->SetBranchAddress("l2_neutralIsoPtSumWeight"                    , &m_tau.neutralIsoPtSumWeight                   );
    //inputChain->SetBranchAddress("l2_footprintCorrection"                      , &m_tau.footprintCorrection                     );
    //inputChain->SetBranchAddress("l2_photonPtSumOutsideSignalCone"             , &m_tau.photonPtSumOutsideSignalCone            );



    registerCallback((void*)this, EventMuTau::callback);

}

/*****************************************************************/
bool EventMuTau::passSelection(int selection)
/*****************************************************************/
{
    bool pass = true;
    pass &= (tau().pt > 0.);
    switch(selection)
    {
        case 0: // Standard tau isolation
            pass &= (tau().byCombinedIsolationDeltaBetaCorrRaw3Hits < 1.5);
            break;
        case 1: // Reversed isolation
            pass &= (tau().byCombinedIsolationDeltaBetaCorrRaw3Hits > 1.5);
            break;
        case 2: // No isolation
            break;
        default:
            break;
    };
    return pass;
}


/*****************************************************************/
void EventMuTau::update()
/*****************************************************************/
{
    IEvent::update();

}

/*****************************************************************/
void EventMuTau::callback(void* object)
/*****************************************************************/
{
    EventMuTau* myself = reinterpret_cast<EventMuTau*>(object);
    myself->buildEvent();
}


/*****************************************************************/
void EventMuTau::buildEvent()
/*****************************************************************/
{
    m_muon.SetPtEtaPhiM(muon().pt, muon().eta, muon().phi, muon().mass);
    m_tau.SetPtEtaPhiM(tau().pt,tau().eta,tau().phi,tau().mass);
    m_tauMatch.SetPtEtaPhiM(tauMatch().pt,tauMatch().eta,tauMatch().phi,tauMatch().mass);
    m_tauMatch.computeChargeFromPdgId();
    m_tau.sign_flip = (tau().charge*tauMatch().charge<0 ? -1 : 1);
    if(tau().charge==0 || tauMatch().charge==0) m_tau.sign_flip = 0;
}



