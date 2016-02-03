Name = "Name"
File = "File"
Object = "Object"
Type = "Type"
Dir  = "Dir"
Cut  = "Cut"



class FakeFactors:
    def __init__(self):
        self.fakeFactorsFile1D = ''
        self.fakeFactorsFile2D = ''
        self.fakeFactors = []

fakeFactors = {}

#####################################################
### ZMuMu 
fakeFactorsZMuMu = FakeFactors()
fakeFactors['ZMuMu'] = fakeFactorsZMuMu
fakeFactorsZMuMu.fakeFactorsFile1D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_ZMuMu_1D/FakeFactors_ZMuMu_1D.root"
fakeFactorsZMuMu.fakeFactorsFile2D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_ZMuMu_2D/FakeFactors_ZMuMu_2D.root"
## IsoRaw > 1.5 GeV -> IsoRaw < 1.5 GeV
# 1D
fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_IsoRaw_1_5_Inclusive"   , File:fakeFactorsZMuMu.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_IsoRaw_1_5_InvertIsoRaw_1_5_nevents"})
#fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_IsoRaw_1_5_VsNVtx"      , File:fakeFactorsZMuMu.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_IsoRaw_1_5_InvertIsoRaw_1_5_nvertices"})
fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_IsoRaw_1_5_VsPt"        , File:fakeFactorsZMuMu.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_pt"})
#fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_IsoRaw_1_5_VsEta"       , File:fakeFactorsZMuMu.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_eta"})
fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_IsoRaw_1_5_VsDecay"     , File:fakeFactorsZMuMu.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_decayMode"})
fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_IsoRaw_1_5_VsPdgId"     , File:fakeFactorsZMuMu.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_pdgId"})
fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_IsoRaw_1_5_VsJetPt"     , File:fakeFactorsZMuMu.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_jet_pt"})
# 2D
#fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_IsoRaw_1_5_VsPtEta"     , File:fakeFactorsZMuMu.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_pt_vs_eta"})
fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_IsoRaw_1_5_VsPtDecay"   , File:fakeFactorsZMuMu.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_pt_vs_decayMode"})
fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_IsoRaw_1_5_VsPtPdgId"   , File:fakeFactorsZMuMu.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_pt_vs_mergedPdgId"})
fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_IsoRaw_1_5_VsJetPtDecay", File:fakeFactorsZMuMu.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_jet_pt_vs_decayMode"})
fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_IsoRaw_1_5_VsJetPtPt"   , File:fakeFactorsZMuMu.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_jet_pt_vs_pt"})

