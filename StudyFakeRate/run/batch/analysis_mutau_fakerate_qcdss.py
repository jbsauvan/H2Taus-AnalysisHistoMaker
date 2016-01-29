from AnhimaBatchLauncher import AnhimaBatchLauncher
import glob

## Samples definition
treeDirectory =  "/afs/cern.ch/work/s/steggema/public/mt/151215/"
treeProdName  =  "H2TauTauTreeProducerTauMu"


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
### Old samples
# MC
#samples.append({Name:"Z"        ,Dir:"DYJetsToLL_M50_LO",Cut:""})
#samples.append({Name:"W"        ,Dir:"WJetsToLNu_LO"    ,Cut:""})
#samples.append({Name:"TT"       ,Dir:"TT_pow"           ,Cut:""})
#samples.append({Name:"T_tWch"   ,Dir:"T_tWch"           ,Cut:""})
#samples.append({Name:"TBar_tWch",Dir:"TBar_tWch"        ,Cut:""})
#samples.append({Name:"ZZ"       ,Dir:"ZZp8"             ,Cut:""})
#samples.append({Name:"WZ"       ,Dir:"WZ"               ,Cut:""})
#samples.append({Name:"WW"       ,Dir:"WWTo2L2Nu"        ,Cut:""})
#samples.append({Name:"QCD"      ,Dir:"QCD_Mu15"         ,Cut:""})
# Data
#samples.append({Name:"Data_Run15D_05Oct", Dir:"SingleMuon_Run2015D_05Oct"         ,Cut:""})
#samples.append({Name:"Data_Run15D_v4",    Dir:"SingleMuon_Run2015D_v4"            ,Cut:""})


## Definition of fake factors
#fakeFactorsFile1D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_ZMuMu_1D/FakeFactors_ZMuMu_1D.root"
#fakeFactorsFile2D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_ZMuMu_2D/FakeFactors_ZMuMu_2D.root"
#fakeFactors = []
### !IsoMedium -> IsoMedium
#fakeFactors.append({Name:"Weight_Iso_Medium_VsPtDecay", File:fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"})



batch = []

for sample in samples:
    batch.append(AnhimaBatchLauncher())
    batch[-1].name = "FakeRate_MuTau_QCDSS_"+sample[Name]
    batch[-1].exe = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/CMSSW/CMSSW_7_4_15/bin/slc6_amd64_gcc491/fakerate_mutau_qcdss.exe"
    batch[-1].baseDir = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/CMSSW/CMSSW_7_4_15/src/AnHiMaCMG/StudyFakeRate/"
    batch[-1].inputFiles.append("{0}/{1}/{2}/tree.root".format(treeDirectory, sample[Dir], treeProdName))
    batch[-1].tree = "tree"
    batch[-1].outputDirectory = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/Histos/StudyFakeRate/MuTau_FakeRate_QCDSS/"+sample[Name]
    batch[-1].outputFile = "fakerates_MuTau_QCDSS_{0}.root".format(sample[Name])
    batch[-1].histoParameters = "../histos.par"
    batch[-1].histoTag = "HistosZMuMu"
    batch[-1].nFilesPerJob = 1

    batch[-1].batchSystem = "lxplus"
    batch[-1].queue      = "8nm"
    batch[-1].local      = True

    # Muon cuts
    #batch[-1].cuts.extend(["l1_reliso05<0.1","l1_muonid_medium>0.5","l1_pt>19"])
    batch[-1].cuts.extend(["l1_reliso05>0.05","l1_muonid_medium>0.5","l1_pt>19"]) ## muon anti-isolation
    # Tau cuts
    batch[-1].cuts.extend(["l2_againstMuon3>1.5","l2_againstElectronMVA5>0.5"])
    batch[-1].cuts.extend(["veto_dilepton<0.5", "veto_thirdlepton<0.5", "veto_otherlepton<0.5"])
    batch[-1].cuts.extend(["l2_decayModeFinding"])
    batch[-1].cuts.extend(["l2_pt>20"])
    #batch[-1].cuts.extend(["l2_gen_match==6"])
    # Mu-Tau cuts
    #batch[-1].cuts.extend(["l1_charge*l2_charge<0"])
    # Sample specific cuts
    if sample[Cut]!="":
        batch[-1].cuts.append(sample[Cut])

    # Fake factors
    #systematics = ""
    #for fakeFactor in fakeFactors:
        #systematics += fakeFactor[Name]
        #systematics += ":"
    #batch[-1].additionalParameters["Systematics"] = systematics[:-1]
    ##
    #batch[-1].additionalParameters["NumberOfFakeFactors"] = str(len(fakeFactors))
    #for i,fakeFactor in enumerate(fakeFactors):
        #batch[-1].additionalParameters["FakeFactor.{0}.Name".format(i+1)]   = fakeFactor[Name]
        #batch[-1].additionalParameters["FakeFactor.{0}.File".format(i+1)]   = fakeFactor[File]
        #batch[-1].additionalParameters["FakeFactor.{0}.Object".format(i+1)] = fakeFactor[Object]
        #batch[-1].additionalParameters["FakeFactor.{0}.Type".format(i+1)]   = fakeFactor[Type]


