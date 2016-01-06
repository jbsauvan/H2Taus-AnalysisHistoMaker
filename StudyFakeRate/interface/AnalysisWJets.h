/**
 *  @file  AnalysisWJets.h
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <sauvan@llr.in2p3.fr>
 *
 *  @date    01/04/2016
 *
 *  @internal
 *     Created :  01/04/2016
 * Last update :  01/04/2016 02:05:28 PM
 *          by :  JB Sauvan
 *
 * =====================================================================================
 */






#ifndef AnalysisWJets_h
#define AnalysisWJets_h

#include "AnHiMaCMG/Core/interface/IAnalysis.h"
#include "AnHiMaCMG/Core/interface/EventAware.h"
#include "AnHiMaCMG/H2TausCommon/interface/EventMuTau.h"
#include "AnHiMaCMG/H2TausCommon/interface/FakeFactors.h"


class TObject;

namespace AnHiMa
{

    class AnalysisWJets: public IAnalysis, EventAware<EventMuTau>
    {
        public:
            AnalysisWJets();
            ~AnalysisWJets();

            bool initialize(const std::string& parameterFile);

            void execute();

        private:
            void fillHistos(unsigned, const std::string&);
            //double retrieveFakeFactor(const std::string&);

            FakeFactors m_fakeFactors;
            //std::map<std::string, std::pair<std::string, TObject*>> m_fakeFactors;

    };
}


#endif
