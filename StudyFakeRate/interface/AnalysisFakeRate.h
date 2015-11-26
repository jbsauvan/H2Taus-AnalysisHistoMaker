/**
 *  @file  AnalysisFakeRate.h
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <sauvan@llr.in2p3.fr>
 *
 *  @date    19/11/2015
 *
 *  @internal
 *     Created :  19/11/2015
 * Last update :  19/11/2015 10:49:43
 *          by :  JB Sauvan
 *
 * =====================================================================================
 */






#ifndef AnalysisFakeRate_h
#define AnalysisFakeRate_h

#include "AnHiMaCMG/Core/interface/IAnalysis.h"
#include "AnHiMaCMG/Core/interface/EventAware.h"
#include "AnHiMaCMG/H2TausCommon/interface/EventMuMu.h"



namespace AnHiMa
{

    class AnalysisFakeRate: public IAnalysis, EventAware<EventMuMu>
    {
        public:
            AnalysisFakeRate();
            ~AnalysisFakeRate();

            bool initialize(const std::string& parameterFile);

            void execute();

        private:
            void fillHistos(unsigned);
    };
}


#endif
