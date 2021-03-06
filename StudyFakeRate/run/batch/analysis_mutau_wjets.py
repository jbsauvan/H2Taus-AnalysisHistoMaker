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
Object = "Object"
Type = "Type"
Dir  = "Dir"
Cut  = "Cut"

samples = []
samples.append({Name:"W"        ,Dir:"WJetsToLNu_LO"    ,Cut:""})


## Definition of fake factors
fakeFactorsFile1D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_ZMuMu_1D/FakeFactors_ZMuMu_1D.root"
fakeFactorsFile2D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_ZMuMu_2D/FakeFactors_ZMuMu_2D.root"
fakeFactors = []
## !IsoMedium -> IsoMedium
fakeFactors.append({Name:"Weight_Iso_Medium_Inclusive", File:fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_nevents"})
fakeFactors.append({Name:"Weight_Iso_Medium_VsPt"     , File:fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_tau_pt"})
fakeFactors.append({Name:"Weight_Iso_Medium_VsDecay"  , File:fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_tau_decayMode"})
fakeFactors.append({Name:"Weight_Iso_Medium_VsPdgId"  , File:fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_tau_pdgId"})
fakeFactors.append({Name:"Weight_Iso_Medium_VsPtDecay", File:fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"})
fakeFactors.append({Name:"Weight_Iso_Medium_VsPtPdgId", File:fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_mergedPdgId"})



batch = []

for sample in samples:
    batch.append(AnhimaBatchLauncher())
    batch[-1].name = "FakeRate_MuTau_WJets_"+sample[Name]
    batch[-1].exe = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/CMSSW/CMSSW_7_4_15/bin/slc6_amd64_gcc491/fakeratewjets.exe"
    batch[-1].baseDir = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/CMSSW/CMSSW_7_4_15/src/AnHiMaCMG/StudyFakeRate/"
    batch[-1].inputFiles.append("{0}/{1}/{2}/tree.root".format(treeDirectory, sample[Dir], treeProdName))
    batch[-1].tree = "tree"
    batch[-1].outputDirectory = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/Histos/StudyFakeRate/MuTau_WJets/"+sample[Name]
    batch[-1].outputFile = "fakerates_MuTau_WJets_{0}.root".format(sample[Name])
    batch[-1].histoParameters = "../histos.par"
    batch[-1].histoTag = "HistosMuTauWJets"
    batch[-1].nFilesPerJob = 1

    batch[-1].batchSystem = "lxplus"
    batch[-1].queue      = "8nm"
    batch[-1].local      = True

    # Muon cuts
    #batch[-1].cuts.extend(["l1_reliso05<0.1","l1_muonid_medium>0.5","l1_pt>19"])
    batch[-1].cuts.extend(["l1_muonid_medium>0.5","l1_pt>19"]) # TMP: used to study the impact of muon isolation on fake factor mT-dependency
    # Tau cuts
    batch[-1].cuts.extend(["l2_againstMuon3>1.5","l2_againstElectronMVA5>0.5","l2_decayModeFinding"])
    batch[-1].cuts.extend(["veto_dilepton<0.5", "veto_thirdlepton<0.5", "veto_otherlepton<0.5"])
    batch[-1].cuts.extend(["l2_decayModeFinding"])
    batch[-1].cuts.extend(["l2_pt>20"])
    batch[-1].cuts.extend(["l2_gen_match==6"])
    batch[-1].cuts.extend(["genmet_pt>20"]) # TMP: used to have the same selection as Z+jets
    # Mu-Tau cuts
    #batch[-1].cuts.extend(["l1_charge*l2_charge<0"])
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


