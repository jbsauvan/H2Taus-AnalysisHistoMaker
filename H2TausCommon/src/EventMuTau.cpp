






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
    inputChain->SetBranchStatus("n_jets"                                   , true);
    inputChain->SetBranchStatus("n_jets_puid"                              , true);
    inputChain->SetBranchStatus("n_jets_20"                                , true);
    inputChain->SetBranchStatus("n_jets_20_puid"                           , true);
    inputChain->SetBranchStatus("weight"                                   , true);
    inputChain->SetBranchStatus("weight_vertex"                            , true);
    inputChain->SetBranchStatus("mt"                                       , true);
    inputChain->SetBranchStatus("mvis"                                     , true);
    inputChain->SetBranchStatus("met_pt"                                   , true);
    inputChain->SetBranchStatus("genmet_pt"                                , true);
    inputChain->SetBranchStatus("genmet_phi"                               , true);
    inputChain->SetBranchStatus("delta_phi_l1_met"                         , true);
    inputChain->SetBranchStatus("delta_phi_l2_met"                         , true);
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
    //inputChain->SetBranchStatus("l1_weight_rec_eff"                        , true);
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
    //inputChain->SetBranchStatus("l2_weight_rec_eff"                           , true);
    inputChain->SetBranchStatus("l2_decayMode"                                , true);
    inputChain->SetBranchStatus("l2_zImpact"                                  , true);
    inputChain->SetBranchStatus("l2_dz_selfvertex"                            , true);
    inputChain->SetBranchStatus("l2_againstElectronMVA6"                      , true);
    inputChain->SetBranchStatus("l2_againstElectronMVA6category"              , true);
    inputChain->SetBranchStatus("l2_againstElectronMVA6raw"                   , true);
    inputChain->SetBranchStatus("l2_againstMuon3"                             , true);
    inputChain->SetBranchStatus("l2_byCombinedIsolationDeltaBetaCorrRaw3Hits" , true);
    inputChain->SetBranchStatus("l2_byIsolationMVA3newDMwLTraw"               , true);
    inputChain->SetBranchStatus("l2_byIsolationMVA3oldDMwLTraw"               , true);
    inputChain->SetBranchStatus("l2_byIsolationMVArun2v1DBnewDMwLTraw"        , true);
    inputChain->SetBranchStatus("l2_byIsolationMVArun2v1DBoldDMwLTraw"        , true);
    inputChain->SetBranchStatus("l2_byCombinedIsolationDeltaBetaCorr3Hits"    , true);
    inputChain->SetBranchStatus("l2_byIsolationMVA3newDMwLT"                  , true);
    inputChain->SetBranchStatus("l2_byIsolationMVA3oldDMwLT"                  , true);
    inputChain->SetBranchStatus("l2_byIsolationMVArun2v1DBnewDMwLT"           , true);
    inputChain->SetBranchStatus("l2_byIsolationMVArun2v1DBoldDMwLT"           , true);
    inputChain->SetBranchStatus("l2_chargedIsoPtSum"                          , true);
    inputChain->SetBranchStatus("l2_decayModeFinding"                         , true);
    inputChain->SetBranchStatus("l2_decayModeFindingNewDMs"                   , true);
    inputChain->SetBranchStatus("l2_neutralIsoPtSum"                          , true);
    inputChain->SetBranchStatus("l2_puCorrPtSum"                              , true);
    inputChain->SetBranchStatus("l2_nc_ratio"                                 , true);
    inputChain->SetBranchStatus("l2_jet_pt"                                   , true);
    inputChain->SetBranchStatus("l2_jet_eta"                                  , true);
    inputChain->SetBranchStatus("l2_jet_phi"                                  , true);
    inputChain->SetBranchStatus("l2_jet_mass"                                 , true);
    inputChain->SetBranchStatus("l2_jet_charge"                               , true);
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
    inputChain->SetBranchStatus("l2_photonPtSumOutsideSignalCone"             , true);



    // Connect event branches
    inputChain->SetBranchAddress("run"              , &m_run);
    inputChain->SetBranchAddress("lumi"             , &m_lumi);
    inputChain->SetBranchAddress("event"            , &m_event);
    inputChain->SetBranchAddress("n_vertices"       , &m_n_vertices);
    inputChain->SetBranchAddress("n_jets"           , &m_n_jets);
    inputChain->SetBranchAddress("n_jets_puid"      , &m_n_jets_puid);
    inputChain->SetBranchAddress("n_jets_20"        , &m_n_jets_20);
    inputChain->SetBranchAddress("n_jets_20_puid"   , &m_n_jets_20_puid);
    inputChain->SetBranchAddress("rho"              , &m_rho);
    inputChain->SetBranchAddress("weight"           , &m_weight);
    inputChain->SetBranchAddress("weight_vertex"    , &m_weight_vertex);
    inputChain->SetBranchAddress("mt"               , &m_mt);
    inputChain->SetBranchAddress("mvis"             , &m_mvis);
    inputChain->SetBranchAddress("met_pt"           , &m_met_pt);
    inputChain->SetBranchAddress("genmet_pt"        , &m_met_gen_pt);
    inputChain->SetBranchAddress("genmet_phi"       , &m_met_gen_phi);
    inputChain->SetBranchAddress("delta_phi_l1_met" , &m_delta_phi_l2_met); // FIXME: swap l1 and l2 in trees
    inputChain->SetBranchAddress("delta_phi_l2_met" , &m_delta_phi_l1_met);
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
    //inputChain->SetBranchAddress("l1_weight_rec_eff"   , &m_muon.weight_rec_eff   );
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
    //inputChain->SetBranchAddress("l2_weight_rec_eff"                           , &m_tau.weight_rec_eff                          );
    inputChain->SetBranchAddress("l2_decayMode"                                , &m_tau.decayMode                               );
    inputChain->SetBranchAddress("l2_zImpact"                                  , &m_tau.zImpact                                 );
    inputChain->SetBranchAddress("l2_dz_selfvertex"                            , &m_tau.dz_selfvertex                           );
    inputChain->SetBranchAddress("l2_againstElectronMVA6"                      , &m_tau.againstElectronMVA6                     );
    inputChain->SetBranchAddress("l2_againstElectronMVA6category"              , &m_tau.againstElectronMVA6category             );
    inputChain->SetBranchAddress("l2_againstElectronMVA6raw"                   , &m_tau.againstElectronMVA6raw                  );
    inputChain->SetBranchAddress("l2_againstMuon3"                             , &m_tau.againstMuon3                            );
    inputChain->SetBranchAddress("l2_byCombinedIsolationDeltaBetaCorrRaw3Hits" , &m_tau.byCombinedIsolationDeltaBetaCorrRaw3Hits);
    inputChain->SetBranchAddress("l2_byIsolationMVA3newDMwLTraw"               , &m_tau.byIsolationMVA3newDMwLTraw              );
    inputChain->SetBranchAddress("l2_byIsolationMVA3oldDMwLTraw"               , &m_tau.byIsolationMVA3oldDMwLTraw              );
    inputChain->SetBranchAddress("l2_byIsolationMVArun2v1DBnewDMwLTraw"        , &m_tau.byIsolationMVArun2v1DBnewDMwLTraw       );
    inputChain->SetBranchAddress("l2_byIsolationMVArun2v1DBoldDMwLTraw"        , &m_tau.byIsolationMVArun2v1DBoldDMwLTraw       );
    inputChain->SetBranchAddress("l2_byCombinedIsolationDeltaBetaCorr3Hits"    , &m_tau.byCombinedIsolationDeltaBetaCorr3Hits   );
    inputChain->SetBranchAddress("l2_byIsolationMVA3newDMwLT"                  , &m_tau.byIsolationMVA3newDMwLT                 );
    inputChain->SetBranchAddress("l2_byIsolationMVA3oldDMwLT"                  , &m_tau.byIsolationMVA3oldDMwLT                 );
    inputChain->SetBranchAddress("l2_byIsolationMVArun2v1DBnewDMwLT"           , &m_tau.byIsolationMVArun2v1DBnewDMwLT          );
    inputChain->SetBranchAddress("l2_byIsolationMVArun2v1DBoldDMwLT"           , &m_tau.byIsolationMVArun2v1DBoldDMwLT          );
    inputChain->SetBranchAddress("l2_chargedIsoPtSum"                          , &m_tau.chargedIsoPtSum                         );
    inputChain->SetBranchAddress("l2_decayModeFinding"                         , &m_tau.decayModeFinding                        );
    inputChain->SetBranchAddress("l2_decayModeFindingNewDMs"                   , &m_tau.decayModeFindingNewDMs                  );
    inputChain->SetBranchAddress("l2_neutralIsoPtSum"                          , &m_tau.neutralIsoPtSum                         );
    inputChain->SetBranchAddress("l2_puCorrPtSum"                              , &m_tau.puCorrPtSum                             );
    inputChain->SetBranchAddress("l2_nc_ratio"                                 , &m_tau.nc_ratio                                );
    inputChain->SetBranchAddress("l2_gen_match"                                , &m_tau.gen_match                               );
    inputChain->SetBranchAddress("l2_jet_pt"                                   , &m_tauJetMatch.pt                              );
    inputChain->SetBranchAddress("l2_jet_eta"                                  , &m_tauJetMatch.eta                             );
    inputChain->SetBranchAddress("l2_jet_phi"                                  , &m_tauJetMatch.phi                             );
    inputChain->SetBranchAddress("l2_jet_charge"                               , &m_tauJetMatch.charge                          );
    inputChain->SetBranchAddress("l2_jet_mass"                                 , &m_tauJetMatch.mass                            );
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
    inputChain->SetBranchAddress("l2_photonPtSumOutsideSignalCone"             , &m_tau.photonPtSumOutsideSignalCone            );



    registerCallback((void*)this, EventMuTau::callback);

}

