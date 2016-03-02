from FakeFactors import createRawComponent, createCombinedComponent, createCombinedSysComponent, findComponent

import ROOT



fakeFactor = 'Iso_Medium_VsPtDecay'

def listRawFakeFactors(fakeFactors):
    rawFakeFactors = []
    for fakeFactor in fakeFactors:
        if fakeFactor.object.Type is 'Combined': continue
        if fakeFactor.object.Object.split('_')[0]!='FakeFactors': continue
        rawFakeFactors.append(fakeFactor)
    return rawFakeFactors


def create(fakeFactorsMC, fakeFactorsData):
    fakeFactors2DMCFileTemplate = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_{TYPE}_2D/FakeFactors_{TYPE}_2D.root"
    fakeFactors2DDataFileTemplate = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_Data_{TYPE}_2D/FakeFactors_Data_{TYPE}_2D.root"
    ### MC fake factors
    fakeFactorsMC.append(
        createRawComponent(
            Name="Weight_ZMuMu_"+fakeFactor,
            File=fakeFactors2DMCFileTemplate.format(TYPE='ZMuMu') ,
            Type="2DHisto",
            Object="FakeFactors_ZMuMu_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"
        )
    )
    fakeFactorsMC.append(
        createRawComponent(
            Name="Weight_HighMTRaw_"+fakeFactor,
            File=fakeFactors2DMCFileTemplate.format(TYPE='HighMT'),
            Type="2DHisto",
            Object="FakeFactors_HighMT_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"
        )
    )
    fakeFactorsMC.append(
        createRawComponent(
            Name="Weight_HighMTSSRaw_"+fakeFactor,
            File=fakeFactors2DMCFileTemplate.format(TYPE='HighMTSS'),
            Type="2DHisto",
            Object="FakeFactors_HighMTSS_2D_SS_Iso_Medium_SS_InvertIso_Medium_tau_pt_vs_decayMode"
        )
    )
    fakeFactorsMC.append(
        createRawComponent(
            Name="Weight_QCDSS_"+fakeFactor,
            File=fakeFactors2DMCFileTemplate.format(TYPE='QCDSS'),
            Type="2DHisto",
            Object="FakeFactors_QCDSS_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"
        )
    )

    ### Data fake factors
    fakeFactorsData.append(
        createRawComponent(
            Name="Weight_ZMuMu_"+fakeFactor,
            File=fakeFactors2DDataFileTemplate.format(TYPE='ZMuMu') ,
            Type="2DHisto",
            Object="FakeFactors_Data_ZMuMu_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"
        )
    )
    fakeFactorsData.append(
        createRawComponent(
            Name="Weight_HighMTRaw_"+fakeFactor,
            File=fakeFactors2DDataFileTemplate.format(TYPE='HighMT'),
            Type="2DHisto",
            Object="FakeFactors_Data_HighMT_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"
        )
    )
    fakeFactorsData.append(
        createRawComponent(
            Name="Weight_HighMTSSRaw_"+fakeFactor,
            File=fakeFactors2DDataFileTemplate.format(TYPE='HighMTSS'),
            Type="2DHisto",
            Object="FakeFactors_Data_HighMTSS_2D_SS_Iso_Medium_SS_InvertIso_Medium_tau_pt_vs_decayMode"
        )
    )
    fakeFactorsData.append(
        createRawComponent(
            Name="Weight_QCDSS_"+fakeFactor,
            File=fakeFactors2DDataFileTemplate.format(TYPE='QCDSS'),
            Type="2DHisto",
            Object="FakeFactors_Data_QCDSS_2D_Iso_Medium_InvertIso_Medium_tau_pt_vs_decayMode"
        )
    )




