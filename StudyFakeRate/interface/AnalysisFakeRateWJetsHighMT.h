/**
 *  @file  AnalysisFakeRateWJetsHighMT.h
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






#ifndef AnalysisFakeRateWJetsHighMT_h
#define AnalysisFakeRateWJetsHighMT_h

#include "AnHiMaCMG/Core/interface/IAnalysis.h"
#include "AnHiMaCMG/Core/interface/EventAware.h"
#include "AnHiMaCMG/H2TausCommon/interface/EventMuTau.h"


class TObject;

namespace AnHiMa
{

    class AnalysisFakeRateWJetsHighMT: public IAnalysis, EventAware<EventMuTau>
    {
        public:
            AnalysisFakeRateWJetsHighMT();
            ~AnalysisFakeRateWJetsHighMT();

            bool initialize(const std::string& parameterFile);

            void execute();

        private:
            void fillHistos(unsigned);

    };
}


#endif