/*****************************************************************/
bool EventMuTau::passSelection(int selection)
/*****************************************************************/
{
    bool pass = true;
    pass &= (tau().pt > 0.);
    switch(selection%20)
    {
        case 0: // No isolation
            break;
        case 1: // Tau isolation tight
            //pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits >= 2);
            pass &= (tau().byIsolationMVArun2v1DBoldDMwLT>= 4);
            break;
        case 2: // Reverse tau isolation tight
            //pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits < 2);
            pass &= (tau().byIsolationMVArun2v1DBoldDMwLT< 4);
            break;
        default:
            break;
    };
    if(selection/20==1) // apply mT cut
    {
        pass &= (mt()<40.);
    }
    return pass;
}

/*****************************************************************/
bool EventMuTau::passSelectionSignal(int iso, int applyMT, int sign)
/*****************************************************************/
{
    bool pass = true;
    pass &= (tau().pt > 0.);
    switch(iso)
    {
        case 0: // No isolation
            break;
        case 1: // Tau isolation tight
            //pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits >= 2);
            pass &= (tau().byIsolationMVArun2v1DBoldDMwLT>= 4);
            break;
        case 2: // Reverse tau isolation tight
            //pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits < 2);
            pass &= (tau().byIsolationMVArun2v1DBoldDMwLT< 4);
            break;
        default:
            break;
    };
    if(applyMT==1) // apply mT cut
    {
        pass &= (mt()<40.);
    }
    switch(sign)
    {
        case 0: // No sign requirement
            break;
        case 1: // OS
            pass &= (tau().charge*muon().charge<0);
            break;
        case 2: // SS
            pass &= (tau().charge*muon().charge>0);
            break;
        default:
            break;
    };
    return pass;
}

