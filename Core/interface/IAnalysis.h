/**
 *  @file  IAnalysis.h
 *  @brief  
 *
 *
 *  @author  Jean-Baptiste Sauvan <sauvan@llr.in2p3.fr>
 *
 *  @date    12/17/2012
 *
 *  @internal
 *     Created :  12/17/2012
 * Last update :  12/17/2012 10:46:38 AM
 *          by :  JB Sauvan
 *
 * =====================================================================================
 */

#ifndef IAnalysis_h
#define IAnalysis_h


#include <string>


#include "AnHiMaCMG/Core/interface/HistoManager.h"
#include "AnHiMaCMG/Core/interface/ParReader.h"

class TFile;
class TChain;
class TEntryList;

namespace AnHiMa
{

    class IAnalysis
    {
        public:
            IAnalysis();
            virtual ~IAnalysis();

            virtual bool initialize(const std::string& parameterFile);
            void loop();
            unsigned systematicNumber(const std::string&);
            const std::vector<std::string>& systematicList() const {return m_systematicsList;}
            virtual void execute() = 0;


        protected:
            std::string m_workingDirectory;
            std::string m_outputFileName;
            TChain* m_inputChain;
            TEntryList* m_entryList;
            Long64_t m_nEntries;
            std::string m_cuts;
            TFile* m_outputFile;
            HistoManager m_histos;
            ParReader m_reader;
            std::vector<std::string> m_systematicsList;
            std::map<std::string, unsigned> m_systematicsMap;

    };

}

#endif 
