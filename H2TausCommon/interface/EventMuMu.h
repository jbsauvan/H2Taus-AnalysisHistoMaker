/**
 *  @file  EventMuMu.h
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <sauvan@llr.in2p3.fr>
 *
 *  @date    19/11/2015
 *
 *  @internal
 *     Created :  19/11/2015
 * Last update :  19/11/2015 09:12:16
 *          by :  JB Sauvan
 *
 * =====================================================================================
 */




#ifndef EventMuMu_h
#define EventMuMu_h

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


    class EventMuMu: public IEvent
    {
        public:
            EventMuMu();
            ~EventMuMu();

            bool passSelection(int selection=0);
            void connectVariables(TChain* inputChain);
            void update();
            void setIsData(bool isData) {m_isData = isData;}

            bool isData() {return m_isData;}

            int event()           const {return (int)m_event;}
            int lumi()            const {return (int)m_lumi;}
            int run()             const {return (int)m_run;}
            int npu()             const {return (int)m_npu;}
            int n_vertices()      const {return (int)m_n_vertices;}
            float rho()           const {return m_rho;}
            float weight()        const {return m_weight;}
            float weight_vertex() const {return m_weight_vertex;}
            float mt()            const {return m_mt;}
            float mvis()          const {return m_mvis;}

            const Muon& muon(unsigned i) const {return m_muons.at(i);}
            const TParticlePair<Muon>& muonPair() const {return *m_muonPair;}
            const Tau& tau()             const {return m_tau;}
            const GenParticle& tauMatch()  const {return m_tauMatch;}
            const Particle& tauJetMatch() const {return m_tauJetMatch;}


        private:
            static void callback(void*);
            void buildEvent();

            bool m_isData;

            double m_event;
            double m_lumi;
            double m_run;
            double m_npu;
            double m_n_vertices;
            double m_rho;
            double m_weight;
            double m_weight_vertex;
            double m_mt;
            double m_mvis;

            std::vector<Muon> m_muons;
            std::unique_ptr< TParticlePair<Muon> > m_muonPair;
            Tau m_tau;
            GenParticle m_tauMatch;
            Particle m_tauJetMatch;

    };
}

#endif
