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




##############################################
## Background fractions
##############################################
#fractionsFile = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeBackgroundFractions/results/backgroundFraction_lowMT_mvis.root"
#fractionsW   = {Name:"Fraction_W_VsMVis"      , File:fractionsFile, Type:"1DHisto", Object:"h_backgroundFraction_lowMT_mvis_W"}
#fractionsQCD = {Name:"Fraction_QCD_VsMVis"    , File:fractionsFile, Type:"1DHisto", Object:"h_backgroundFraction_lowMT_mvis_QCD"}
#fractionsTT  = {Name:"Fraction_TT_VsMVis"     , File:fractionsFile, Type:"1DHisto", Object:"h_backgroundFraction_lowMT_mvis_TT"}
#fractionsZJ  = {Name:"Fraction_ZJ_VsMVis"     , File:fractionsFile, Type:"1DHisto", Object:"h_backgroundFraction_lowMT_mvis_ZJ"}
#fractionsVV  = {Name:"Fraction_VV_VsMVis"     , File:fractionsFile, Type:"1DHisto", Object:"h_backgroundFraction_lowMT_mvis_VV"}

fractionsFile = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeBackgroundFractions/results/backgroundFraction_Iso_Medium_mvis_vs_mt.root"
fractionsW   = {Name:"Fraction_W_VsMVisMT"      , File:fractionsFile, Type:"2DHisto", Object:"h_backgroundFraction_Iso_Medium_mvis_vs_mt_W_Nom"}
fractionsQCD = {Name:"Fraction_QCD_VsMVisMT"    , File:fractionsFile, Type:"2DHisto", Object:"h_backgroundFraction_Iso_Medium_mvis_vs_mt_QCD_Nom"}
fractionsTT  = {Name:"Fraction_TT_VsMVisMT"     , File:fractionsFile, Type:"2DHisto", Object:"h_backgroundFraction_Iso_Medium_mvis_vs_mt_TT_Nom"}
fractionsZJ  = {Name:"Fraction_ZJ_VsMVisMT"     , File:fractionsFile, Type:"2DHisto", Object:"h_backgroundFraction_Iso_Medium_mvis_vs_mt_ZJ_Nom"}
fractionsVV  = {Name:"Fraction_VV_VsMVisMT"     , File:fractionsFile, Type:"2DHisto", Object:"h_backgroundFraction_Iso_Medium_mvis_vs_mt_VV_Nom"}

