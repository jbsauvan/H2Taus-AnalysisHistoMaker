/**
 *  @file  AnalysisFakeRateZMuMuLowMTZMuMuLowMT.h
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <jsauvan@cern.ch>
 *
 *  @date    01/26/2016
 *
 *  @internal
 *     Created :  01/26/2016
 * Last update :  01/26/2016 06:23:57 PM
 *          by :  J.-B. Sauvan
 *
 * =====================================================================================
 */





#ifndef AnalysisFakeRateZMuMuLowMT_h
#define AnalysisFakeRateZMuMuLowMT_h

#include "AnHiMaCMG/Core/interface/IAnalysis.h"
#include "AnHiMaCMG/Core/interface/EventAware.h"
#include "AnHiMaCMG/H2TausCommon/interface/EventMuMu.h"
#include "AnHiMaCMG/H2TausCommon/interface/PUWeights.h"
#include "AnHiMaCMG/H2TausCommon/interface/FakeFactors.h"



namespace AnHiMa
{

    class AnalysisFakeRateZMuMuLowMT: public IAnalysis, EventAware<EventMuMu>
    {
        public:
            AnalysisFakeRateZMuMuLowMT();
            ~AnalysisFakeRateZMuMuLowMT();

            bool initialize(const std::string& parameterFile);

            void execute();

        private:
            void fillHistos(unsigned, unsigned, const std::string&);

            PUWeights m_puWeights;
            FakeFactors m_fakeFactors;
    };
}


#endif
