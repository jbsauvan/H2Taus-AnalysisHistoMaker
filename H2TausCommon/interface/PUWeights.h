/**
 *  @file  PUWeights.h
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <jsauvan@cern.ch>
 *
 *  @date    01/26/2016
 *
 *  @internal
 *     Created :  01/26/2016
 * Last update :  01/26/2016 11:04:11 AM
 *          by :  J.-B. Sauvan
 *
 * =====================================================================================
 */



#ifndef PUWeights_h
#define PUWeights_h

#include <string>
#include <vector>

namespace AnHiMa
{
    class PUWeights
    {
        public:
            PUWeights();
            ~PUWeights();

            bool initialize(const std::string&, const std::string&, const std::string&, const std::string&);
            double weight(size_t npu) {return (npu<m_weights.size() ? m_weights[npu] : m_weights.back());}

        private:
            std::vector<double> m_weights;
    };

}


#endif
