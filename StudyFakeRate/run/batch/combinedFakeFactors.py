from FakeFactors import createRawComponent, createCombinedComponent, createCombinedSysComponent, findComponent

import ROOT

fakeFactor = 'Iso_Medium_VsPtDecay'


def findFraction(name, fractions):
    for fraction in fractions:
        if fraction.name is name:
            return fraction
    return None

def create(fakeFactorsMC, fakeFactorsData):
    fractionsFile = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeBackgroundFractions/results/backgroundFraction_Iso_Medium_mvis_vs_mt.root"
    #formCombined = '[{W_QCD}]*[{QCD}]+[{W_W}]*([{W}]+[{TT}])+[{W_Z}]*([{ZJ}]+[{VV}])'
    formCombined = '[{W_QCD}]*[{QCD}]+[{W_W}]*([{W}]+[{TT}]+[{ZJ}]+[{VV}])'
    fractionsW   = createRawComponent(
        Name="Fraction_W_VsMVisMT"  ,
        File=fractionsFile,
        Type="2DHisto",
        Object="h_backgroundFraction_Iso_Medium_mvis_vs_mt_W_Nom"
    )
    fractionsQCD = createRawComponent(
        Name="Fraction_QCD_VsMVisMT",
        File=fractionsFile,
        Type="2DHisto",
        Object="h_backgroundFraction_Iso_Medium_mvis_vs_mt_QCD_Nom"
    )
    fractionsTT  = createRawComponent(
        Name="Fraction_TT_VsMVisMT" ,
        File=fractionsFile,
        Type="2DHisto",
        Object="h_backgroundFraction_Iso_Medium_mvis_vs_mt_TT_Nom"
    )
    fractionsZJ  = createRawComponent(
        Name="Fraction_ZJ_VsMVisMT" ,
        File=fractionsFile,
        Type="2DHisto",
        Object="h_backgroundFraction_Iso_Medium_mvis_vs_mt_ZJ_Nom"
    )
    fractionsVV  = createRawComponent(
        Name="Fraction_VV_VsMVisMT" ,
        File=fractionsFile,
        Type="2DHisto",
        Object="h_backgroundFraction_Iso_Medium_mvis_vs_mt_VV_Nom"
    )

    fakeFactorsMC.append(
        createCombinedComponent(
            Name="Weight_Combined_"+fakeFactor,
            Form=formCombined,
            W_QCD=findComponent("Weight_QCDSS_"+fakeFactor,fakeFactorsMC),
            W_W=findComponent("Weight_HighMT_"+fakeFactor,fakeFactorsMC),
            #W_Z=findComponent("Weight_ZMuMu_"+fakeFactor,fakeFactorsMC),
            QCD=fractionsQCD,
            W=fractionsW,
            ZJ=fractionsZJ,
            TT=fractionsTT,
            VV=fractionsVV
        )
    )
    fakeFactorsData.append(
        createCombinedComponent(
            Name="Weight_Combined_"+fakeFactor,
            Form=formCombined,
            W_QCD=findComponent("Weight_QCDSS_"+fakeFactor,fakeFactorsData),
            W_W=findComponent("Weight_HighMT_"+fakeFactor,fakeFactorsData),
            #W_Z=findComponent("Weight_ZMuMu_"+fakeFactor,fakeFactorsData),
            QCD=fractionsQCD,
            W=fractionsW,
            ZJ=fractionsZJ,
            TT=fractionsTT,
            VV=fractionsVV
        )
    )
    return [fractionsTT,fractionsW,fractionsVV,fractionsZJ,fractionsQCD]


