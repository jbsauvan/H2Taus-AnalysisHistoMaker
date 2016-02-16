Name = "Name"
File = "File"
Object = "Object"
Type = "Type"
Dir  = "Dir"
Cut  = "Cut"



#class FakeFactors:
    #def __init__(self):
        #self.fakeFactorsFile1D = ''
        #self.fakeFactorsFile2D = ''
        #self.fakeFactors = []


class FakeFactor:
    def __init__(self, **args):
        self.Name   = args.get('Name', '')
        self.File   = args.get('File', '')
        self.Type   = args.get('Type', '')
        self.Object = args.get('Object', '')

    def __str__(self):
        str = ''
        str += 'Fake factor:\n'
        str += '  Name   = '+ self.Name + '\n'
        str += '  File   = '+ self.File + '\n'
        str += '  Type   = '+ self.Type + '\n'
        str += '  Object = '+ self.Object + '\n'
        return str


## Files
fractionsFile = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeBackgroundFractions/results/backgroundFraction_Iso_Medium_mvis_vs_mt.root"
highMTCorrectionFile = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_WJets/FakeFactors_WJets_highMTCorrections.root"
nonClosureFile = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/Uncertainties/Closures/results/nonClosures.root"
fakeFactors1DMCFileTemplate = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_{TYPE}_1D/FakeFactors_{TYPE}_1D.root"
fakeFactors2DMCFileTemplate = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_{TYPE}_2D/FakeFactors_{TYPE}_2D.root"
fakeFactors1DDataFileTemplate = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_Data_{TYPE}_1D/FakeFactors_Data_{TYPE}_1D.root"
fakeFactors2DDataFileTemplate = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_Data_{TYPE}_2D/FakeFactors_Data_{TYPE}_2D.root"

fakeFactorTypes = ['ZMuMu', 'HighMTRaw', 'HighMT', 'QCDSS', 'Combined']


##############################################
## Background fractions
##############################################
fractionsW   = FakeFactor(Name="Fraction_W_VsMVisMT"  , File=fractionsFile, Type="2DHisto", Object="h_backgroundFraction_Iso_Medium_mvis_vs_mt_W")
fractionsQCD = FakeFactor(Name="Fraction_QCD_VsMVisMT", File=fractionsFile, Type="2DHisto", Object="h_backgroundFraction_Iso_Medium_mvis_vs_mt_QCD")
fractionsTT  = FakeFactor(Name="Fraction_TT_VsMVisMT" , File=fractionsFile, Type="2DHisto", Object="h_backgroundFraction_Iso_Medium_mvis_vs_mt_TT")
fractionsZJ  = FakeFactor(Name="Fraction_ZJ_VsMVisMT" , File=fractionsFile, Type="2DHisto", Object="h_backgroundFraction_Iso_Medium_mvis_vs_mt_ZJ")
fractionsVV  = FakeFactor(Name="Fraction_VV_VsMVisMT" , File=fractionsFile, Type="2DHisto", Object="h_backgroundFraction_Iso_Medium_mvis_vs_mt_VV")

##############################################
## High-MT correction
##############################################
highMTCorrection = FakeFactor(Name="HighMTCorr_VsMT" , File=highMTCorrectionFile, Type="1DGraph", Object="HighMTCorrection_WJets_Iso_Medium_OS_InvertIso_Medium_OS_mt")

##############################################
## Uncertainties
##############################################
## Non-closures
nonClosures = {}
nonClosures['HighMT'] = FakeFactor(Name="HighMTNonClosure_VsMvis", File=nonClosureFile, Type="1DGraph", Object="HighMT_KDE_Ratio")

##############################################
## Fake factors
##############################################
fakeFactorsMC = {}
fakeFactorsData = {}
for type in fakeFactorTypes:
    fakeFactorsMC[type] = {}
    fakeFactorsData[type] = {}

formCorrection = '[{CORR}]*[{RAW}]'
formCombined = '[{W_QCD}]*[{QCD}]+[{W_W}]*[{W}]+[{W_Z}]*([{ZJ}]+[{TT}]+[{VV}])'

