/**
 *  @file  AnalysisFakeRateApplyBackup.h
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <sauvan@llr.in2p3.fr>
 *
 *  @date    20/11/2015
 *
 *  @internal
 *     Created :  20/11/2015
 * Last update :  20/11/2015 14:09:35
 *          by :  JB Sauvan
 *
 * =====================================================================================
 */






#ifndef AnalysisFakeRateApplyBackup_h
#define AnalysisFakeRateApplyBackup_h

#include "AnHiMaCMG/Core/interface/IAnalysis.h"
#include "AnHiMaCMG/Core/interface/EventAware.h"
#include "AnHiMaCMG/H2TausCommon/interface/EventMuTau.h"
#include "AnHiMaCMG/H2TausCommon/interface/FakeFactors.h"



class TObject;

namespace AnHiMa
{

    class AnalysisFakeRateApplyBackup: public IAnalysis, EventAware<EventMuTau>
    {
        public:
            AnalysisFakeRateApplyBackup();
            ~AnalysisFakeRateApplyBackup();

            bool initialize(const std::string& parameterFile);

            void execute();

        private:
            void fillHistos(unsigned, const std::string&);

            FakeFactors m_fakeFactors;

    };
}


#endif