##############################################
## High-MT correction
##############################################
highMTCorrectionFile = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeMTCorrection/results/mtCorrections.root"
highMTCorrection = {Name:"HighMTCorr_VsMT"      , File:highMTCorrectionFile, Type:"1DGraph", Object:"mt_correction"}


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
### HighMT Raw
fakeFactorsMC['HighMTRaw'] = FakeFactors()
fakeFactorsMC['HighMTRaw'].fakeFactorsFile1D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_HighMT_1D/FakeFactors_HighMT_1D.root"
fakeFactorsMC['HighMTRaw'].fakeFactorsFile2D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_HighMT_2D/FakeFactors_HighMT_2D.root"
## !IsoMedium -> IsoMedium
# 1D
fakeFactorsMC['HighMTRaw'].fakeFactors.append({Name:"Weight_HighMTRaw_Iso_Medium_VsPt"        , File:fakeFactorsMC['HighMTRaw'].fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_HighMT_1D_Iso_Medium_InvertIso_Medium_tau_pt"})
fakeFactorsMC['HighMTRaw'].fakeFactors.append({Name:"Weight_HighMTRaw_Iso_Medium_VsDecay"     , File:fakeFactorsMC['HighMTRaw'].fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_HighMT_1D_Iso_Medium_InvertIso_Medium_tau_decayMode"})
# 2D
fakeFactorsMC['HighMTRaw'].fakeFactors.append({Name:"Weight_HighMTRaw_Iso_Medium_VsPtDecay"   , File:fakeFactorsMC['HighMTRaw'].fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_HighMT_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"})
#####################################################
### HighMTSS Raw
fakeFactorsMC['HighMTSSRaw'] = FakeFactors()
fakeFactorsMC['HighMTSSRaw'].fakeFactorsFile1D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_HighMTSS_1D/FakeFactors_HighMTSS_1D.root"
fakeFactorsMC['HighMTSSRaw'].fakeFactorsFile2D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_HighMTSS_2D/FakeFactors_HighMTSS_2D.root"
## !IsoMedium -> IsoMedium
# 1D
fakeFactorsMC['HighMTSSRaw'].fakeFactors.append({Name:"Weight_HighMTSSRaw_Iso_Medium_VsPt"        , File:fakeFactorsMC['HighMTSSRaw'].fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_HighMTSS_1D_SS_Iso_Medium_SS_InvertIso_Medium_tau_pt"})
fakeFactorsMC['HighMTSSRaw'].fakeFactors.append({Name:"Weight_HighMTSSRaw_Iso_Medium_VsDecay"     , File:fakeFactorsMC['HighMTSSRaw'].fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_HighMTSS_1D_SS_Iso_Medium_SS_InvertIso_Medium_tau_decayMode"})
# 2D
fakeFactorsMC['HighMTSSRaw'].fakeFactors.append({Name:"Weight_HighMTSSRaw_Iso_Medium_VsPtDecay"   , File:fakeFactorsMC['HighMTSSRaw'].fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_HighMTSS_2D_SS_Iso_Medium_SS_InvertIso_Medium_tau_pt_vs_decayMode"})
#####################################################
### HighMT Corr
template = '[{CORR}]*[{RAW}]'
fakeFactorsMC['HighMT'] = FakeFactors()
## !IsoMedium -> IsoMedium
# 1D
fakeFactorsMC['HighMT'].fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsPt"     , File:'', Type:"Combined", Object:template.format(CORR=highMTCorrection[Name],RAW=fakeFactorsMC['HighMTRaw'].fakeFactors[0][Name])})
fakeFactorsMC['HighMT'].fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsDecay"  , File:'', Type:"Combined", Object:template.format(CORR=highMTCorrection[Name],RAW=fakeFactorsMC['HighMTRaw'].fakeFactors[1][Name])})
# 2D
fakeFactorsMC['HighMT'].fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsPtDecay", File:'', Type:"Combined", Object:template.format(CORR=highMTCorrection[Name],RAW=fakeFactorsMC['HighMTRaw'].fakeFactors[2][Name])})
#####################################################
### HighMTSS Corr
template = '[{CORR}]*[{RAW}]'
fakeFactorsMC['HighMTSS'] = FakeFactors()
## !IsoMedium -> IsoMedium
# 1D
fakeFactorsMC['HighMTSS'].fakeFactors.append({Name:"Weight_HighMTSS_Iso_Medium_VsPt"     , File:'', Type:"Combined", Object:template.format(CORR=highMTCorrection[Name],RAW=fakeFactorsMC['HighMTSSRaw'].fakeFactors[0][Name])})
fakeFactorsMC['HighMTSS'].fakeFactors.append({Name:"Weight_HighMTSS_Iso_Medium_VsDecay"  , File:'', Type:"Combined", Object:template.format(CORR=highMTCorrection[Name],RAW=fakeFactorsMC['HighMTSSRaw'].fakeFactors[1][Name])})
# 2D
fakeFactorsMC['HighMTSS'].fakeFactors.append({Name:"Weight_HighMTSS_Iso_Medium_VsPtDecay", File:'', Type:"Combined", Object:template.format(CORR=highMTCorrection[Name],RAW=fakeFactorsMC['HighMTSSRaw'].fakeFactors[2][Name])})
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
#####################################################
### Combined
#template = '[{W_QCD}]*[{QCD}]+[{W_W}]*[{W}]+[{W_Z}]*([{ZJ}]+[{TT}]+[{VV}])'
#template = '[{W_QCD}]*[{QCD}]+[{W_W}]*([{W}]+[{TT}])+[{W_Z}]*([{ZJ}]+[{VV}])'
template = '[{W_QCD}]*[{QCD}]+[{W_W}]*([{W}]+[{TT}]+[{ZJ}]+[{VV}])'
fakeFactorsMC['Combined'] = FakeFactors()
## !IsoMedium -> IsoMedium
# 1D
fakeFactorsMC['Combined'].fakeFactors.append({Name:"Weight_Combined_Iso_Medium_VsPt"     , File:'', Type:"Combined", Object:template.format(W_QCD=fakeFactorsMC['QCDSS'].fakeFactors[0][Name],QCD=fractionsQCD[Name],W_W=fakeFactorsMC['HighMT'].fakeFactors[0][Name],W=fractionsW[Name],ZJ=fractionsZJ[Name],TT=fractionsTT[Name],VV=fractionsVV[Name])})
fakeFactorsMC['Combined'].fakeFactors.append({Name:"Weight_Combined_Iso_Medium_VsDecay"  , File:'', Type:"Combined", Object:template.format(W_QCD=fakeFactorsMC['QCDSS'].fakeFactors[1][Name],QCD=fractionsQCD[Name],W_W=fakeFactorsMC['HighMT'].fakeFactors[1][Name],W=fractionsW[Name],ZJ=fractionsZJ[Name],TT=fractionsTT[Name],VV=fractionsVV[Name])})
# 2D
fakeFactorsMC['Combined'].fakeFactors.append({Name:"Weight_Combined_Iso_Medium_VsPtDecay", File:'', Type:"Combined", Object:template.format(W_QCD=fakeFactorsMC['QCDSS'].fakeFactors[2][Name],QCD=fractionsQCD[Name],W_W=fakeFactorsMC['HighMT'].fakeFactors[2][Name],W=fractionsW[Name],ZJ=fractionsZJ[Name],TT=fractionsTT[Name],VV=fractionsVV[Name])})



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
### HighMT Raw
fakeFactorsData['HighMTRaw'] = FakeFactors()
fakeFactorsData['HighMTRaw'].fakeFactorsFile1D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_Data_HighMT_1D/FakeFactors_Data_HighMT_1D.root"
fakeFactorsData['HighMTRaw'].fakeFactorsFile2D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_Data_HighMT_2D/FakeFactors_Data_HighMT_2D.root"
## !IsoMedium -> IsoMedium
# 1D
fakeFactorsData['HighMTRaw'].fakeFactors.append({Name:"Weight_HighMTRaw_Iso_Medium_VsPt"        , File:fakeFactorsData['HighMTRaw'].fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_Data_HighMT_1D_Iso_Medium_InvertIso_Medium_tau_pt"})
fakeFactorsData['HighMTRaw'].fakeFactors.append({Name:"Weight_HighMTRaw_Iso_Medium_VsDecay"     , File:fakeFactorsData['HighMTRaw'].fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_Data_HighMT_1D_Iso_Medium_InvertIso_Medium_tau_decayMode"})
# 2D
fakeFactorsData['HighMTRaw'].fakeFactors.append({Name:"Weight_HighMTRaw_Iso_Medium_VsPtDecay"   , File:fakeFactorsData['HighMTRaw'].fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_Data_HighMT_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"})
#####################################################
### HighMTSS Raw
fakeFactorsData['HighMTSSRaw'] = FakeFactors()
fakeFactorsData['HighMTSSRaw'].fakeFactorsFile1D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_Data_HighMTSS_1D/FakeFactors_Data_HighMTSS_1D.root"
fakeFactorsData['HighMTSSRaw'].fakeFactorsFile2D = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_Data_HighMTSS_2D/FakeFactors_Data_HighMTSS_2D.root"
## !IsoMedium -> IsoMedium
# 1D
fakeFactorsData['HighMTSSRaw'].fakeFactors.append({Name:"Weight_HighMTSSRaw_Iso_Medium_VsPt"        , File:fakeFactorsData['HighMTSSRaw'].fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_Data_HighMT_1D_SS_Iso_Medium_SS_InvertIso_Medium_tau_pt"})
fakeFactorsData['HighMTSSRaw'].fakeFactors.append({Name:"Weight_HighMTSSRaw_Iso_Medium_VsDecay"     , File:fakeFactorsData['HighMTSSRaw'].fakeFactorsFile1D, Type:"1DGraph", Object:"FakeFactors_Data_HighMT_1D_SS_Iso_Medium_SS_InvertIso_Medium_tau_decayMode"})
# 2D
fakeFactorsData['HighMTSSRaw'].fakeFactors.append({Name:"Weight_HighMTSSRaw_Iso_Medium_VsPtDecay"   , File:fakeFactorsData['HighMTSSRaw'].fakeFactorsFile2D, Type:"2DHisto", Object:"FakeFactors_Data_HighMT_2D_SS_Iso_Medium_SS_InvertIso_Medium_tau_pt_vs_decayMode"})
#####################################################
### HighMT Corr
template = '[{CORR}]*[{RAW}]'
fakeFactorsData['HighMT'] = FakeFactors()
## !IsoMedium -> IsoMedium
# 1D
fakeFactorsData['HighMT'].fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsPt"     , File:'', Type:"Combined", Object:template.format(CORR=highMTCorrection[Name],RAW=fakeFactorsData['HighMTRaw'].fakeFactors[0][Name])})
fakeFactorsData['HighMT'].fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsDecay"  , File:'', Type:"Combined", Object:template.format(CORR=highMTCorrection[Name],RAW=fakeFactorsData['HighMTRaw'].fakeFactors[1][Name])})
# 2D
fakeFactorsData['HighMT'].fakeFactors.append({Name:"Weight_HighMT_Iso_Medium_VsPtDecay", File:'', Type:"Combined", Object:template.format(CORR=highMTCorrection[Name],RAW=fakeFactorsData['HighMTRaw'].fakeFactors[2][Name])})
#####################################################
### HighMTSS Corr
template = '[{CORR}]*[{RAW}]'
fakeFactorsData['HighMTSS'] = FakeFactors()
## !IsoMedium -> IsoMedium
# 1D
fakeFactorsData['HighMTSS'].fakeFactors.append({Name:"Weight_HighMTSS_Iso_Medium_VsPt"     , File:'', Type:"Combined", Object:template.format(CORR=highMTCorrection[Name],RAW=fakeFactorsData['HighMTSSRaw'].fakeFactors[0][Name])})
fakeFactorsData['HighMTSS'].fakeFactors.append({Name:"Weight_HighMTSS_Iso_Medium_VsDecay"  , File:'', Type:"Combined", Object:template.format(CORR=highMTCorrection[Name],RAW=fakeFactorsData['HighMTSSRaw'].fakeFactors[1][Name])})
# 2D
fakeFactorsData['HighMTSS'].fakeFactors.append({Name:"Weight_HighMTSS_Iso_Medium_VsPtDecay", File:'', Type:"Combined", Object:template.format(CORR=highMTCorrection[Name],RAW=fakeFactorsData['HighMTSSRaw'].fakeFactors[2][Name])})
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
#####################################################
### Combined
#template = '[{W_QCD}]*[{QCD}]+[{W_W}]*[{W}]+[{W_Z}]*([{ZJ}]+[{TT}]+[{VV}])'
#template = '[{W_QCD}]*[{QCD}]+[{W_W}]*([{W}]+[{TT}])+[{W_Z}]*([{ZJ}]+[{VV}])'
template = '[{W_QCD}]*[{QCD}]+[{W_W}]*([{W}]+[{TT}]+[{ZJ}]+[{VV}])'
fakeFactorsData['Combined'] = FakeFactors()
## !IsoMedium -> IsoMedium
# 1D
fakeFactorsData['Combined'].fakeFactors.append({Name:"Weight_Combined_Iso_Medium_VsPt"     , File:'', Type:"Combined", Object:template.format(W_QCD=fakeFactorsData['QCDSS'].fakeFactors[0][Name],QCD=fractionsQCD[Name],W_W=fakeFactorsData['HighMT'].fakeFactors[0][Name],W=fractionsW[Name],ZJ=fractionsZJ[Name],TT=fractionsTT[Name],VV=fractionsVV[Name])})
fakeFactorsData['Combined'].fakeFactors.append({Name:"Weight_Combined_Iso_Medium_VsDecay"  , File:'', Type:"Combined", Object:template.format(W_QCD=fakeFactorsData['QCDSS'].fakeFactors[1][Name],QCD=fractionsQCD[Name],W_W=fakeFactorsData['HighMT'].fakeFactors[1][Name],W=fractionsW[Name],ZJ=fractionsZJ[Name],TT=fractionsTT[Name],VV=fractionsVV[Name])})
# 2D
fakeFactorsData['Combined'].fakeFactors.append({Name:"Weight_Combined_Iso_Medium_VsPtDecay", File:'', Type:"Combined", Object:template.format(W_QCD=fakeFactorsData['QCDSS'].fakeFactors[2][Name],QCD=fractionsQCD[Name],W_W=fakeFactorsData['HighMT'].fakeFactors[2][Name],W=fractionsW[Name],ZJ=fractionsZJ[Name],TT=fractionsTT[Name],VV=fractionsVV[Name])})
#####################################################
### Combined SS
#template = '[{W_QCD}]*[{QCD}]+[{W_W}]*[{W}]+[{W_Z}]*([{ZJ}]+[{TT}]+[{VV}])'
#template = '[{W_QCD}]*[{QCD}]+[{W_W}]*([{W}]+[{TT}])+[{W_Z}]*([{ZJ}]+[{VV}])'
template = '[{W_QCD}]*[{QCD}]+[{W_W}]*([{W}]+[{TT}]+[{ZJ}]+[{VV}])'
fakeFactorsData['CombinedSS'] = FakeFactors()
## !IsoMedium -> IsoMedium
# 1D
fakeFactorsData['CombinedSS'].fakeFactors.append({Name:"Weight_CombinedSS_Iso_Medium_VsPt"     , File:'', Type:"Combined", Object:template.format(W_QCD=fakeFactorsData['QCDSS'].fakeFactors[0][Name],QCD=fractionsQCD[Name],W_W=fakeFactorsData['HighMTSS'].fakeFactors[0][Name],W=fractionsW[Name],ZJ=fractionsZJ[Name],TT=fractionsTT[Name],VV=fractionsVV[Name])})
fakeFactorsData['CombinedSS'].fakeFactors.append({Name:"Weight_CombinedSS_Iso_Medium_VsDecay"  , File:'', Type:"Combined", Object:template.format(W_QCD=fakeFactorsData['QCDSS'].fakeFactors[1][Name],QCD=fractionsQCD[Name],W_W=fakeFactorsData['HighMTSS'].fakeFactors[1][Name],W=fractionsW[Name],ZJ=fractionsZJ[Name],TT=fractionsTT[Name],VV=fractionsVV[Name])})
# 2D
fakeFactorsData['CombinedSS'].fakeFactors.append({Name:"Weight_CombinedSS_Iso_Medium_VsPtDecay", File:'', Type:"Combined", Object:template.format(W_QCD=fakeFactorsData['QCDSS'].fakeFactors[2][Name],QCD=fractionsQCD[Name],W_W=fakeFactorsData['HighMTSS'].fakeFactors[2][Name],W=fractionsW[Name],ZJ=fractionsZJ[Name],TT=fractionsTT[Name],VV=fractionsVV[Name])})
