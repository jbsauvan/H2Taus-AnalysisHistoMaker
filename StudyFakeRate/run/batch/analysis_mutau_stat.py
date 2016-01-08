from AnhimaBatchLauncher import AnhimaBatchLauncher
import glob
import copy

## Samples definition
treeDirectory =  "/afs/cern.ch/work/s/steggema/public/mt/18112015/"
treeProdName  =  "H2TauTauTreeProducerTauMu"

ztt_cut = 'l2_gen_match == 5'
zl_cut  = 'l2_gen_match < 5'
zj_cut  = 'l2_gen_match == 6'


Name = "Name"
File = "File"
Object = "Object"
Type = "Type"
Dir  = "Dir"
Cut  = "Cut"

samples = []
#samples.append({Name:"ZL"       ,Dir:"DYJetsToLL_M50_LO",Cut:zl_cut})
samples.append({Name:"ZJ"       ,Dir:"DYJetsToLL_M50_LO",Cut:""})
samples.append({Name:"W"        ,Dir:"WJetsToLNu_LO"    ,Cut:""})
samples.append({Name:"TT"       ,Dir:"TT_pow"           ,Cut:""})
samples.append({Name:"T_tWch"   ,Dir:"T_tWch"           ,Cut:""})
samples.append({Name:"TBar_tWch",Dir:"TBar_tWch"        ,Cut:""})
samples.append({Name:"ZZ"       ,Dir:"ZZp8"             ,Cut:""})
samples.append({Name:"WZ"       ,Dir:"WZ"               ,Cut:""})
samples.append({Name:"WW"       ,Dir:"WWTo2L2Nu"        ,Cut:""})
samples.append({Name:"QCD"      ,Dir:"QCD_Mu15"         ,Cut:""})


## Definition of fake factors
fakeFactorsFile1D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_ZMuMu_1D/FakeFactors_ZMuMu_1D.root"
fakeFactorsFile2D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_ZMuMu_2D/FakeFactors_ZMuMu_2D.root"
fakeFactors = []
## !IsoMedium -> IsoMedium
fakeFactors.append({Name:"Weight_Iso_Medium_Inclusive", File:fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_nevents"})
fakeFactors.append({Name:"Weight_Iso_Medium_VsPt"     , File:fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_tau_pt"})
fakeFactors.append({Name:"Weight_Iso_Medium_VsDecay"  , File:fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_tau_decayMode"})
fakeFactors.append({Name:"Weight_Iso_Medium_VsPtDecay", File:fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"})

## Apply fake factors with random fluctuations + Up/Down fake factors
fakeFactorsFluctuate = []
for fakeFactor in fakeFactors:
    for i in xrange(100):
        ffCopy = copy.deepcopy(fakeFactor)
        ffCopy[Name] += "_Fluctuate{}".format(i)
        fakeFactorsFluctuate.append(ffCopy)
    #
    ffUp = copy.deepcopy(fakeFactor)
    ffUp[Name] += "_Up"
    fakeFactorsFluctuate.append(ffUp)
    #
    ffDown = copy.deepcopy(fakeFactor)
    ffDown[Name] += "_Down"
    fakeFactorsFluctuate.append(ffDown)
fakeFactors.extend(fakeFactorsFluctuate)


batch = []

for sample in samples:
    batch.append(AnhimaBatchLauncher())
    batch[-1].name = "FakeRate_MuTau_Stat_"+sample[Name]
    batch[-1].exe = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/CMSSW/CMSSW_7_4_15/bin/slc6_amd64_gcc491/fakeratestat.exe"
    batch[-1].baseDir = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/CMSSW/CMSSW_7_4_15/src/AnHiMaCMG/StudyFakeRate/"
    batch[-1].inputFiles.append("{0}/{1}/{2}/tree.root".format(treeDirectory, sample[Dir], treeProdName))
    batch[-1].tree = "tree"
    batch[-1].outputDirectory = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/Histos/StudyFakeRate/MuTau_Stat/"+sample[Name]
    batch[-1].outputFile = "fakerates_MuTau_Stat_{0}.root".format(sample[Name])
    batch[-1].histoParameters = "../histos.par"
    batch[-1].histoTag = "HistosMuTauStat"
    batch[-1].nFilesPerJob = 1

    batch[-1].batchSystem = "lxplus"
    batch[-1].queue      = "8nm"
    batch[-1].local      = True

    # Muon cuts
    batch[-1].cuts.extend(["l1_reliso05<0.1","l1_muonid_medium>0.5","l1_pt>19"])
    # Tau cuts
    batch[-1].cuts.extend(["l2_againstMuon3>1.5","l2_againstElectronMVA5>0.5","l2_decayModeFinding"])
    batch[-1].cuts.extend(["veto_dilepton<0.5", "veto_thirdlepton<0.5", "veto_otherlepton<0.5"])
    batch[-1].cuts.extend(["l2_decayModeFinding"])
    batch[-1].cuts.extend(["l2_pt>20"])
    # Mu-Tau cuts
    batch[-1].cuts.extend(["l1_charge*l2_charge<0"])
    # Sample specific cuts
    if sample[Cut]!="":
        batch[-1].cuts.append(sample[Cut])

    # Fake factors
    systematics = ""
    for fakeFactor in fakeFactors:
        systematics += fakeFactor[Name]
        systematics += ":"
    batch[-1].additionalParameters["Systematics"] = systematics[:-1]
    #
    batch[-1].additionalParameters["NumberOfFakeFactors"] = str(len(fakeFactors))
    for i,fakeFactor in enumerate(fakeFactors):
        batch[-1].additionalParameters["FakeFactor.{0}.Name".format(i+1)]   = fakeFactor[Name]
        batch[-1].additionalParameters["FakeFactor.{0}.File".format(i+1)]   = fakeFactor[File]
        batch[-1].additionalParameters["FakeFactor.{0}.Object".format(i+1)] = fakeFactor[Object]
        batch[-1].additionalParameters["FakeFactor.{0}.Type".format(i+1)]   = fakeFactor[Type]