fakeFactor = 'Iso_Medium_VsPtDecay'
## ZMuMu 
fakeFactorsMC['ZMuMu'][fakeFactor]     = FakeFactor(
    Name="Weight_ZMuMu_"+fakeFactor,
    File=fakeFactors2DMCFileTemplate.format(TYPE='ZMuMu') ,
    Type="2DHisto",
    Object="FakeFactors_ZMuMu_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"
)
fakeFactorsData['ZMuMu'][fakeFactor]     = FakeFactor(
    Name="Weight_ZMuMu_"+fakeFactor,
    File=fakeFactors2DDataFileTemplate.format(TYPE='ZMuMu') ,
    Type="2DHisto",
    Object="FakeFactors_Data_ZMuMu_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"
)
## HighMTRaw
fakeFactorsMC['HighMTRaw'][fakeFactor] = FakeFactor(
    Name="Weight_HighMTRaw_"+fakeFactor,
    File=fakeFactors2DMCFileTemplate.format(TYPE='HighMT'),
    Type="2DHisto",
    Object="FakeFactors_HighMT_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"
)
fakeFactorsData['HighMTRaw'][fakeFactor] = FakeFactor(
    Name="Weight_HighMTRaw_"+fakeFactor,
    File=fakeFactors2DDataFileTemplate.format(TYPE='HighMT'),
    Type="2DHisto",
    Object="FakeFactors_Data_HighMT_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"
)
## HighMT
fakeFactorsMC['HighMT'][fakeFactor]    = FakeFactor(
    Name="Weight_HighMT_"+fakeFactor,
    File='',
    Type="Combined",
    Object=formCorrection.format(
        CORR=highMTCorrection.Name,
        RAW=fakeFactorsMC['HighMTRaw'][fakeFactor].Name
    )
)
fakeFactorsData['HighMT'][fakeFactor]    = FakeFactor(
    Name="Weight_HighMT_"+fakeFactor,
    File='',
    Type="Combined",
    Object=formCorrection.format(
        CORR=highMTCorrection.Name,
        RAW=fakeFactorsData['HighMTRaw'][fakeFactor].Name
    )
)
## QCDSS
fakeFactorsMC['QCDSS'][fakeFactor]     = FakeFactor(
    Name="Weight_QCDSS_"+fakeFactor,
    File=fakeFactors2DMCFileTemplate.format(TYPE='QCDSS'),
    Type="2DHisto",
    Object="FakeFactors_QCDSS_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"
)
fakeFactorsData['QCDSS'][fakeFactor]     = FakeFactor(
    Name="Weight_QCDSS_"+fakeFactor,
    File=fakeFactors2DDataFileTemplate.format(TYPE='QCDSS'),
    Type="2DHisto",
    Object="FakeFactors_Data_QCDSS_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"
)
## Combined
fakeFactorsMC['Combined'][fakeFactor]  = FakeFactor(
    Name="Weight_Combined_"+fakeFactor,
    File='',
    Type="Combined",
    Object=formCombined.format(
        W_QCD=fakeFactorsMC['QCDSS'][fakeFactor].Name,
        QCD=fractionsQCD.Name,
        W_W=fakeFactorsMC['HighMT'][fakeFactor].Name,
        W=fractionsW.Name,
        W_Z=fakeFactorsMC['ZMuMu'][fakeFactor].Name,
        ZJ=fractionsZJ.Name,
        TT=fractionsTT.Name,
        VV=fractionsVV.Name
    )
)
fakeFactorsData['Combined'][fakeFactor]  = FakeFactor(
    Name="Weight_Combined_"+fakeFactor,
    File='',
    Type="Combined",
    Object=formCombined.format(
        W_QCD=fakeFactorsData['QCDSS'][fakeFactor].Name,
        QCD=fractionsQCD.Name,
        W_W=fakeFactorsData['HighMT'][fakeFactor].Name,
        W=fractionsW.Name,
        W_Z=fakeFactorsData['ZMuMu'][fakeFactor].Name,
        ZJ=fractionsZJ.Name,
        TT=fractionsTT.Name,
        VV=fractionsVV.Name
    )
)



###############################################
##  Produce shifted fake factors 
###############################################
formShift = '[{SHIFT}]*[{NOM}]'
for type,nonClosure in nonClosures.items():
    ## MC fake factors
    # sys shift on individual fake factors
    for name,fakeFactor in fakeFactorsMC[type].items():
        fakeFactorShift = FakeFactor(
            Name=fakeFactor.Name+'_ShiftNonClosure'+type,
            File='',
            Type="Combined",
            Object=formShift.format(
                SHIFT=nonClosure.Name,
                NOM=fakeFactor.Name
            )
        )
        fakeFactorsMC[type][name+'_ShiftNonClosure'+type] = fakeFactorShift
    # sys shift on combined fake factors
    for name,fakeFactor in fakeFactorsMC['Combined'].items():
        shiftedComponent = formShift.format(SHIFT=nonClosure.Name,NOM=fakeFactorsMC[type][name].Name)
        fakeFactorShift = FakeFactor(
            Name=fakeFactor.Name+'_ShiftNonClosure'+type,
            File='',
            Type="Combined",
            Object=fakeFactor.Object.replace(fakeFactorsMC[type][name].Name, fakeFactorsMC[type][name].Name+'_ShiftNonClosure'+type)
        )
        fakeFactorsMC['Combined'][name+'_ShiftNonClosure'+type] = fakeFactorShift
    ## Data fake factors
    # sys shift on individual fake factors
    for name,fakeFactor in fakeFactorsData[type].items():
        fakeFactorShift = FakeFactor(
            Name=fakeFactor.Name+'_ShiftNonClosure'+type,
            File='',
            Type="Combined",
            Object=formShift.format(
                SHIFT=nonClosure.Name,
                NOM=fakeFactor.Name
            )
        )
        fakeFactorsData[type][name+'_ShiftNonClosure'+type] = fakeFactorShift
    # sys shift on combined fake factors
    for name,fakeFactor in fakeFactorsData['Combined'].items():
        shiftedComponent = formShift.format(SHIFT=nonClosure.Name,NOM=fakeFactorsData[type][name].Name)
        fakeFactorShift = FakeFactor(
            Name=fakeFactor.Name+'_ShiftNonClosure'+type,
            File='',
            Type="Combined",
            Object=fakeFactor.Object.replace(fakeFactorsData[type][name].Name, fakeFactorsData[type][name].Name+'_ShiftNonClosure'+type)
        )
        fakeFactorsData['Combined'][name+'_ShiftNonClosure'+type] = fakeFactorShift
