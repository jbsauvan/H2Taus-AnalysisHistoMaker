/**
 *  @file  Particles.h
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <sauvan@llr.in2p3.fr>
 *
 *  @date    20/11/2015
 *
 *  @internal
 *     Created :  20/11/2015
 * Last update :  20/11/2015 13:46:56
 *          by :  JB Sauvan
 *
 * =====================================================================================
 */




#ifndef Particles_h
#define Particles_h

#include "TLorentzVector.h"


namespace AnHiMa
{

    class GenParticle: public TLorentzVector
    {
        public:
            GenParticle();
            ~GenParticle();

            double pt;
            double eta;
            double phi;
            double charge;
            double mass;
            double pdgId;

            void computeChargeFromPdgId();
    };

    class Muon: public TLorentzVector
    {
        public:
            Muon();
            ~Muon();

            double pt;
            double eta;
            double phi;
            double charge;
            double mass;
            double reliso05;
            double reliso05_04;
            double dxy;
            double dxy_error;
            double dz;
            double dz_error;
            double weight;
            double weight_trigger;
            double eff_trigger_data;
            double eff_trigger_mc;
            double weight_rec_eff;
            double muonid_loose;
            double muonid_medium;
            double muonid_tight;
            double muonid_tightnovtx;
            double muonid_highpt;
            double dxy_innertrack;
            double dz_innertrack;
            double gen_match;

    };

    class Tau: public TLorentzVector
    {
        public:
            Tau();
            ~Tau();

            double pt;
            double eta;
            double phi;
            double charge;
            double mass;
            double reliso05;
            double reliso05_04;
            double dxy;
            double dxy_error;
            double dz;
            double dz_error;
            double weight;
            double weight_trigger;
            double eff_trigger_data;
            double eff_trigger_mc;
            double weight_rec_eff;
            double decayMode;
            double zImpact;
            double dz_selfvertex;
            double againstElectronMVA5;
            double againstElectronMVA5category;
            double againstElectronMVA5raw;
            double againstMuon3;
            double byCombinedIsolationDeltaBetaCorrRaw3Hits;
            double byIsolationMVA3newDMwLTraw;
            double byIsolationMVA3oldDMwLTraw;
            double byCombinedIsolationDeltaBetaCorr3Hits;
            double byIsolationMVA3newDMwLT;
            double byIsolationMVA3oldDMwLT;
            double chargedIsoPtSum;
            double decayModeFinding;
            double decayModeFindingNewDMs;
            double neutralIsoPtSum;
            double puCorrPtSum;
            double byPileupWeightedIsolation3Hits;
            double byPileupWeightedIsolationRaw3Hits;
            double neutralIsoPtSumWeight;
            double footprintCorrection;
            double photonPtSumOutsideSignalCone;
            double gen_match;
            int    sign_flip;


    };

}

#endif
