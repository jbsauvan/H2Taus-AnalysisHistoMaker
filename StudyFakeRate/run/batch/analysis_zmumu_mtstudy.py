from AnhimaBatchLauncher import AnhimaBatchLauncher
import glob
import os
import copy

cmssw_base = os.environ['CMSSW_BASE']

## samples
treeDirectory =  "/afs/cern.ch/user/s/steggema/work/public/mm/190116/"
treeProdName  =  "H2TauTauTreeProducerMuMu"

Name = "Name"
File = "File"
Object = "Object"
Type = "Type"
Dir  = "Dir"
Cut  = "Cut"


samples = []
samples.append({Name:"Z"           ,Dir:"DYJetsToLL_M50_LO",Cut:""})
samples.append({Name:"W"           ,Dir:"WJetsToLNu_LO"    ,Cut:""})
samples.append({Name:"TT"          ,Dir:"TT_pow_ext"       ,Cut:""})
samples.append({Name:"T_tWch"      ,Dir:"T_tWch"           ,Cut:""})
samples.append({Name:"TBar_tWch"   ,Dir:"TBar_tWch"        ,Cut:""})
samples.append({Name:"QCD"         ,Dir:"QCD_Mu15"         ,Cut:""})
#
#samples.append({Name:"ZZTo4L"      ,Dir:"ZZTo4L"           ,Cut:""}) ## FIXME: output not there
samples.append({Name:"ZZTo2L2Q"    ,Dir:"ZZTo2L2Q"         ,Cut:""})
samples.append({Name:"WZTo3L"      ,Dir:"WZTo3L"           ,Cut:""})
samples.append({Name:"WZTo2L2Q"    ,Dir:"WZTo2L2Q"         ,Cut:""})
samples.append({Name:"WZTo1L3Nu"   ,Dir:"WZTo1L3Nu"        ,Cut:""})
samples.append({Name:"WZTo1L1Nu2Q" ,Dir:"WZTo1L1Nu2Q"      ,Cut:""})
samples.append({Name:"VVTo2L2Nu"   ,Dir:"VVTo2L2Nu"        ,Cut:""})
samples.append({Name:"WWTo1L1Nu2Q" ,Dir:"WWTo1L1Nu2Q"      ,Cut:""})
#
samples.append({Name:"Data_Run15D_v4",    Dir:"SingleMuon_Run2015D_v4"            ,Cut:""})
samples.append({Name:"Data_Run15D_05Oct", Dir:"SingleMuon_Run2015D_05Oct"         ,Cut:""})

## selection
cuts = []
### Muon cuts
#cuts.extend(["l1_gen_match==2","l2_gen_match==2"])
cuts.extend(["l1_reliso05<0.1","l1_muonid_medium>0.5","l1_pt>19"])
cuts.extend(["l2_reliso05<0.1","l2_muonid_medium>0.5","l2_pt>10"])
cuts.extend(["l1_charge*l2_charge<0"])
# Tau cuts
cuts.extend(["tau1_againstMuon3>1.5","tau1_againstElectronMVA5>0.5","tau1_pt>20"])
cuts.extend(["tau1_decayModeFinding"])
# Event cuts
cuts.extend(['!veto_dilepton && !veto_thirdlepton && !veto_otherlepton'])

batch = []

for sample in samples:
    batch.append(AnhimaBatchLauncher())
    batch[-1].name = "FakeRate_ZMuMu_MTStudy_{0}".format(sample[Name])
    batch[-1].exe = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/CMSSW/CMSSW_7_4_15/bin/slc6_amd64_gcc491/fakerate_zmumu_mtstudy.exe"
    batch[-1].baseDir = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/CMSSW/CMSSW_7_4_15/src/AnHiMaCMG/StudyFakeRate/"
    batch[-1].inputFiles.append("{0}/{1}/{2}/tree.root".format(treeDirectory, sample[Dir], treeProdName))
    batch[-1].tree = "tree"
    batch[-1].outputDirectory = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/Histos/StudyFakeRate/MuMu_MTStudy/{0}".format(sample[Name])
    batch[-1].outputFile = "fakerates_ZMuMu_MTStudy_{0}.root".format(sample[Name])
    batch[-1].histoParameters = "../histos.par"
    batch[-1].histoTag = "HistosZMuMuMT"
    batch[-1].nFilesPerJob = 1

    batch[-1].batchSystem = "lxplus"
    batch[-1].queue      = "8nm"
    batch[-1].local = True

    batch[-1].cuts = copy.copy(cuts) 
    if sample[Cut]!='': batch[-1].cuts.append(sample[Cut])

    ## parameters
    #batch[-1].additionalParameters["Systematics"] = 'NoPUReweight'
    #
    batch[-1].additionalParameters['IsData'] = ('True' if 'Data' in sample[Name] else 'False')
    batch[-1].additionalParameters["PUWeightsDataFile"]  = '{CMSSW_BASE}/src/CMGTools/H2TauTau/data/data_pu_11-11-2015_75mb.root'.format(CMSSW_BASE=cmssw_base)
    batch[-1].additionalParameters["PUWeightsMCFile"]    = '{CMSSW_BASE}/src/CMGTools/H2TauTau/data/mc_true_pu.root'.format(CMSSW_BASE=cmssw_base)
    batch[-1].additionalParameters["PUWeightsDataHisto"] = 'pileup'
    batch[-1].additionalParameters["PUWeightsMCHisto"]   = 'pu_mc'




