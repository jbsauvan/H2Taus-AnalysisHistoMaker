from AnhimaBatchLauncher import AnhimaBatchLauncher
import glob
import os

cmssw_base = os.environ['CMSSW_BASE']
scram = os.environ['SCRAM_ARCH']

## Samples definition
treeDirectory =  "/afs/cern.ch/work/s/steggema/public/mt/070416/TauMuSVFitMC/"
treeProdName  =  "H2TauTauTreeProducerTauMu"



ztt_cut = 'l2_gen_match == 5'
zl_cut  = 'l2_gen_match < 5'
zj_cut  = 'l2_gen_match == 6'
lepton_cut  = 'l2_gen_match < 6'
fake_cut  = 'l2_gen_match == 6'


Name = "Name"
File = "File"
Object = "Object"
Type = "Type"
Dir  = "Dir"
Cut  = "Cut"

samples = []
## Non fake backgrounds
samples.append({Name:"W_L"           ,Dir:"WJetsToLNu_LO"     ,Cut:lepton_cut})
samples.append({Name:"W1_L"          ,Dir:"W1JetsToLNu_LO"    ,Cut:lepton_cut})
samples.append({Name:"W2_L"          ,Dir:"W2JetsToLNu_LO"    ,Cut:lepton_cut})
samples.append({Name:"W3_L"          ,Dir:"W3JetsToLNu_LO"    ,Cut:lepton_cut})
samples.append({Name:"W4_L"          ,Dir:"W4JetsToLNu_LO"    ,Cut:lepton_cut})
samples.append({Name:"ZTT"           ,Dir:"DYJetsToLL_M50_LO",Cut:ztt_cut})
samples.append({Name:"Z1TT"          ,Dir:"DY1JetsToLL_M50_LO",Cut:ztt_cut})
samples.append({Name:"Z2TT"          ,Dir:"DY2JetsToLL_M50_LO",Cut:ztt_cut})
samples.append({Name:"Z3TT"          ,Dir:"DY3JetsToLL_M50_LO",Cut:ztt_cut})
samples.append({Name:"Z4TT"          ,Dir:"DY4JetsToLL_M50_LO",Cut:ztt_cut})
samples.append({Name:"ZL"           ,Dir:"DYJetsToLL_M50_LO",Cut:zl_cut})
samples.append({Name:"Z1L"          ,Dir:"DY1JetsToLL_M50_LO",Cut:zl_cut})
samples.append({Name:"Z2L"          ,Dir:"DY2JetsToLL_M50_LO",Cut:zl_cut})
samples.append({Name:"Z3L"          ,Dir:"DY3JetsToLL_M50_LO",Cut:zl_cut})
samples.append({Name:"Z4L"          ,Dir:"DY4JetsToLL_M50_LO",Cut:zl_cut})
samples.append({Name:"TT_L"          ,Dir:"TT_pow_ext3"       ,Cut:lepton_cut}) 
samples.append({Name:"T_tWch_L"      ,Dir:"T_tWch"           ,Cut:lepton_cut})
samples.append({Name:"TBar_tWch_L"   ,Dir:"TBar_tWch"        ,Cut:lepton_cut})
## ?? TBarToLeptons_tch_powheg, TToLeptons_tch_powheg 
samples.append({Name:"ZZTo4L_L"      ,Dir:"ZZTo4L"           ,Cut:lepton_cut}) 
samples.append({Name:"ZZTo2L2Q_L"    ,Dir:"ZZTo2L2Q"         ,Cut:lepton_cut})
samples.append({Name:"WZTo3LNu_L"    ,Dir:"WZTo3LNu_amcatnlo",Cut:lepton_cut})
samples.append({Name:"WZTo2L2Q_L"    ,Dir:"WZTo2L2Q"         ,Cut:lepton_cut})
samples.append({Name:"WZTo1L3Nu_L"   ,Dir:"WZTo1L3Nu"        ,Cut:lepton_cut})
samples.append({Name:"WZTo1L1Nu2Q_L" ,Dir:"WZTo1L1Nu2Q"      ,Cut:lepton_cut})
samples.append({Name:"VVTo2L2Nu_L"   ,Dir:"VVTo2L2Nu"        ,Cut:lepton_cut})
samples.append({Name:"WWTo1L1Nu2Q_L" ,Dir:"WWTo1L1Nu2Q"      ,Cut:lepton_cut})
# Data
samples.append({Name:"Data_Run15D_16Dec",    Dir:"SingleMuon_Run2015D_16Dec"            ,Cut:""})


batch = []


for sample in samples:
    batch.append(AnhimaBatchLauncher())
    batch[-1].name = "FakeRate_MuTau_"+sample[Name]
    batch[-1].exe = "{CMSSW}/bin/{SCRAM}/fakerateapply.exe".format(CMSSW=cmssw_base,SCRAM=scram)
    batch[-1].baseDir = "{CMSSW}/src/AnHiMaCMG/StudyFakeRate/".format(CMSSW=cmssw_base)
    batch[-1].inputFiles.append("{0}/{1}/{2}/tree.root".format(treeDirectory, sample[Dir], treeProdName))
    batch[-1].tree = "tree"
    batch[-1].outputDirectory = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/Histos/StudyFakeRate/76X/MuTau/FakeFactorUncertainties/{SAMPLE}".format(SAMPLE=sample[Name])
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
    batch[-1].cuts.extend(["l2_againstMuon3>1.5","l2_againstElectronMVA6>0.5"])
    batch[-1].cuts.extend(["veto_dilepton<0.5", "veto_thirdlepton<0.5", "veto_otherlepton<0.5"])
    batch[-1].cuts.extend(["l2_decayModeFinding"])
    batch[-1].cuts.extend(["l2_pt>20"])
    # Mu-Tau cuts
    batch[-1].cuts.extend(["l1_charge*l2_charge<0"])
    # Remove events with bad missing ET
    batch[-1].cuts.extend(['!(met_pt < 0.15 && met_phi > 0. && met_phi < 1.8)'])
    # Sample specific cuts
    if sample[Cut]!="":
        batch[-1].cuts.append(sample[Cut])

    # Fake factors
    fakeFactorFile = '/afs/cern.ch/user/j/jsauvan/public/Htautau/FakeRate/20160425/fakeFactors_20160425.root'
    fakeFactors = {
        'ff_comb':['', 'ff_qcd_up', 'ff_qcd_down', 'ff_w_up', 'ff_w_down', 'ff_tt_up', 'ff_tt_down']
    }
    ifake = 0
    systematics = ''
    for fakeFactor, sys in fakeFactors.items():
        for s in sys:
            if s!='': systematics += fakeFactor+'__'+s
            else: systematics += fakeFactor
            systematics += ':'
    for fakeFactor,sys in fakeFactors.items():
        batch[-1].additionalParameters["FakeFactor.{0}.Name".format(ifake+1)]   = fakeFactor
        batch[-1].additionalParameters["FakeFactor.{0}.File".format(ifake+1)]   = fakeFactorFile
        batch[-1].additionalParameters["FakeFactor.{0}.Object".format(ifake+1)] = fakeFactor
        ifake += 1
    batch[-1].additionalParameters["Systematics"] = systematics[:-1]
    #
    batch[-1].additionalParameters["NumberOfFakeFactors"] = str(ifake)



