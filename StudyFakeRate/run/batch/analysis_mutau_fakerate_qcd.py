from AnhimaBatchLauncher import AnhimaBatchLauncher
import glob
import os

cmssw_base = os.environ['CMSSW_BASE']
scram = os.environ['SCRAM_ARCH']

## Samples definition
treeDirectory =  "/afs/cern.ch/work/s/steggema/public/mt/180216"
treeProdName  =  "H2TauTauTreeProducerTauMu"


Name = "Name"
File = "File"
Object = "Object"
Type = "Type"
Dir  = "Dir"
Cut  = "Cut"

samples = []
samples.append({Name:"Z"           ,Dir:"DYJetsToLL_M50_LO",Cut:""})
samples.append({Name:"Z1"          ,Dir:"DY1JetsToLL_M50_LO",Cut:""})
samples.append({Name:"Z2"          ,Dir:"DY2JetsToLL_M50_LO",Cut:""})
samples.append({Name:"Z3"          ,Dir:"DY3JetsToLL_M50_LO",Cut:""})
samples.append({Name:"Z4"          ,Dir:"DY4JetsToLL_M50_LO",Cut:""})
samples.append({Name:"W"           ,Dir:"WJetsToLNu_LO"     ,Cut:""})
samples.append({Name:"W1"          ,Dir:"W1JetsToLNu_LO"    ,Cut:""})
samples.append({Name:"W4"          ,Dir:"W4JetsToLNu_LO"    ,Cut:""})
samples.append({Name:"TT"          ,Dir:"TT_pow_ext"       ,Cut:""})
samples.append({Name:"T_tWch"      ,Dir:"T_tWch"           ,Cut:""})
samples.append({Name:"TBar_tWch"   ,Dir:"TBar_tWch"        ,Cut:""})
#samples.append({Name:"QCD"         ,Dir:"QCD_Mu15"         ,Cut:""})
#
samples.append({Name:"ZZTo4L"      ,Dir:"ZZTo4L"           ,Cut:""}) 
samples.append({Name:"ZZTo2L2Q"    ,Dir:"ZZTo2L2Q"         ,Cut:""})
samples.append({Name:"WZTo3LNu"    ,Dir:"WZTo3LNu"         ,Cut:""})
samples.append({Name:"WZTo2L2Q"    ,Dir:"WZTo2L2Q"         ,Cut:""})
samples.append({Name:"WZTo1L3Nu"   ,Dir:"WZTo1L3Nu"        ,Cut:""})
samples.append({Name:"WZTo1L1Nu2Q" ,Dir:"WZTo1L1Nu2Q"      ,Cut:""})
#samples.append({Name:"VVTo2L2Nu"   ,Dir:"VVTo2L2Nu"        ,Cut:""})
samples.append({Name:"WWTo1L1Nu2Q" ,Dir:"WWTo1L1Nu2Q"      ,Cut:""})
#
samples.append({Name:"Data_Run15D_16Dec",    Dir:"SingleMuon_Run2015D_16Dec"            ,Cut:""})

batch = []

for sample in samples:
    batch.append(AnhimaBatchLauncher())
    batch[-1].name = "FakeRate_MuTau_QCD_"+sample[Name]
    batch[-1].exe = "{CMSSW}/bin/{SCRAM}/fakerate_mutau_qcdss.exe".format(CMSSW=cmssw_base,SCRAM=scram)
    batch[-1].baseDir = "{CMSSW}/src/AnHiMaCMG/StudyFakeRate/".format(CMSSW=cmssw_base)
    batch[-1].inputFiles.append("{0}/{1}/{2}/tree.root".format(treeDirectory, sample[Dir], treeProdName))
    batch[-1].tree = "tree"
    batch[-1].outputDirectory = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/Histos/StudyFakeRate/76X/MuTau_FakeRate_QCD/"+sample[Name]
    batch[-1].outputFile = "fakerates_MuTau_QCD_{0}.root".format(sample[Name])
    batch[-1].histoParameters = "../histos.par"
    batch[-1].histoTag = "HistosQCDOSSS"
    batch[-1].nFilesPerJob = 1

    batch[-1].batchSystem = "lxplus"
    batch[-1].queue      = "8nm"
    batch[-1].local      = True

    # Muon cuts
    #batch[-1].cuts.extend(["l1_reliso05<0.1","l1_muonid_medium>0.5","l1_pt>19"])
    #batch[-1].cuts.extend(["l1_reliso05>0.05","l1_muonid_medium>0.5","l1_pt>19"]) ## muon anti-isolation
    #batch[-1].cuts.extend(["l1_reliso05>0.12","l1_muonid_medium>0.5","l1_pt>19"]) ## new muon anti-isolation
    #batch[-1].cuts.extend(["l1_reliso05>0.15","l1_muonid_medium>0.5","l1_pt>19"]) ## new muon anti-isolation (18/03/2016)
    batch[-1].cuts.extend(["l1_reliso05>0.05","l1_muonid_medium>0.5","l1_pt>19"]) ## both anti-isolation and medium isolation (05/04/2016)
    # Tau cuts
    batch[-1].cuts.extend(["l2_againstMuon3>1.5","l2_againstElectronMVA6>0.5"])
    batch[-1].cuts.extend(["veto_dilepton<0.5", "veto_thirdlepton<0.5", "veto_otherlepton<0.5"])
    batch[-1].cuts.extend(["l2_decayModeFinding"])
    batch[-1].cuts.extend(["l2_pt>20"])
    #batch[-1].cuts.extend(["l2_gen_match==6"])
    # Mu-Tau cuts
    #batch[-1].cuts.extend(["l1_charge*l2_charge<0"])
    # Remove events with bad missing ET
    batch[-1].cuts.extend(['!(met_pt < 0.15 && met_phi > 0. && met_phi < 1.8)'])
    # Sample specific cuts
    if sample[Cut]!="":
        batch[-1].cuts.append(sample[Cut])