## !IsoMedium -> IsoMedium
# 1D
fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_Iso_Medium_Inclusive"   , File:fakeFactorsZMuMu.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_nevents"})
#fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_Iso_Medium_VsNVtx"      , File:fakeFactorsZMuMu.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_nvertices"})
fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_Iso_Medium_VsPt"        , File:fakeFactorsZMuMu.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_tau_pt"})
#fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_Iso_Medium_VsEta"       , File:fakeFactorsZMuMu.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_tau_eta"})
fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_Iso_Medium_VsDecay"     , File:fakeFactorsZMuMu.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_tau_decayMode"})
fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_Iso_Medium_VsPdgId"     , File:fakeFactorsZMuMu.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_tau_pdgId"})
fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_Iso_Medium_VsJetPt"     , File:fakeFactorsZMuMu.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_tau_jet_pt"})
# 2D
#fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_Iso_Medium_VsPtEta"     , File:fakeFactorsZMuMu.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_eta"})
fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_Iso_Medium_VsPtDecay"   , File:fakeFactorsZMuMu.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"})
fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_Iso_Medium_VsPtPdgId"   , File:fakeFactorsZMuMu.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_mergedPdgId"})
fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_Iso_Medium_VsJetPtDecay", File:fakeFactorsZMuMu.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_Iso_Medium_InvertIso_Medium_tau_jet_pt_vs_decayMode"})
fakeFactorsZMuMu.fakeFactors.append({Name:"Weight_Iso_Medium_VsJetPtPt"   , File:fakeFactorsZMuMu.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_Iso_Medium_InvertIso_Medium_tau_jet_pt_vs_pt"})


#####################################################
### HighMT
fakeFactorsHighMT = FakeFactors()
fakeFactors['HighMT'] = fakeFactorsHighMT
fakeFactorsHighMT.fakeFactorsFile1D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_HighMT_1D/FakeFactors_HighMT_1D.root"
fakeFactorsHighMT.fakeFactorsFile2D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_HighMT_2D/FakeFactors_HighMT_2D.root"
## IsoRaw > 1.5 GeV -> IsoRaw < 1.5 GeV
# 1D
fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_IsoRaw_1_5_Inclusive"   , File:fakeFactorsHighMT.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_HighMT_1D_IsoRaw_1_5_InvertIsoRaw_1_5_nevents"})
#fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_IsoRaw_1_5_VsNVtx"      , File:fakeFactorsHighMT.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_HighMT_1D_IsoRaw_1_5_InvertIsoRaw_1_5_nvertices"})
fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_IsoRaw_1_5_VsPt"        , File:fakeFactorsHighMT.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_HighMT_1D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_pt"})
#fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_IsoRaw_1_5_VsEta"       , File:fakeFactorsHighMT.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_HighMT_1D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_eta"})
fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_IsoRaw_1_5_VsDecay"     , File:fakeFactorsHighMT.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_HighMT_1D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_decayMode"})
fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_IsoRaw_1_5_VsPdgId"     , File:fakeFactorsHighMT.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_HighMT_1D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_pdgId"})
fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_IsoRaw_1_5_VsJetPt"     , File:fakeFactorsHighMT.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_HighMT_1D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_jet_pt"})
# 2D
#fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_IsoRaw_1_5_VsPtEta"     , File:fakeFactorsHighMT.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_HighMT_2D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_pt_vs_eta"})
fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_IsoRaw_1_5_VsPtDecay"   , File:fakeFactorsHighMT.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_HighMT_2D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_pt_vs_decayMode"})
fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_IsoRaw_1_5_VsPtPdgId"   , File:fakeFactorsHighMT.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_HighMT_2D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_pt_vs_mergedPdgId"})
fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_IsoRaw_1_5_VsJetPtDecay", File:fakeFactorsHighMT.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_HighMT_2D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_jet_pt_vs_decayMode"})
fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_IsoRaw_1_5_VsJetPtPt"   , File:fakeFactorsHighMT.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_HighMT_2D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_jet_pt_vs_pt"})

## !IsoMedium -> IsoMedium
# 1D
fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_Inclusive"   , File:fakeFactorsHighMT.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_HighMT_1D_Iso_Medium_InvertIso_Medium_nevents"})
#fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsNVtx"      , File:fakeFactorsHighMT.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_HighMT_1D_Iso_Medium_InvertIso_Medium_nvertices"})
fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsPt"        , File:fakeFactorsHighMT.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_HighMT_1D_Iso_Medium_InvertIso_Medium_tau_pt"})
#fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsEta"       , File:fakeFactorsHighMT.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_HighMT_1D_Iso_Medium_InvertIso_Medium_tau_eta"})
fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsDecay"     , File:fakeFactorsHighMT.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_HighMT_1D_Iso_Medium_InvertIso_Medium_tau_decayMode"})
fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsPdgId"     , File:fakeFactorsHighMT.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_HighMT_1D_Iso_Medium_InvertIso_Medium_tau_pdgId"})
fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsJetPt"     , File:fakeFactorsHighMT.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_HighMT_1D_Iso_Medium_InvertIso_Medium_tau_jet_pt"})
# 2D
#fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsPtEta"     , File:fakeFactorsHighMT.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_HighMT_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_eta"})
fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsPtDecay"   , File:fakeFactorsHighMT.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_HighMT_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"})
fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsPtPdgId"   , File:fakeFactorsHighMT.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_HighMT_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_mergedPdgId"})
fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsJetPtDecay", File:fakeFactorsHighMT.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_HighMT_2D_Iso_Medium_InvertIso_Medium_tau_jet_pt_vs_decayMode"})
fakeFactorsHighMT.fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsJetPtPt"   , File:fakeFactorsHighMT.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_HighMT_2D_Iso_Medium_InvertIso_Medium_tau_jet_pt_vs_pt"})


