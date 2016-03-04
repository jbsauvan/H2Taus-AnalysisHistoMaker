import rawFakeFactors
import mTCorrectedFakeFactors
import combinedFakeFactors
from FakeFactors import findComponent, listDependencies


data = []
mc = []
rawFakeFactors.create(mc,data)
mtcorr = mTCorrectedFakeFactors.create(mc,data)
combinedFakeFactors.create(mc,data)

rawFakeFactors.applySplitNonClosure(mc,data)
mTCorrectedFakeFactors.applySplitNonClosure(mc,data)
mTCorrectedFakeFactors.applyStat(mtcorr)
mTCorrectedFakeFactors.applyBinSys(mtcorr)
combinedFakeFactors.applySys(mc,data)
#combinedFakeFactors.applyStat(mc,data)

combinedFakeFactor = findComponent('Weight_Combined_Iso_Medium_VsPtDecay', data) 



for comp in combinedFakeFactor.components:
    # 1st level
    for group,sys in comp.systematics.items():
        for s in sys:
            ffsys = combinedFakeFactor.copy()       
            ffsys.replaceComponent(comp,s)
            combinedFakeFactor.addSystematic(group, s.name.replace(comp.name+'_',''), ffsys)
    ## 2nd level
    for comp2 in comp.components:
        for group,sys in comp2.systematics.items():
            for s in sys:
                compsys = comp.copy()       
                compsys.replaceComponent(comp2,s)
                comp.addSystematic(group, s.name.replace(comp2.name+'_',''), compsys)
                ffsys = combinedFakeFactor.copy()       
                ffsys.replaceComponent(comp,compsys)
                combinedFakeFactor.addSystematic(group, s.name.replace(comp2.name+'_',''), ffsys)


allFakeFactors = []
listDependencies(combinedFakeFactor, allFakeFactors)



