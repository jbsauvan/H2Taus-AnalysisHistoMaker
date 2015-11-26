from AnhimaBatchLauncher import AnhimaBatchLauncher
import glob

batch = AnhimaBatchLauncher()
batch.name = "FakeRate_ZMuMu"
batch.exe = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/CMSSW/CMSSW_7_4_15/bin/slc6_amd64_gcc491/fakerate.exe"
batch.baseDir = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/CMSSW/CMSSW_7_4_15/src/AnHiMaCMG/StudyFakeRate/"
batch.inputFiles.extend(["/afs/cern.ch/user/s/steggema/work/public/mm/MiniAODv2/DYJetsToLL_M50_LO/H2TauTauTreeProducerMuMu/tree.root"])
batch.tree = "tree"
batch.outputDirectory = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/Histos/StudyFakeRate/ZMuMu/"
batch.outputFile = "fakerates_ZMuMu.root"
batch.histoParameters = "../histos.par"
batch.histoTag = "HistosZMuMu"
batch.nFilesPerJob = 1

batch.batchSystem = "lxplus"
batch.queue      = "8nm"
batch.local = True

### Muon cuts
batch.cuts.extend(["l1_gen_match==2","l2_gen_match==2"])
batch.cuts.extend(["l1_reliso05<0.1","l1_muonid_medium>0.5","l1_pt>19"])
batch.cuts.extend(["l2_reliso05<0.1","l2_muonid_medium>0.5","l2_pt>19"])
batch.cuts.extend(["l1_charge*l2_charge<0"])
# Tau cuts
batch.cuts.extend(["tau1_againstMuon3>1.5","tau1_againstElectronMVA5>0.5","tau1_pt>20"])
batch.cuts.extend(["tau1_decayModeFinding"])