/*****************************************************************/
bool EventMuTau::passSelectionBackup(int selection)
/*****************************************************************/
{
    bool pass = true;
    pass &= (tau().pt > 0.);
    switch(selection%20)
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
        case 5: // Reversed isolation raw > 3 GeV
            pass &= (tau().byCombinedIsolationDeltaBetaCorrRaw3Hits > 3.);
            break;
        default:
            break;
    };
    if(selection/20==1) // apply mT cut
    {
        pass &= (mt()<40.);
    }
    return pass;
}

/*****************************************************************/
bool EventMuTau::passSelectionFakeFactorsWJetsHighMT(int iso, bool os)
/*****************************************************************/
{
    bool pass = true;
    pass &= (tau().pt > 0.);
    pass &= (mt()>70.);
    if(os) pass &= (tau().charge*muon().charge<0); 
    else pass &= (tau().charge*muon().charge>0);
    switch(iso)
    {
        case 0: // Tau isolation raw < 1.5 GeV
            pass &= (tau().byCombinedIsolationDeltaBetaCorrRaw3Hits < 1.5);
            break;
        case 1: // Reversed isolation raw > 1.5 GeV
            pass &= (tau().byCombinedIsolationDeltaBetaCorrRaw3Hits > 1.5);
            break;
        case 2: // No isolation
            break;
        case 3: // Tau isolation tight
            //pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits >= 2);
            pass &= (tau().byIsolationMVArun2v1DBoldDMwLT>=4);
            break;
        case 4: // Reverse tau isolation tight
            //pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits < 2);
            pass &= (tau().byIsolationMVArun2v1DBoldDMwLT< 4);
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
bool EventMuTau::passSelectionFakeFactorsQCD(int iso, int isomu, bool os)
/*****************************************************************/
{
    bool pass = true;
    pass &= (tau().pt > 0.);
    pass &= (mt()<40.);
    if(os) pass &= (tau().charge*muon().charge<0); 
    else pass &= (tau().charge*muon().charge>0);
    switch(isomu)
    {
        case 0: // anti-isolattion
            pass &= (muon().reliso05>0.15);
            break;
        case 1: // medium isolation
            pass &= (muon().reliso05>0.05 && muon().reliso05<0.15);
            break;
        default:
            break;
    };
    switch(iso)
    {
        case 0: // Tau isolation raw < 1.5 GeV
            pass &= (tau().byCombinedIsolationDeltaBetaCorrRaw3Hits < 1.5);
            break;
        case 1: // Reversed isolation raw > 1.5 GeV
            pass &= (tau().byCombinedIsolationDeltaBetaCorrRaw3Hits > 1.5);
            break;
        case 2: // No isolation
            break;
        case 3: // Tau isolation tight
            //pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits >= 2);
            pass &= (tau().byIsolationMVArun2v1DBoldDMwLT>= 4);
            break;
        case 4: // Reverse tau isolation tight
            //pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits < 2);
            pass &= (tau().byIsolationMVArun2v1DBoldDMwLT< 4);
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
bool EventMuTau::passSelectionForPolarization(int selection)
/*****************************************************************/
{
    bool pass = true;
    pass &= (tau().pt > 0.);
    switch(selection%20)
    {
        case 0: // Tau isolation tight
            //pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits >= 2);
            pass &= (tau().byIsolationMVArun2v1DBoldDMwLT>= 4);
            break;
        case 1: // Reverse tau isolation tight
            //pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits < 2);
            pass &= (tau().byIsolationMVArun2v1DBoldDMwLT< 4);
            break;
        case 2: // Tau isolation raw < 1.5 GeV
            pass &= (tau().byCombinedIsolationDeltaBetaCorrRaw3Hits < 1.5);
            break;
        case 3: // Reversed isolation raw > 1.5 GeV
            pass &= (tau().byCombinedIsolationDeltaBetaCorrRaw3Hits > 1.5);
            break;
        case 4: // Reversed medium isolation only reversing the raw isolation part
            pass &= (tau().byCombinedIsolationDeltaBetaCorrRaw3Hits > 1.5 && tau().photonPtSumOutsideSignalCone/tau().Pt()<0.1);
            break;
        default:
            break;
    };
    if(selection/20==0) // apply mT cut
    {
        pass &= (mt()<40.);
    }
    else if(selection/20==1) // reverse mT cut
    {
        pass &= (mt()>40.);
    }
    return pass;
}

/*****************************************************************/
bool EventMuTau::passSelectionWJetsStudy(int selection)
/*****************************************************************/
{
    bool pass = true;
    pass &= (tau().pt > 0.);
    switch(selection)
    {
        case 0: // Tau isolation tight + OS
            //pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits >= 2);
            pass &= (tau().byIsolationMVArun2v1DBoldDMwLT>= 4);
            pass &= (tau().charge*muon().charge<0);
            break;
        case 1: // Reverse tau isolation tight + OS
            //pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits < 2);
            pass &= (tau().byIsolationMVArun2v1DBoldDMwLT< 4);
            pass &= (tau().charge*muon().charge<0);
            break;
        case 2: // Loose10 reverse tau isolation medium + OS
            pass &= (tau().byCombinedIsolationDeltaBetaCorrRaw3Hits < 10.);
            pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits < 2);
            pass &= (tau().charge*muon().charge<0);
            break;
        case 3: // Loose20 reverse tau isolation medium + OS
            pass &= (tau().byCombinedIsolationDeltaBetaCorrRaw3Hits < 20.);
            pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits < 2);
            pass &= (tau().charge*muon().charge<0);
            break;
        case 4: //  OS
            pass &= (tau().charge*muon().charge<0);
            break;
        case 5: // Tau isolation tight + SS
            //pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits >= 2);
            pass &= (tau().byIsolationMVArun2v1DBoldDMwLT>= 4);
            pass &= (tau().charge*muon().charge>0);
            break;
        case 6: // Reverse tau isolation tight + SS
            //pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits < 2);
            pass &= (tau().byIsolationMVArun2v1DBoldDMwLT< 4);
            pass &= (tau().charge*muon().charge>0);
            break;
        case 7: // SS
            pass &= (tau().charge*muon().charge>0);
        default:
            break;
    };

    return pass;
}

/*****************************************************************/
bool EventMuTau::passSelectionWJetsContamination(int selection)
/*****************************************************************/
{
    bool pass = true;
    pass &= (tau().pt > 0.);
    double highMtCut = 70.;
    switch(selection)
    {
        case 0: // high-MT + OS
            pass &= (mt()>highMtCut);
            pass &= (tau().charge*muon().charge<0);
            break;
        case 1: // high-MT + SS
            pass &= (mt()>highMtCut);
            pass &= (tau().charge*muon().charge>0);
            break;
        case 2: // high-MT + OS + tight iso
            pass &= (mt()>highMtCut);
            //pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits >= 2);
            pass &= (tau().byIsolationMVArun2v1DBoldDMwLT>= 4);
            pass &= (tau().charge*muon().charge<0);
            break;
        case 3: // high-MT + SS + tight iso
            pass &= (mt()>highMtCut);
            //pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits >= 2);
            pass &= (tau().byIsolationMVArun2v1DBoldDMwLT>= 4);
            pass &= (tau().charge*muon().charge>0);
            break;
        case 4: // high-MT + OS + anti tight iso
            pass &= (mt()>highMtCut);
            //pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits < 2);
            pass &= (tau().byIsolationMVArun2v1DBoldDMwLT< 4);
            pass &= (tau().charge*muon().charge<0);
            break;
        case 5: // high-MT + SS + anti  tight iso
            pass &= (mt()>highMtCut);
            //pass &= (tau().byCombinedIsolationDeltaBetaCorr3Hits < 2);
            pass &= (tau().byIsolationMVArun2v1DBoldDMwLT< 4);
            pass &= (tau().charge*muon().charge>0);
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
    // Build TLorentzVector
    m_muon.SetPtEtaPhiM(muon().pt, muon().eta, muon().phi, muon().mass);
    m_tau.SetPtEtaPhiM(tau().pt,tau().eta,tau().phi,tau().mass);
    m_tauMatch.SetPtEtaPhiM(tauMatch().pt,tauMatch().eta,tauMatch().phi,tauMatch().mass);
    m_tauJetMatch.SetPtEtaPhiM(tauJetMatch().pt,tauJetMatch().eta,tauJetMatch().phi,tauJetMatch().mass);
    // Recompute parton charge from pdg ID
    m_tauMatch.computeChargeFromPdgId();
    // Compute tau sign-flip
    m_tau.sign_flip = (tau().charge*tauMatch().charge<0 ? -1 : 1);
    if(tau().charge==0 || tauMatch().charge==0) m_tau.sign_flip = 0;
    //
    // Compute gen mT
    m_mt_gen = sqrt(2.*muon().Pt()*met_pt()*(1.-cos(met_gen_phi()-muon().Phi())));
}



