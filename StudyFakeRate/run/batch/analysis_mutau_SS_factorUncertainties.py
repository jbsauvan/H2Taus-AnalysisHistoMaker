from AnhimaBatchLauncher import AnhimaBatchLauncher
#from FakeFactorsLocationsWithUncertainties import fakeFactorsMC,fakeFactorsData,fractionsW,fractionsTT,fractionsVV,fractionsZJ,fractionsQCD,highMTCorrection,nonClosures, binByBinShiftsData
import listCombinedSSFakeFactors
import glob

## Samples definition
treeDirectory =  "/afs/cern.ch/work/j/jsauvan/public/HTauTau/Trees/mt/151215/"
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
#samples.append({Name:"ZJ"          ,Dir:"DYJetsToLL_M50_LO",Cut:zj_cut})
#samples.append({Name:"W"           ,Dir:"WJetsToLNu_LO"    ,Cut:fake_cut})
#samples.append({Name:"TT"          ,Dir:"TT_pow_ext"       ,Cut:fake_cut})
#samples.append({Name:"T_tWch"      ,Dir:"T_tWch"           ,Cut:fake_cut})
#samples.append({Name:"TBar_tWch"   ,Dir:"TBar_tWch"        ,Cut:fake_cut})
#samples.append({Name:"QCD"         ,Dir:"QCD_Mu15"         ,Cut:fake_cut})
###
##samples.append({Name:"ZZTo4L"      ,Dir:"ZZTo4L"           ,Cut:""}) ## FIXME: output not there
#samples.append({Name:"ZZTo2L2Q"    ,Dir:"ZZTo2L2Q"         ,Cut:fake_cut})
#samples.append({Name:"WZTo3L"      ,Dir:"WZTo3L"           ,Cut:fake_cut})
#samples.append({Name:"WZTo2L2Q"    ,Dir:"WZTo2L2Q"         ,Cut:fake_cut})
#samples.append({Name:"WZTo1L3Nu"   ,Dir:"WZTo1L3Nu"        ,Cut:fake_cut})
#samples.append({Name:"WZTo1L1Nu2Q" ,Dir:"WZTo1L1Nu2Q"      ,Cut:fake_cut})
#samples.append({Name:"VVTo2L2Nu"   ,Dir:"VVTo2L2Nu"        ,Cut:fake_cut})
#samples.append({Name:"WWTo1L1Nu2Q" ,Dir:"WWTo1L1Nu2Q"      ,Cut:fake_cut})
#

## Non fake backgrounds
samples.append({Name:"W_L"           ,Dir:"WJetsToLNu_LO"    , Cut:lepton_cut}) ## almost no non-fakes
samples.append({Name:"ZTT"           ,Dir:"DYJetsToLL_M50_LO", Cut:ztt_cut})
samples.append({Name:"ZL"            ,Dir:"DYJetsToLL_M50_LO", Cut:zl_cut})
samples.append({Name:"TT_L"          ,Dir:"TT_pow_ext"       , Cut:lepton_cut})
samples.append({Name:"T_tWch_L"      ,Dir:"T_tWch"           , Cut:lepton_cut})
samples.append({Name:"TBar_tWch_L"   ,Dir:"TBar_tWch"        , Cut:lepton_cut})
samples.append({Name:"ZZTo2L2Q_L"    ,Dir:"ZZTo2L2Q"       , Cut:lepton_cut})
samples.append({Name:"WZTo3L_L"      ,Dir:"WZTo3L"         , Cut:lepton_cut})
samples.append({Name:"WZTo2L2Q_L"    ,Dir:"WZTo2L2Q"       , Cut:lepton_cut})
samples.append({Name:"WZTo1L3Nu_L"   ,Dir:"WZTo1L3Nu"      , Cut:lepton_cut})
samples.append({Name:"WZTo1L1Nu2Q_L" ,Dir:"WZTo1L1Nu2Q"    , Cut:lepton_cut})
samples.append({Name:"VVTo2L2Nu_L"   ,Dir:"VVTo2L2Nu"      , Cut:lepton_cut})
samples.append({Name:"WWTo1L1Nu2Q_L" ,Dir:"WWTo1L1Nu2Q"    , Cut:lepton_cut})
## Data
samples.append({Name:"Data_Run15D_v4",    Dir:"SingleMuon_Run2015D_v4"            ,Cut:""})
samples.append({Name:"Data_Run15D_05Oct", Dir:"SingleMuon_Run2015D_05Oct"         ,Cut:""})

### Old samples                                                   
#samples.append({Name:"ZL"       ,Dir:"DYJetsToLL_M50_LO",Cut:zl_cut})
##
#samples.append({Name:"ZJ"       ,Dir:"DYJetsToLL_M50_LO",Cut:""})
#samples.append({Name:"W"        ,Dir:"WJetsToLNu_LO"    ,Cut:""})
#samples.append({Name:"TT"       ,Dir:"TT_pow"           ,Cut:""})
#samples.append({Name:"T_tWch"   ,Dir:"T_tWch"           ,Cut:""})
#samples.append({Name:"TBar_tWch",Dir:"TBar_tWch"        ,Cut:""})
#samples.append({Name:"ZZ"       ,Dir:"ZZp8"             ,Cut:""})
#samples.append({Name:"WZ"       ,Dir:"WZ"               ,Cut:""})
#samples.append({Name:"WW"       ,Dir:"WWTo2L2Nu"        ,Cut:""})
#samples.append({Name:"QCD"      ,Dir:"QCD_Mu15"         ,Cut:""})


batch = []


for sample in samples:
    batch.append(AnhimaBatchLauncher())
    batch[-1].name = "FakeRate_MuTau_"+sample[Name]
    batch[-1].exe = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/CMSSW/CMSSW_7_4_15/bin/slc6_amd64_gcc491/fakerateapply.exe"
    batch[-1].baseDir = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/CMSSW/CMSSW_7_4_15/src/AnHiMaCMG/StudyFakeRate/"
    batch[-1].inputFiles.append("{0}/{1}/{2}/tree.root".format(treeDirectory, sample[Dir], treeProdName))
    batch[-1].tree = "tree"
    batch[-1].outputDirectory = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/Histos/StudyFakeRate/MuTau/FakeFactorUncertainties_SS/{SAMPLE}".format(SAMPLE=sample[Name])
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
    batch[-1].cuts.extend(["l2_againstMuon3>1.5","l2_againstElectronMVA5>0.5"])
    batch[-1].cuts.extend(["veto_dilepton<0.5", "veto_thirdlepton<0.5", "veto_otherlepton<0.5"])
    batch[-1].cuts.extend(["l2_decayModeFinding"])
    batch[-1].cuts.extend(["l2_pt>20"])
    # Mu-Tau cuts
    batch[-1].cuts.extend(["l1_charge*l2_charge>0"])
    # Remove events with bad missing ET
    batch[-1].cuts.extend(['!(met_pt < 0.15 && met_phi > 0. && met_phi < 1.8)'])
    # Sample specific cuts
    if sample[Cut]!="":
        batch[-1].cuts.append(sample[Cut])

    # Fake factors
    isData = ('Data' in sample[Name])
    #batch[-1].additionalParameters['IsData'] = str(isData)
    systematics = ""
    ifake = 0
    selectedFakeFactors = listCombinedSSFakeFactors.allFakeFactors
    sysFakeFactors = listCombinedSSFakeFactors.combinedFakeFactor.systematics
    systematics +=  listCombinedSSFakeFactors.combinedFakeFactor.name
    systematics += ":"
    for syss in sysFakeFactors.values():
        for sys in syss:
            systematics += sys.name
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