#####################################################
### QCDSS
fakeFactorsQCDSS = FakeFactors()
fakeFactors['QCDSS'] = fakeFactorsQCDSS
fakeFactorsQCDSS.fakeFactorsFile1D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_QCDSS_1D/FakeFactors_QCDSS_1D.root"
fakeFactorsQCDSS.fakeFactorsFile2D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_QCDSS_2D/FakeFactors_QCDSS_2D.root"
## IsoRaw > 1.5 GeV -> IsoRaw < 1.5 GeV
# 1D
fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_IsoRaw_1_5_Inclusive"   , File:fakeFactorsQCDSS.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_QCDSS_1D_IsoRaw_1_5_InvertIsoRaw_1_5_nevents"})
#fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_IsoRaw_1_5_VsNVtx"      , File:fakeFactorsQCDSS.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_QCDSS_1D_IsoRaw_1_5_InvertIsoRaw_1_5_nvertices"})
fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_IsoRaw_1_5_VsPt"        , File:fakeFactorsQCDSS.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_QCDSS_1D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_pt"})
#fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_IsoRaw_1_5_VsEta"       , File:fakeFactorsQCDSS.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_QCDSS_1D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_eta"})
fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_IsoRaw_1_5_VsDecay"     , File:fakeFactorsQCDSS.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_QCDSS_1D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_decayMode"})
fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_IsoRaw_1_5_VsPdgId"     , File:fakeFactorsQCDSS.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_QCDSS_1D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_pdgId"})
fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_IsoRaw_1_5_VsJetPt"     , File:fakeFactorsQCDSS.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_QCDSS_1D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_jet_pt"})
# 2D
#fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_IsoRaw_1_5_VsPtEta"     , File:fakeFactorsQCDSS.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_QCDSS_2D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_pt_vs_eta"})
fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_IsoRaw_1_5_VsPtDecay"   , File:fakeFactorsQCDSS.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_QCDSS_2D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_pt_vs_decayMode"})
fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_IsoRaw_1_5_VsPtPdgId"   , File:fakeFactorsQCDSS.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_QCDSS_2D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_pt_vs_mergedPdgId"})
fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_IsoRaw_1_5_VsJetPtDecay", File:fakeFactorsQCDSS.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_QCDSS_2D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_jet_pt_vs_decayMode"})
fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_IsoRaw_1_5_VsJetPtPt"   , File:fakeFactorsQCDSS.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_QCDSS_2D_IsoRaw_1_5_InvertIsoRaw_1_5_tau_jet_pt_vs_pt"})

## !IsoMedium -> IsoMedium
# 1D
fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_Iso_Medium_Inclusive"   , File:fakeFactorsQCDSS.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_QCDSS_1D_Iso_Medium_InvertIso_Medium_nevents"})
#fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_Iso_Medium_VsNVtx"      , File:fakeFactorsQCDSS.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_QCDSS_1D_Iso_Medium_InvertIso_Medium_nvertices"})
fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_Iso_Medium_VsPt"        , File:fakeFactorsQCDSS.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_QCDSS_1D_Iso_Medium_InvertIso_Medium_tau_pt"})
#fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_Iso_Medium_VsEta"       , File:fakeFactorsQCDSS.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_QCDSS_1D_Iso_Medium_InvertIso_Medium_tau_eta"})
fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_Iso_Medium_VsDecay"     , File:fakeFactorsQCDSS.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_QCDSS_1D_Iso_Medium_InvertIso_Medium_tau_decayMode"})
fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_Iso_Medium_VsPdgId"     , File:fakeFactorsQCDSS.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_QCDSS_1D_Iso_Medium_InvertIso_Medium_tau_pdgId"})
fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_Iso_Medium_VsJetPt"     , File:fakeFactorsQCDSS.fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_QCDSS_1D_Iso_Medium_InvertIso_Medium_tau_jet_pt"})
# 2D
#fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_Iso_Medium_VsPtEta"     , File:fakeFactorsQCDSS.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_QCDSS_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_eta"})
fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_Iso_Medium_VsPtDecay"   , File:fakeFactorsQCDSS.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_QCDSS_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"})
fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_Iso_Medium_VsPtPdgId"   , File:fakeFactorsQCDSS.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_QCDSS_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_mergedPdgId"})
fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_Iso_Medium_VsJetPtDecay", File:fakeFactorsQCDSS.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_QCDSS_2D_Iso_Medium_InvertIso_Medium_tau_jet_pt_vs_decayMode"})
fakeFactorsQCDSS.fakeFactors.append({Name:"Weight_QCDSS_Iso_Medium_VsJetPtPt"   , File:fakeFactorsQCDSS.fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_QCDSS_2D_Iso_Medium_InvertIso_Medium_tau_jet_pt_vs_pt"})
