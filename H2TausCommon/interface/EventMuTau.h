/**
 *  @file  EventMuTau.h
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <sauvan@llr.in2p3.fr>
 *
 *  @date    20/11/2015
 *
 *  @internal
 *     Created :  20/11/2015
 * Last update :  20/11/2015 13:53:34
 *          by :  JB Sauvan
 *
 * =====================================================================================
 */






#ifndef EventMuTau_h
#define EventMuTau_h

#include "AnHiMaCMG/Core/interface/IEvent.h"
#include "AnHiMaCMG/Core/interface/TParticlePair.h"

#include "AnHiMaCMG/H2TausCommon/interface/Particles.h"

#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <string>
#include <memory>




namespace AnHiMa
{


    class EventMuTau: public IEvent
    {
        public:
            EventMuTau();
            ~EventMuTau();

            bool passSelection(int selection=0);
            // FIXME: change this ****** naming
            bool passSelectionSignal(int iso=0, int applyMT=0, int sign=0);
            bool passSelectionBackup(int selection=0);
            bool passSelectionFakeFactorsWJetsHighMT(int iso=0, bool os=true);
            bool passSelectionFakeFactorsQCD(int iso=0, int isomu=0, bool os=true);
            bool passSelectionForPolarization(int selection=0);
            bool passSelectionWJetsStudy(int selection=0);
            bool passSelectionWJetsContamination(int selection=0);
            void connectVariables(TChain* inputChain);
            void update();

            int event()                const {return (int)m_event;}
            int lumi()                 const {return (int)m_lumi;}
            int run()                  const {return (int)m_run;}
            int n_vertices()           const {return (int)m_n_vertices;}
            float rho()                const {return m_rho;}
            int n_jets()               const {return (int)m_n_jets;}
            int n_jets_puid()          const {return (int)m_n_jets_puid;}
            int n_jets_20()            const {return (int)m_n_jets_20;}
            int n_jets_20_puid()       const {return (int)m_n_jets_20_puid;}
            float weight()             const {return m_weight;}
            float weight_vertex()      const {return m_weight_vertex;}
            float mt()                 const {return m_mt;}
            float mt_gen()             const {return m_mt_gen;}
            float mvis()               const {return m_mvis;}
            float met_pt()             const {return m_met_pt;}
            float met_gen_pt()         const {return m_met_gen_pt;}
            float met_gen_phi()        const {return m_met_gen_phi;}
            float delta_phi_muon_met() const {return m_delta_phi_l1_met;}
            float delta_phi_tau_met()  const {return m_delta_phi_l2_met;}


            const Muon& muon()            const {return m_muon;}
            const Tau& tau()              const {return m_tau;}
            const GenParticle& tauMatch() const {return m_tauMatch;}
            const Particle& tauJetMatch() const {return m_tauJetMatch;}


        private:
            static void callback(void*);
            void buildEvent();

            double m_event;
            double m_lumi;
            double m_run;
            double m_npu;
            double m_n_vertices;
            double m_rho;
            double m_n_jets;
            double m_n_jets_puid;
            double m_n_jets_20;
            double m_n_jets_20_puid;
            double m_weight;
            double m_weight_vertex;
            double m_mt;
            double m_mt_gen;
            double m_mvis;
            double m_met_pt;
            double m_met_gen_pt;
            double m_met_gen_phi;
            double m_delta_phi_l1_met;
            double m_delta_phi_l2_met;

            Muon m_muon;
            Tau m_tau;
            GenParticle m_tauMatch;
            Particle m_tauJetMatch;

    };
}

#endif