def applyNonClosure(fakeFactorsMC, fakeFactorsData):
    nonClosureFile = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/Uncertainties/Closures/results/nonClosures.root"
    formShift = '[{SHIFT}]*[{NOM}]'
    ## MC
    #nonClosureZMuMu = createRawComponent(
        #Name="ZMuMuNonClosure_VsMVis",
        #File=nonClosureFile,
        #Type="1DGraph",
        #Object="ZMuMu_Histo_Smooth_Ratio"
    #)
    #fakeFactorZMuMu = findComponent("Weight_ZMuMu_"+fakeFactor,fakeFactorsMC)
    #fakeFactorZMuMu.addSystematic(
        #'NonClosure',
        #'ShiftNonClosure_ZMuMu',
        #createCombinedComponent(
            #Name='',
            #Form=formShift,
            #SHIFT=nonClosureZMuMu,
            #NOM=fakeFactorZMuMu
        #)
    #)
    #
    nonClosureQCDSS = createRawComponent(
        Name="QCDSSNonClosure_VsMVis",
        File=nonClosureFile,
        Type="1DGraph",
        Object="QCDSS_Histo_Smooth_Ratio"
    )
    fakeFactorQCDSS = findComponent("Weight_QCDSS_"+fakeFactor,fakeFactorsMC)
    fakeFactorQCDSS.addSystematic(
        'NonClosure',
        'ShiftNonClosure_QCDSS',
        createCombinedComponent(
            Name='',
            Form=formShift,
            SHIFT=nonClosureQCDSS,
            NOM=fakeFactorQCDSS
        )
    )
    ## Data
    #fakeFactorZMuMu = findComponent("Weight_ZMuMu_"+fakeFactor,fakeFactorsData)
    #fakeFactorZMuMu.addSystematic(
        #'NonClosure',
        #'ShiftNonClosure_ZMuMu',
        #createCombinedComponent(
            #Name='',
            #Form=formShift,
            #SHIFT=nonClosureZMuMu,
            #NOM=fakeFactorZMuMu
        #)
    #)
    #
    fakeFactorQCDSS = findComponent("Weight_QCDSS_"+fakeFactor,fakeFactorsData)
    fakeFactorQCDSS.addSystematic(
        'NonClosure',
        'ShiftNonClosure_QCDSS',
        createCombinedComponent(
            Name='',
            Form=formShift,
            SHIFT=nonClosureQCDSS,
            NOM=fakeFactorQCDSS
        )
    )

def applySplitNonClosure(fakeFactorsMC, fakeFactorsData):
    nonClosureFile = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/Uncertainties/Closures/results/nonClosures_split.root"
    formShift = '[{SHIFT}]*[{NOM}]'
    for i in xrange(4):
        nonClosureQCDSS = createRawComponent(
            Name="QCDSSNonClosure{I}_VsMVis".format(I=i),
            File=nonClosureFile,
            Type="1DGraph",
            Object="QCDSS_Histo_Smooth_Ratio_{I}".format(I=i)
        )
        ## MC
        fakeFactorQCDSS = findComponent("Weight_QCDSS_"+fakeFactor,fakeFactorsMC)
        fakeFactorQCDSS.addSystematic(
            'NonClosure',
            'ShiftNonClosure_QCDSS_{I}'.format(I=i),
            createCombinedComponent(
                Name='',
                Form=formShift,
                SHIFT=nonClosureQCDSS,
                NOM=fakeFactorQCDSS
            )
        )
        ## Data
        fakeFactorQCDSS = findComponent("Weight_QCDSS_"+fakeFactor,fakeFactorsData)
        fakeFactorQCDSS.addSystematic(
            'NonClosure',
            'ShiftNonClosure_QCDSS_{I}'.format(I=i),
            createCombinedComponent(
                Name='',
                Form=formShift,
                SHIFT=nonClosureQCDSS,
                NOM=fakeFactorQCDSS
            )
        )







