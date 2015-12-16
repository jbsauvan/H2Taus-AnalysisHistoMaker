from AnhimaBatchLauncher import AnhimaBatchLauncher
import glob

## Samples definition
treeDirectory =  "/afs/cern.ch/work/s/steggema/public/mt/18112015/"
treeProdName  =  "H2TauTauTreeProducerTauMu"

#ztt_cut = 'l2_gen_match == 5'
#zl_cut  = 'l2_gen_match < 5'
#zj_cut  = 'l2_gen_match == 6'


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
#fakeFactorsFile1D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_ZMuMu_1D/FakeFactors_ZMuMu_1D.root"
fakeFactorsFile2D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_ZMuMu_2D/FakeFactors_ZMuMu_2D.root"
fakeFactors = []
## IsoRaw > 1.5 GeV -> IsoRaw < 1.5 GeV
#fakeFactors.append({Name:"Weight_IsoRaw_1_5_Inclusive", File:fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_IsoRaw_1_5_InvertIsoRaw_1_5_nevents"})
#fakeFactors.append({Name:"Weight_IsoRaw_1_5_VsNVtx"   , File:fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_IsoRaw_1_5_InvertIsoRaw_1_5_nvertices"})
#fakeFactors.append({Name:"Weight_IsoRaw_1_5_VsPt"     , File:fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_pt"})
#fakeFactors.append({Name:"Weight_IsoRaw_1_5_VsEta"    , File:fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_eta"})
#fakeFactors.append({Name:"Weight_IsoRaw_1_5_VsDecay"  , File:fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_decayMode"})
#fakeFactors.append({Name:"Weight_IsoRaw_1_5_VsPdgId"  , File:fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_pdgId"})
#fakeFactors.append({Name:"Weight_IsoRaw_1_5_VsPtEta"  , File:fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_pt_vs_eta"})
fakeFactors.append({Name:"Weight_IsoRaw_1_5_VsPtDecay", File:fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_pt_vs_decayMode"})
#fakeFactors.append({Name:"Weight_IsoRaw_1_5_VsPtPdgId", File:fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_pt_vs_mergedPdgId"})
## !IsoMedium -> IsoMedium
#fakeFactors.append({Name:"Weight_Iso_Medium_Inclusive", File:fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_nevents"})
#fakeFactors.append({Name:"Weight_Iso_Medium_VsNVtx"   , File:fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_nvertices"})
#fakeFactors.append({Name:"Weight_Iso_Medium_VsPt"     , File:fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_tau_pt"})
#fakeFactors.append({Name:"Weight_Iso_Medium_VsEta"    , File:fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_tau_eta"})
#fakeFactors.append({Name:"Weight_Iso_Medium_VsDecay"  , File:fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_tau_decayMode"})
#fakeFactors.append({Name:"Weight_Iso_Medium_VsPdgId"  , File:fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_tau_pdgId"})
#fakeFactors.append({Name:"Weight_Iso_Medium_VsPtEta"  , File:fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_eta"})
fakeFactors.append({Name:"Weight_Iso_Medium_VsPtDecay", File:fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"})
#fakeFactors.append({Name:"Weight_Iso_Medium_VsPtPdgId", File:fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_mergedPdgId"})
## !IsoMedium (with the non-inverted strip pT cut) -> IsoMedium
fakeFactors.append({Name:"Weight_Iso_Medium_InvertRawOnly_VsPtDecay", File:fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_Iso_Medium_InvertIso_Medium_RawOnly_tau_pt_vs_decayMode"})



batch = []

for sample in samples:
    batch.append(AnhimaBatchLauncher())
    batch[-1].name = "Polarization_Background_"+sample[Name]
    batch[-1].exe = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/CMSSW/CMSSW_7_4_15/bin/slc6_amd64_gcc491/polarization_background.exe"
    batch[-1].baseDir = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/CMSSW/CMSSW_7_4_15/src/AnHiMaCMG/TauPolarization/"
    batch[-1].inputFiles.append("{0}/{1}/{2}/tree.root".format(treeDirectory, sample[Dir], treeProdName))
    batch[-1].tree = "tree"
    batch[-1].outputDirectory = "/afs/cern.ch/work/j/jsauvan/Projects/Htautau_Run2/Histos/TauPolarization/Background/"+sample[Name]
    batch[-1].outputFile = "polarization_background_{0}.root".format(sample[Name])
    batch[-1].histoParameters = "../histos.par"
    batch[-1].histoTag = "HistosBackground"
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
    # M_vis cuts
    batch[-1].cuts.extend(["(mvis>40. && mvis<90.)"])
    # Remove events at MET=0
    batch[-1].cuts.extend(["!(pfmet_pt < 0.2 && pfmet_phi > 0 && pfmet_phi < 2)"])
    # neutral-charge asymmetry cut
    batch[-1].cuts.extend(["l2_nc_ratio>-99"])
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


