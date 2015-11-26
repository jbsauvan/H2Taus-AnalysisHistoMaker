from AnhimaBatchLauncher import AnhimaBatchLauncher
import glob

## Samples definition
treeDirectory =  "/afs/cern.ch/work/s/steggema/public/mt/18112015/"
treeProdName  =  "H2TauTauTreeProducerTauMu"

ztt_cut = 'l2_gen_match == 5'
zl_cut  = 'l2_gen_match < 5'
zj_cut  = 'l2_gen_match == 6'


Name = "Name"
File = "File"
Histo = "Histo"
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
fakeFactorsFile = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/ComputeFakeRates/plots/FakeFactors_ZMuMu/FakeFactors_ZMuMu.root"
fakeFactors = []
fakeFactors.append({Name:"Weight_Inclusive", File:fakeFactorsFile, Histo:"FakeFactors_ZMuMu_StandardIso_InvertIso_nevents"})
fakeFactors.append({Name:"Weight_VsNVtx"   , File:fakeFactorsFile, Histo:"FakeFactors_ZMuMu_StandardIso_InvertIso_nvertices"})
fakeFactors.append({Name:"Weight_VsPt"     , File:fakeFactorsFile, Histo:"FakeFactors_ZMuMu_StandardIso_InvertIso_tau_pt"})
fakeFactors.append({Name:"Weight_VsEta"    , File:fakeFactorsFile, Histo:"FakeFactors_ZMuMu_StandardIso_InvertIso_tau_eta"})
fakeFactors.append({Name:"Weight_VsDecay"  , File:fakeFactorsFile, Histo:"FakeFactors_ZMuMu_StandardIso_InvertIso_tau_decayMode"})
fakeFactors.append({Name:"Weight_VsPdgId"  , File:fakeFactorsFile, Histo:"FakeFactors_ZMuMu_StandardIso_InvertIso_tau_pdgId"})



batch = []

for sample in samples:
    batch.append(AnhimaBatchLauncher())
    batch[-1].name = "FakeRate_MuTau_"+sample[Name]
    batch[-1].exe = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/CMSSW/CMSSW_7_4_15/bin/slc6_amd64_gcc491/fakerateapply.exe"
    batch[-1].baseDir = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/CMSSW/CMSSW_7_4_15/src/AnHiMaCMG/StudyFakeRate/"
    batch[-1].inputFiles.append("{0}/{1}/{2}/tree.root".format(treeDirectory, sample[Dir], treeProdName))
    batch[-1].tree = "tree"
    batch[-1].outputDirectory = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/Histos/StudyFakeRate/MuTau/"+sample[Name]
    batch[-1].outputFile = "fakerates_MuTau_{0}.root".format(sample[Name])
    batch[-1].histoParameters = "../histos.par"
    batch[-1].histoTag = "HistosMuTau"
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
        batch[-1].additionalParameters["FakeFactor.{0}.Histo".format(i+1)]  = fakeFactor[Histo]


