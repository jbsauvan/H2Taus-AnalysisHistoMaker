/**
 *  @file  AnalysisStatUncertainty.h
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <sauvan@llr.in2p3.fr>
 *
 *  @date    01/05/2016
 *
 *  @internal
 *     Created :  01/05/2016
 * Last update :  01/05/2016 11:25:27 AM
 *          by :  JB Sauvan
 *
 * =====================================================================================
 */






#ifndef AnalysisStatUncertainty_h
#define AnalysisStatUncertainty_h

#include "AnHiMaCMG/Core/interface/IAnalysis.h"
#include "AnHiMaCMG/Core/interface/EventAware.h"
#include "AnHiMaCMG/H2TausCommon/interface/EventMuTau.h"
#include "AnHiMaCMG/H2TausCommon/interface/FakeFactors.h"



class TObject;

namespace AnHiMa
{

    class AnalysisStatUncertainty: public IAnalysis, EventAware<EventMuTau>
    {
        public:
            AnalysisStatUncertainty();
            ~AnalysisStatUncertainty();

            bool initialize(const std::string& parameterFile);

            void execute();

        private:
            void fillHistos(unsigned, const std::string&);

            FakeFactors m_fakeFactors;

    };
}


#endif