def applyStat(fakeFactorsMC, fakeFactorsData):
    statUncertDir = '/afs/cern.ch/user/j/jsauvan/Projects/Htautau_Run2/Studies/FakeRate/Uncertainties/FakeFactorStatUncertainties/results/'
    #statUncertDir = '/home/sauvan/lxwork/Projects/Htautau_Run2/Studies/FakeRate/Uncertainties/FakeFactorStatUncertainties/results/'
    formShift = '([{NOM}]+[{SHIFT}])'
    ## MC
    for fakeFactor in listRawFakeFactors(fakeFactorsMC):
        # Retrieve list of stat shifts
        fileName = fakeFactor.object.File.split('/')[-1].replace('.root', '_StatShift.root') 
        uncertFile = ROOT.TFile.Open(statUncertDir+'/'+fileName)
        keys = uncertFile.GetListOfKeys()
        fakeFactorStatShifts = []
        for key in keys:
            if fakeFactor.object.Object in key.GetName():
                fakeFactorStatShifts.append(key.GetName())
        uncertFile.Close()
        # Create bin shift and add uncertainty
        for fakeFactorStatShift in fakeFactorStatShifts:
            extension = fakeFactorStatShift.replace(fakeFactor.object.Object+'_', '')
            binshift = createRawComponent(
                Name=fakeFactor.name+'_BinShift_'+extension,
                File=statUncertDir+'/'+fileName,
                Type=fakeFactor.object.Type,
                Object=fakeFactorStatShift
            )
            fakeFactor.addSystematic(
                'StatFakeFactors',
                'ShiftStatFF_'+extension,
                createCombinedComponent(
                    Name='',
                    Form=formShift,
                    SHIFT=binshift,
                    NOM=fakeFactor
                )
            )
    ## Data
    for fakeFactor in listRawFakeFactors(fakeFactorsData):
        # Retrieve list of stat shifts
        fileName = fakeFactor.object.File.split('/')[-1].replace('.root', '_StatShift.root') 
        uncertFile = ROOT.TFile.Open(statUncertDir+'/'+fileName)
        keys = uncertFile.GetListOfKeys()
        fakeFactorStatShifts = []
        for key in keys:
            if fakeFactor.object.Object in key.GetName():
                fakeFactorStatShifts.append(key.GetName())
        uncertFile.Close()
        # Create bin shift and add uncertainty
        for fakeFactorStatShift in fakeFactorStatShifts:
            extension = fakeFactorStatShift.replace(fakeFactor.object.Object+'_', '')
            binshift = createRawComponent(
                Name=fakeFactor.name+'_BinShift_'+extension,
                File=statUncertDir+'/'+fileName,
                Type=fakeFactor.object.Type,
                Object=fakeFactorStatShift
            )
            fakeFactor.addSystematic(
                'StatFakeFactors',
                'ShiftStatFF_'+extension,
                createCombinedComponent(
                    Name='',
                    Form=formShift,
                    SHIFT=binshift,
                    NOM=fakeFactor
                )
            )

def createZMuMuHighMT(fakeFactorsMC, fakeFactorsData):
    fakeFactors2DMCFileTemplate = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_{TYPE}_2D/FakeFactors_{TYPE}_2D.root"
    fakeFactors2DDataFileTemplate = "/afs/cern.ch/user/j/jsauvan/workspace/Projects/Htautau_Run2/Studies/FakeRate/ComputeFakeRates/plots/FakeFactors_Data_{TYPE}_2D/FakeFactors_Data_{TYPE}_2D.root"
    ### MC fake factors
    fakeFactorsMC.append(
        createRawComponent(
            Name="Weight_ZMuMu_HighMT_"+fakeFactor,
            File=fakeFactors2DMCFileTemplate.format(TYPE='ZMuMu_HighMT') ,
            Type="2DHisto",
            Object="FakeFactors_ZMuMu_HighMT_2D_MTgt70_Iso_Medium_MTgt70_InvertIso_Medium_tau_pt_vs_decayMode"
        )
    )

    ### Data fake factors
    fakeFactorsData.append(
        createRawComponent(
            Name="Weight_ZMuMu_HighMT_"+fakeFactor,
            File=fakeFactors2DDataFileTemplate.format(TYPE='ZMuMu_HighMT') ,
            Type="2DHisto",
            Object="FakeFactors_Data_ZMuMu_HighMT_2D_MTgt70_Iso_Medium_MTgt70_InvertIso_Medium_tau_pt_vs_decayMode"
        )
    )



