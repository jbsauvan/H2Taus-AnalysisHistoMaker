




#ifndef FakeFactors_h
#define FakeFactors_h

#include <map>
#include <utility>
#include "AnHiMaCMG/H2TausCommon/interface/EventMuTau.h"
#include "AnHiMaCMG/H2TausCommon/interface/EventMuMu.h"

class TObject;
class FakeFactor;

namespace AnHiMa
{
    class FakeFactors
    {
        public:
            FakeFactors();
            ~FakeFactors();

            bool addFakeFactor(const std::string&, const std::string&, const std::string&);
            double retrieveFakeFactor(const std::string&, const EventMuTau&, const std::string& systematic="");
            double retrieveFakeFactor(const std::string&, const EventMuMu&, const std::string& systematic="");


        private:
            std::map<std::string, FakeFactor*> m_fakeFactors;

    };
}



#endif
