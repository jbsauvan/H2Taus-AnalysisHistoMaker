/**
 *  @file  AnalysisPolarizationBackground.h
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <sauvan@llr.in2p3.fr>
 *
 *  @date    12/14/2015
 *
 *  @internal
 *     Created :  12/14/2015
 * Last update :  12/14/2015 04:50:00 PM
 *          by :  JB Sauvan
 *
 * =====================================================================================
 */





#ifndef AnalysisPolarizationBackground_h
#define AnalysisPolarizationBackground_h

#include "AnHiMaCMG/Core/interface/IAnalysis.h"
#include "AnHiMaCMG/Core/interface/EventAware.h"
#include "AnHiMaCMG/H2TausCommon/interface/EventMuTau.h"



class TObject;

namespace AnHiMa
{

    class AnalysisPolarizationBackground: public IAnalysis, EventAware<EventMuTau>
    {
        public:
            AnalysisPolarizationBackground();
            ~AnalysisPolarizationBackground();

            bool initialize(const std::string& parameterFile);

            void execute();

        private:
            void fillHistos(unsigned, const std::string&);
            double retrieveFakeFactor(const std::string&);

            std::map<std::string, std::pair<std::string, TObject*>> m_fakeFactors;

    };
}


#endif
