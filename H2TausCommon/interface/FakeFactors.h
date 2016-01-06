/**
 *  @file  FakeFactors.h
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <sauvan@llr.in2p3.fr>
 *
 *  @date    01/04/2016
 *
 *  @internal
 *     Created :  01/04/2016
 * Last update :  01/04/2016 02:59:44 PM
 *          by :  JB Sauvan
 *
 * =====================================================================================
 */





#ifndef FakeFactors_h
#define FakeFactors_h

#include <map>
#include <utility>
#include "AnHiMaCMG/H2TausCommon/interface/EventMuTau.h"

class TObject;

namespace AnHiMa
{
    class FakeFactors
    {
        public:
            FakeFactors();
            ~FakeFactors();

            bool addFakeFactor(const std::string&, const std::string&, const std::string&, const std::string&);
            double retrieveFakeFactor(const std::string&, const EventMuTau&, bool fluctuate=false);


        private:
            std::map<std::string, std::pair<std::string, TObject*>> m_fakeFactors;

    };
}



#endif
