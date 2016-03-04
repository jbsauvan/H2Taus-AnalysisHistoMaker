from FakeFactors import createRawComponent, createCombinedComponent, createCombinedSysComponent, findComponent





fakeFactor = 'Iso_Medium_VsPtDecay'

def create(fakeFactorsMC, fakeFactorsData):
    highMTCorrectionFile = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeMTCorrection/results/mtCorrections.root"
    formCorrection = '[{CORR}]*[{RAW}]'
    highMTCorrection = createRawComponent(
        Name="HighMTCorr_VsMT" ,
        File=highMTCorrectionFile,
        Type="1DGraph",
        Object="mt_correction"
    )
    ## MC
    fakeFactorsMC.append(
        createCombinedComponent(
            Name="Weight_HighMT_"+fakeFactor,
            Form=formCorrection,
            CORR=highMTCorrection,
            RAW=findComponent("Weight_HighMTRaw_"+fakeFactor,fakeFactorsMC)
        )
    )
    fakeFactorsMC.append(
        createCombinedComponent(
            Name="Weight_HighMTSS_"+fakeFactor,
            Form=formCorrection,
            CORR=highMTCorrection,
            RAW=findComponent("Weight_HighMTSSRaw_"+fakeFactor,fakeFactorsMC)
        )
    )
    ## Data
    fakeFactorsData.append(
        createCombinedComponent(
            Name="Weight_HighMT_"+fakeFactor,
            Form=formCorrection,
            CORR=highMTCorrection,
            RAW=findComponent("Weight_HighMTRaw_"+fakeFactor,fakeFactorsData)
        )
    )
    fakeFactorsData.append(
        createCombinedComponent(
            Name="Weight_HighMTSS_"+fakeFactor,
            Form=formCorrection,
            CORR=highMTCorrection,
            RAW=findComponent("Weight_HighMTSSRaw_"+fakeFactor,fakeFactorsData)
        )
    )
    return highMTCorrection




def applyNonClosure(fakeFactorsMC, fakeFactorsData):
    nonClosureFile = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/Uncertainties/Closures/results/nonClosures.root"
    nonClosureSSFile = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/Uncertainties/Closures/results/nonClosures_SS.root"
    formShift = '[{SHIFT}]*[{NOM}]'
    nonClosureHighMT = createRawComponent(
        Name="HighMTNonClosure_VsMVis",
        File=nonClosureFile,
        Type="1DGraph",
        Object="HighMT_Histo_Smooth_Ratio"
    )
    nonClosureHighMTSS = createRawComponent(
        Name="HighMTSSNonClosure_VsMVis",
        File=nonClosureSSFile,
        Type="1DGraph",
        Object="HighMTSS_Histo_Smooth_Ratio"
    )
    ## MC
    fakeFactorHighMT = findComponent("Weight_HighMT_"+fakeFactor,fakeFactorsMC)
    fakeFactorHighMT.addSystematic(
        'NonClosure',
        'ShiftNonClosure_HighMT',
        createCombinedComponent(
            Name='',
            Form=formShift,
            SHIFT=nonClosureHighMT,
            NOM=fakeFactorHighMT
        )
    )
    fakeFactorHighMTSS = findComponent("Weight_HighMTSS_"+fakeFactor,fakeFactorsMC)
    fakeFactorHighMTSS.addSystematic(
        'NonClosure',
        'ShiftNonClosure_HighMTSS',
        createCombinedComponent(
            Name='',
            Form=formShift,
            SHIFT=nonClosureHighMTSS,
            NOM=fakeFactorHighMTSS
        )
    )
    ## Data
    fakeFactorHighMT = findComponent("Weight_HighMT_"+fakeFactor,fakeFactorsData)
    fakeFactorHighMT.addSystematic(
        'NonClosure',
        'ShiftNonClosure_HighMT',
        createCombinedComponent(
            Name='',
            Form=formShift,
            SHIFT=nonClosureHighMT,
            NOM=fakeFactorHighMT
        )
    )
    fakeFactorHighMTSS = findComponent("Weight_HighMTSS_"+fakeFactor,fakeFactorsData)
    fakeFactorHighMTSS.addSystematic(
        'NonClosure',
        'ShiftNonClosure_HighMTSS',
        createCombinedComponent(
            Name='',
            Form=formShift,
            SHIFT=nonClosureHighMTSS,
            NOM=fakeFactorHighMTSS
        )
    )

def applyStat(highMTCorrection):
    highMTCorrectionFile = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeMTCorrection/results/mtCorrections.root"
    highMTCorrection.addSystematic(
        'StatMTCorr',
        'ShiftStatMTCorr_Up',
        createRawComponent(
            Name='',
            File=highMTCorrectionFile,
            Type="1DGraph",
            Object="mt_correction_statup"
        )
    )
    highMTCorrection.addSystematic(
        'StatMTCorr',
        'ShiftStatMTCorr_Down',
        createRawComponent(
            Name='',
            File=highMTCorrectionFile,
            Type="1DGraph",
            Object="mt_correction_statdown"
        )
    )

def applyBinSys(highMTCorrection):
    highMTCorrectionFile = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeMTCorrection/results/mtCorrections.root"
    highMTCorrection.addSystematic(
        'BinningMTCorr',
        'ShiftBinningMTCorr_Up',
        createRawComponent(
            Name='',
            File=highMTCorrectionFile,
            Type="1DGraph",
            Object="mt_correction_binup"
        )
    )
    highMTCorrection.addSystematic(
        'BinningMTCorr',
        'ShiftBinningMTCorr_Down',
        createRawComponent(
            Name='',
            File=highMTCorrectionFile,
            Type="1DGraph",
            Object="mt_correction_bindown"
        )
    )
