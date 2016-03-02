from AnhimaBatchLauncher import AnhimaBatchLauncher
import glob
import os
import copy
from rawFakeFactors import createZMuMuHighMT


dataff = []
mcff = []
createZMuMuHighMT(mcff,dataff)

cmssw_base = os.environ['CMSSW_BASE']

## samples
#treeDirectory =  "/afs/cern.ch/user/s/steggema/work/public/mm/190116/"
treeDirectory =  "/afs/cern.ch/work/j/jsauvan/public/HTauTau/Trees/mm/v20160220/"
treeProdName  =  "H2TauTauTreeProducerMuMu"

Name = "Name"
File = "File"
Object = "Object"
Type = "Type"
Dir  = "Dir"
Cut  = "Cut"


samples = []
samples.append({Name:"Z"           ,Dir:"DYJetsToLL_M50_LO",Cut:""})
samples.append({Name:"W"           ,Dir:"WJetsToLNu"    ,Cut:""})
samples.append({Name:"TT"          ,Dir:"TT_pow_ext"       ,Cut:""})
samples.append({Name:"T_tWch"      ,Dir:"T_tWch"           ,Cut:""})
samples.append({Name:"TBar_tWch"   ,Dir:"TBar_tWch"        ,Cut:""})
#samples.append({Name:"QCD"         ,Dir:"QCD_Mu15"         ,Cut:""})
##
samples.append({Name:"ZZTo4L"      ,Dir:"ZZTo4L"           ,Cut:""}) 
#samples.append({Name:"ZZTo2L2Q"    ,Dir:"ZZTo2L2Q"         ,Cut:""})
samples.append({Name:"WZTo3LNu"      ,Dir:"WZTo3LNu"           ,Cut:""})
#samples.append({Name:"WZTo2L2Q"    ,Dir:"WZTo2L2Q"         ,Cut:""})
samples.append({Name:"WZTo1L3Nu"   ,Dir:"WZTo1L3Nu"        ,Cut:""})
#samples.append({Name:"WZTo1L1Nu2Q" ,Dir:"WZTo1L1Nu2Q"      ,Cut:""})
#samples.append({Name:"VVTo2L2Nu"   ,Dir:"VVTo2L2Nu"        ,Cut:""})
samples.append({Name:"WWTo1L1Nu2Q" ,Dir:"WWTo1L1Nu2Q"      ,Cut:""})
##
samples.append({Name:"Data_Run15D",    Dir:"SingleMuon_Run2015D_16Dec"            ,Cut:""})

## selection
cuts = []
### Muon cuts
cuts.extend(["l1_reliso05<0.1","l1_muonid_medium>0.5","l1_pt>20"])
cuts.extend(["l2_reliso05<0.1","l2_muonid_medium>0.5","l2_pt>10"])
cuts.extend(["l1_charge*l2_charge<0"])
# Tau cuts
cuts.extend(["tau1_againstMuon3>1.5","tau1_againstElectronMVA6>0.5","tau1_pt>20"])
cuts.extend(["tau1_decayModeFinding"])
# Event cuts
cuts.extend(['!veto_dilepton && !veto_thirdlepton && !veto_otherlepton'])
# Remove events with bad missing ET
cuts.extend(['!(met_pt < 0.15 && met_phi > 0. && met_phi < 1.8)'])

#muon2PtCuts = [10,12,14,16,18,20]

batch = []

for sample in samples:
    batch.append(AnhimaBatchLauncher())
    batch[-1].name = "FakeRate_ZMuMu_MTStudy_{0}".format(sample[Name])
    batch[-1].exe = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/CMSSW/CMSSW_7_6_3/bin/slc6_amd64_gcc493/fakerate_zmumu_mtstudy.exe"
    batch[-1].baseDir = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/CMSSW/CMSSW_7_6_3/src/AnHiMaCMG/StudyFakeRate/"
    batch[-1].inputFiles.append("{0}/{1}/{2}/tree.root".format(treeDirectory, sample[Dir], treeProdName))
    batch[-1].tree = "tree"
    batch[-1].outputDirectory = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/Histos/StudyFakeRate/MuMu_MTStudy/76X/{0}".format(sample[Name])
    batch[-1].outputFile = "fakerates_ZMuMu_MTStudy_{0}.root".format(sample[Name])
    batch[-1].histoParameters = "../histos.par"
    batch[-1].histoTag = "HistosZMuMuMT"
    batch[-1].nFilesPerJob = 1

    batch[-1].batchSystem = "lxplus"
    batch[-1].queue      = "8nm"
    batch[-1].local = True

    batch[-1].cuts = copy.copy(cuts) 
    if sample[Cut]!='': batch[-1].cuts.append(sample[Cut])

    # Fake factors
    isData = ('Data' in sample[Name])
    #batch[-1].additionalParameters['IsData'] = str(isData)
    systematics = ""
    ifake = 0
    selectedFakeFactors = dataff if isData else mcff
    for fakeFactor in selectedFakeFactors:
        systematics +=  fakeFactor.name
        systematics += ":"
    for fakeFactor in selectedFakeFactors:
        batch[-1].additionalParameters["FakeFactor.{0}.Name".format(ifake+1)]   = fakeFactor.object.Name
        batch[-1].additionalParameters["FakeFactor.{0}.File".format(ifake+1)]   = fakeFactor.object.File
        batch[-1].additionalParameters["FakeFactor.{0}.Object".format(ifake+1)] = fakeFactor.object.Object
        batch[-1].additionalParameters["FakeFactor.{0}.Type".format(ifake+1)]   = fakeFactor.object.Type
        ifake += 1
    batch[-1].additionalParameters["Systematics"] = systematics[:-1]
    #
    batch[-1].additionalParameters["NumberOfFakeFactors"] = str(ifake)

    ## parameters
    #systematics = ['Muon2PtCut_{CUT}'.format(CUT=cut) for cut in muon2PtCuts]
    #batch[-1].additionalParameters["Systematics"] = ':'.join(systematics)
    #