def createShift(group, name, shift, fractionsFile, fakeFactorsMC, fakeFactorsData):
    #formCombined = '[{W_QCD}]*[{QCD}]+[{W_W}]*([{W}]+[{TT}])+[{W_Z}]*([{ZJ}]+[{VV}])'
    formCombined = '[{W_QCD}]*[{QCD}]+[{W_W}]*([{W}]+[{TT}]+[{ZJ}]+[{VV}])'
    fractionsW   = createRawComponent(
        Name="Fraction_W_VsMVisMT_{SHIFT}".format(SHIFT=shift)  ,
        File=fractionsFile,
        Type="2DHisto",
        Object="h_backgroundFraction_Iso_Medium_mvis_vs_mt_W_{SHIFT}".format(SHIFT=shift)
    )
    fractionsQCD = createRawComponent(
        Name="Fraction_QCD_VsMVisMT_{SHIFT}".format(SHIFT=shift),
        File=fractionsFile,
        Type="2DHisto",
        Object="h_backgroundFraction_Iso_Medium_mvis_vs_mt_QCD_{SHIFT}".format(SHIFT=shift)
    )
    fractionsTT  = createRawComponent(
        Name="Fraction_TT_VsMVisMT_{SHIFT}".format(SHIFT=shift) ,
        File=fractionsFile,
        Type="2DHisto",
        Object="h_backgroundFraction_Iso_Medium_mvis_vs_mt_TT_{SHIFT}".format(SHIFT=shift)
    )
    fractionsZJ  = createRawComponent(
        Name="Fraction_ZJ_VsMVisMT_{SHIFT}".format(SHIFT=shift) ,
        File=fractionsFile,
        Type="2DHisto",
        Object="h_backgroundFraction_Iso_Medium_mvis_vs_mt_ZJ_{SHIFT}".format(SHIFT=shift)
    )
    fractionsVV  = createRawComponent(
        Name="Fraction_VV_VsMVisMT_{SHIFT}".format(SHIFT=shift) ,
        File=fractionsFile,
        Type="2DHisto",
        Object="h_backgroundFraction_Iso_Medium_mvis_vs_mt_VV_{SHIFT}".format(SHIFT=shift)
    )
    ## MC
    fakeFactorCombined = findComponent("Weight_Combined_"+fakeFactor,fakeFactorsMC)
    fakeFactorCombined.addSystematic(
        group,
        name,
        createCombinedComponent(
            Name='',
            Form=formCombined,
            W_QCD=findComponent("Weight_QCDSS_"+fakeFactor,fakeFactorsMC),
            W_W=findComponent("Weight_HighMT_"+fakeFactor,fakeFactorsMC),
            #W_Z=findComponent("Weight_ZMuMu_"+fakeFactor,fakeFactorsMC),
            QCD=fractionsQCD,
            W=fractionsW,
            ZJ=fractionsZJ,
            TT=fractionsTT,
            VV=fractionsVV
        )
    )
    ## Data
    fakeFactorCombined = findComponent("Weight_Combined_"+fakeFactor,fakeFactorsData)
    fakeFactorCombined.addSystematic(
        group,
        name,
        createCombinedComponent(
            Name='',
            Form=formCombined,
            W_QCD=findComponent("Weight_QCDSS_"+fakeFactor,fakeFactorsData),
            W_W=findComponent("Weight_HighMT_"+fakeFactor,fakeFactorsData),
            #W_Z=findComponent("Weight_ZMuMu_"+fakeFactor,fakeFactorsData),
            QCD=fractionsQCD,
            W=fractionsW,
            ZJ=fractionsZJ,
            TT=fractionsTT,
            VV=fractionsVV
        )
    )


def applySys(fakeFactorsMC, fakeFactorsData):
    fractionsFile = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeBackgroundFractions/results/backgroundFraction_Iso_Medium_mvis_vs_mt.root"
    createShift('FractionSys', 'ShiftFractionW_Up'  , 'WUp', fractionsFile, fakeFactorsMC, fakeFactorsData)
    createShift('FractionSys', 'ShiftFractionW_Down', 'WDown', fractionsFile, fakeFactorsMC, fakeFactorsData)
    createShift('FractionSys', 'ShiftFractionQCD_Up'  , 'QCDUp', fractionsFile, fakeFactorsMC, fakeFactorsData)
    createShift('FractionSys', 'ShiftFractionQCD_Down', 'QCDDown', fractionsFile, fakeFactorsMC, fakeFactorsData)
    createShift('FractionSys', 'ShiftFractionTT_Up'  , 'TTUp', fractionsFile, fakeFactorsMC, fakeFactorsData)
    createShift('FractionSys', 'ShiftFractionTT_Down', 'TTDown', fractionsFile, fakeFactorsMC, fakeFactorsData)

def applyStat(fakeFactorsMC, fakeFactorsData):
    fractionsFile = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeBackgroundFractions/results/backgroundFraction_Iso_Medium_mvis_vs_mt.root"
    #fractionsFile = "/home/sauvan/lxwork/Projects/Htautau_Run2/Studies/FakeRate/ComputeBackgroundFractions/results/backgroundFraction_Iso_Medium_mvis_vs_mt.root"
    # Retrieve list of stat shifts
    uncertFile = ROOT.TFile.Open(fractionsFile)
    keys = uncertFile.GetListOfKeys()
    statShiftsW = []
    statShiftsQCD = []
    for key in keys:
        if 'W_WStat' in key.GetName():
            statShiftsW.append(key.GetName())
        elif 'QCD_QCDStat' in key.GetName():
            statShiftsQCD.append(key.GetName())
    uncertFile.Close()
    for statShift in statShiftsW:
        shift = statShift.split('_WStat_')[-1]
        createShift('FractionStat', 'ShiftStatFractionW_{SHIFT}'.format(SHIFT=shift)  , 'WStat_{SHIFT}'.format(SHIFT=shift), fractionsFile, fakeFactorsMC, fakeFactorsData)
    for statShift in statShiftsQCD:
        shift = statShift.split('_QCDStat_')[-1]
        print shift
        createShift('FractionStat', 'ShiftStatFractionQCD_{SHIFT}'.format(SHIFT=shift)  , 'QCDStat_{SHIFT}'.format(SHIFT=shift), fractionsFile, fakeFactorsMC, fakeFactorsData)

