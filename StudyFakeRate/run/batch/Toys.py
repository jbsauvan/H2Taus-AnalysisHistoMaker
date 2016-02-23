import copy


fluctuatedFakeFactors = []

def addFluctuatedRawFakeFactors(fakeFactors, ntoys=200):
    for name,fakeFactor in fakeFactors.items():
        if not 'Shift' in name:
            for i in xrange(ntoys):
                ffCopy = copy.deepcopy(fakeFactor)
                ffCopy.Name += "_Fluctuate{}".format(i)
                fakeFactors[name+"_Fluctuate{}".format(i)] = ffCopy
                if not fakeFactor.Name in fluctuatedFakeFactors: fluctuatedFakeFactors.append(fakeFactor.Name)

def addFluctuatedCombinedFakeFactors(fakeFactors, ntoys=200):
    for name,fakeFactor in fakeFactors.items():
        if not 'Shift' in name:
            for i in xrange(ntoys):
                ffCopy = copy.deepcopy(fakeFactor)
                ffCopy.Name += "_Fluctuate{}".format(i)
                for raw in fluctuatedFakeFactors:
                    ffCopy.Object = ffCopy.Object.replace(raw, raw+"_Fluctuate{}".format(i))
                fakeFactors[name+"_Fluctuate{}".format(i)] = ffCopy
                if not fakeFactor.Name in fluctuatedFakeFactors: fluctuatedFakeFactors.append(fakeFactor.Name)
