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

fakeFactorsMC = {}
fakeFactorsData = {}


###############################################
##  MC fake factors
###############################################
### ZMuMu 
fakeFactorsMC['ZMuMu'] = FakeFactors()
fakeFactorsMC['ZMuMu'].fakeFactorsFile1D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_ZMuMu_1D/FakeFactors_ZMuMu_1D.root"
fakeFactorsMC['ZMuMu'].fakeFactorsFile2D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_ZMuMu_2D/FakeFactors_ZMuMu_2D.root"
## !IsoMedium -> IsoMedium
# 1D
fakeFactorsMC['ZMuMu'].fakeFactors.append({Name:"Weight_Iso_Medium_VsPt"        , File:fakeFactorsMC['ZMuMu'].fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_tau_pt"})
fakeFactorsMC['ZMuMu'].fakeFactors.append({Name:"Weight_Iso_Medium_VsDecay"     , File:fakeFactorsMC['ZMuMu'].fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_ZMuMu_1D_Iso_Medium_InvertIso_Medium_tau_decayMode"})
# 2D
fakeFactorsMC['ZMuMu'].fakeFactors.append({Name:"Weight_Iso_Medium_VsPtDecay"   , File:fakeFactorsMC['ZMuMu'].fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_ZMuMu_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"})
#####################################################
### HighMT
fakeFactorsMC['HighMT'] = FakeFactors()
fakeFactorsMC['HighMT'].fakeFactorsFile1D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_HighMT_1D/FakeFactors_HighMT_1D.root"
fakeFactorsMC['HighMT'].fakeFactorsFile2D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_HighMT_2D/FakeFactors_HighMT_2D.root"
## !IsoMedium -> IsoMedium
# 1D
fakeFactorsMC['HighMT'].fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsPt"        , File:fakeFactorsMC['HighMT'].fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_HighMT_1D_Iso_Medium_InvertIso_Medium_tau_pt"})
fakeFactorsMC['HighMT'].fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsDecay"     , File:fakeFactorsMC['HighMT'].fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_HighMT_1D_Iso_Medium_InvertIso_Medium_tau_decayMode"})
# 2D
fakeFactorsMC['HighMT'].fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsPtDecay"   , File:fakeFactorsMC['HighMT'].fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_HighMT_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"})
#####################################################
### QCDSS
fakeFactorsMC['QCDSS'] = FakeFactors()
fakeFactorsMC['QCDSS'].fakeFactorsFile1D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_QCDSS_1D/FakeFactors_QCDSS_1D.root"
fakeFactorsMC['QCDSS'].fakeFactorsFile2D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_QCDSS_2D/FakeFactors_QCDSS_2D.root"
## !IsoMedium -> IsoMedium
# 1D
fakeFactorsMC['QCDSS'].fakeFactors.append({Name:"Weight_QCDSS_Iso_Medium_VsPt"        , File:fakeFactorsMC['QCDSS'].fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_QCDSS_1D_Iso_Medium_InvertIso_Medium_tau_pt"})
fakeFactorsMC['QCDSS'].fakeFactors.append({Name:"Weight_QCDSS_Iso_Medium_VsDecay"     , File:fakeFactorsMC['QCDSS'].fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_QCDSS_1D_Iso_Medium_InvertIso_Medium_tau_decayMode"})
# 2D
fakeFactorsMC['QCDSS'].fakeFactors.append({Name:"Weight_QCDSS_Iso_Medium_VsPtDecay"   , File:fakeFactorsMC['QCDSS'].fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_QCDSS_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"})


###############################################
##  Data fake factors
###############################################
### ZMuMu 
fakeFactorsData['ZMuMu'] = FakeFactors()
fakeFactorsData['ZMuMu'].fakeFactorsFile1D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_Data_ZMuMu_1D/FakeFactors_Data_ZMuMu_1D.root"
fakeFactorsData['ZMuMu'].fakeFactorsFile2D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_Data_ZMuMu_2D/FakeFactors_Data_ZMuMu_2D.root"
## !IsoMedium -> IsoMedium
# 1D
fakeFactorsData['ZMuMu'].fakeFactors.append({Name:"Weight_Iso_Medium_VsPt"        , File:fakeFactorsData['ZMuMu'].fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_Data_ZMuMu_1D_Iso_Medium_InvertIso_Medium_tau_pt"})
fakeFactorsData['ZMuMu'].fakeFactors.append({Name:"Weight_Iso_Medium_VsDecay"     , File:fakeFactorsData['ZMuMu'].fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_Data_ZMuMu_1D_Iso_Medium_InvertIso_Medium_tau_decayMode"})
# 2D
fakeFactorsData['ZMuMu'].fakeFactors.append({Name:"Weight_Iso_Medium_VsPtDecay"   , File:fakeFactorsData['ZMuMu'].fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_Data_ZMuMu_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"})
#####################################################
### HighMT
fakeFactorsData['HighMT'] = FakeFactors()
fakeFactorsData['HighMT'].fakeFactorsFile1D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_Data_HighMT_1D/FakeFactors_Data_HighMT_1D.root"
fakeFactorsData['HighMT'].fakeFactorsFile2D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_Data_HighMT_2D/FakeFactors_Data_HighMT_2D.root"
## !IsoMedium -> IsoMedium
# 1D
fakeFactorsData['HighMT'].fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsPt"        , File:fakeFactorsData['HighMT'].fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_Data_HighMT_1D_Iso_Medium_InvertIso_Medium_tau_pt"})
fakeFactorsData['HighMT'].fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsDecay"     , File:fakeFactorsData['HighMT'].fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_Data_HighMT_1D_Iso_Medium_InvertIso_Medium_tau_decayMode"})
# 2D
fakeFactorsData['HighMT'].fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsPtDecay"   , File:fakeFactorsData['HighMT'].fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_Data_HighMT_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"})
#####################################################
### QCDSS
fakeFactorsData['QCDSS'] = FakeFactors()
fakeFactorsData['QCDSS'].fakeFactorsFile1D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_Data_QCDSS_1D/FakeFactors_Data_QCDSS_1D.root"
fakeFactorsData['QCDSS'].fakeFactorsFile2D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_Data_QCDSS_2D/FakeFactors_Data_QCDSS_2D.root"
## !IsoMedium -> IsoMedium
# 1D
fakeFactorsData['QCDSS'].fakeFactors.append({Name:"Weight_QCDSS_Iso_Medium_VsPt"        , File:fakeFactorsData['QCDSS'].fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_Data_QCDSS_1D_Iso_Medium_InvertIso_Medium_tau_pt"})
fakeFactorsData['QCDSS'].fakeFactors.append({Name:"Weight_QCDSS_Iso_Medium_VsDecay"     , File:fakeFactorsData['QCDSS'].fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_Data_QCDSS_1D_Iso_Medium_InvertIso_Medium_tau_decayMode"})
# 2D
fakeFactorsData['QCDSS'].fakeFactors.append({Name:"Weight_QCDSS_Iso_Medium_VsPtDecay"   , File:fakeFactorsData['QCDSS'].fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_Data_QCDSS_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"})
