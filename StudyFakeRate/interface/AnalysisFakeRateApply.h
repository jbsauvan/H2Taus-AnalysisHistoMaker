/**
 *  @file  AnalysisFakeRateApply.h
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






#ifndef AnalysisFakeRateApply_h
#define AnalysisFakeRateApply_h

#include "AnHiMaCMG/Core/interface/IAnalysis.h"
#include "AnHiMaCMG/Core/interface/EventAware.h"
#include "AnHiMaCMG/H2TausCommon/interface/EventMuTau.h"

#include "TGraphAsymmErrors.h"


namespace AnHiMa
{

    class AnalysisFakeRateApply: public IAnalysis, EventAware<EventMuTau>
    {
        public:
            AnalysisFakeRateApply();
            ~AnalysisFakeRateApply();

            bool initialize(const std::string& parameterFile);

            void execute();

        private:
            void fillHistos(unsigned, const std::string&);
            double retrieveFakeFactor(const std::string&);

            std::map<std::string, TGraphAsymmErrors*> m_fakeFactors;
    };
}


#endif
