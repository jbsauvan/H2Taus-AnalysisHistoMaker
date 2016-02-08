/**
 *  @file  AnalysisMuTauSignal.h
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <jsauvan@cern.ch>
 *
 *  @date    02/08/2016
 *
 *  @internal
 *     Created :  02/08/2016
 * Last update :  02/08/2016 04:33:21 PM
 *          by :  J.-B. Sauvan
 *
 * =====================================================================================
 */






#ifndef AnalysisMuTauSignal_h
#define AnalysisMuTauSignal_h

#include "AnHiMaCMG/Core/interface/IAnalysis.h"
#include "AnHiMaCMG/Core/interface/EventAware.h"
#include "AnHiMaCMG/H2TausCommon/interface/EventMuTau.h"



class TObject;

namespace AnHiMa
{

    class AnalysisMuTauSignal: public IAnalysis, EventAware<EventMuTau>
    {
        public:
            AnalysisMuTauSignal();
            ~AnalysisMuTauSignal();

            bool initialize(const std::string& parameterFile);

            void execute();

        private:
            void fillHistos(unsigned, const std::string&);

    };
}


#endif
