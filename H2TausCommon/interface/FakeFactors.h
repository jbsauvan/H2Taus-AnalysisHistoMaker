




#ifndef FakeFactors_h
#define FakeFactors_h

#include <map>
#include <utility>
#include "AnHiMaCMG/H2TausCommon/interface/EventMuTau.h"
#include "AnHiMaCMG/H2TausCommon/interface/EventMuMu.h"
#include "TRandom3.h"

class TObject;

namespace AnHiMa
{
    class FakeFactors
    {
        public:
            FakeFactors();
            ~FakeFactors();

            bool addFakeFactor(const std::string&, const std::string&, const std::string&, const std::string&);
            void createCombinedFakeFactorFormulas();
            double retrieveFakeFactor(const std::string&, const EventMuTau&, bool fluctuate=false);
            double retrieveFakeFactor(const std::string&, const EventMuMu&, bool fluctuate=false);


        private:
            TRandom3 m_random;
            std::vector<std::string> m_fakeFactorNames;
            std::map<std::string, std::pair<std::string, TObject*>> m_fakeFactors; // name, type, object
            std::map<std::string, std::string> m_fakeFactorFormulas;
            std::map<std::string, std::vector<std::string>> m_formulaVariables;

    };
}



#endif
