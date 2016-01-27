/**
 *  @file  AnalysisFakeRateQCDSS.h
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <jsauvan@cern.ch>
 *
 *  @date    01/27/2016
 *
 *  @internal
 *     Created :  01/27/2016
 * Last update :  01/27/2016 06:06:03 PM
 *          by :  J.-B. Sauvan
 *
 * =====================================================================================
 */




#ifndef AnalysisFakeRateQCDSS_h
#define AnalysisFakeRateQCDSS_h

#include "AnHiMaCMG/Core/interface/IAnalysis.h"
#include "AnHiMaCMG/Core/interface/EventAware.h"
#include "AnHiMaCMG/H2TausCommon/interface/EventMuTau.h"


class TObject;

namespace AnHiMa
{

    class AnalysisFakeRateQCDSS: public IAnalysis, EventAware<EventMuTau>
    {
        public:
            AnalysisFakeRateQCDSS();
            ~AnalysisFakeRateQCDSS();

            bool initialize(const std::string& parameterFile);

            void execute();

        private:
            void fillHistos(unsigned);

    };
}


#endif
