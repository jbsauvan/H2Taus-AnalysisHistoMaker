import copy

class Object:
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
    
    def __eq__(self,other):
        return  self.Name==other.Name and self.File==other.File and self.Type==other.Type and self.Object==other.Object


class Component:
    def __init__(self):
        self.name = ''
        self.object = None
        self.isSystematics = False
        self.components = []
        self.systematics = {}
        self.combined = []

    def copy(self):
        comp = Component()
        comp.name = self.name
        comp.object = copy.deepcopy(self.object)
        comp.isSystematics = self.isSystematics
        return comp

    def replaceComponent(self,old,new):
        for i,comp in enumerate(self.components):
            if comp==old: 
                self.components[i] = new
        self.object.Object = self.object.Object.replace('[{}]'.format(old.name), '[{}]'.format(new.name))

    def addSystematic(self, group, name, sys):
        sys.name = self.name+'_'+name
        sys.object.Name = sys.name
        sys.isSystematics = True
        if not group in self.systematics: self.systematics[group] = []
        if sys in self.systematics[group]: return
        self.systematics[group].append(sys)
        #for combined in self.combined:
            #if component==combined: continue # don't loop infinitely
            #if combined.isSystematics: continue # don't apply systematics to systematics
            #print 1
            ##print combined
            #print '>>>> Combined tree'
            #combined.printCombinedTree()
            #print '>>>> Sys tree'
            #combined.printSysTree()

            #combinedsys = copy.deepcopy(combined)
            #print 2
            #combinedsys.replaceComponent(self, component)
            #print 3
            #combinedsys.systematics = {}
            #component.combined.append(combinedsys)
            #combined.addSystematic(group, name, combinedsys, level+1)

    #def addSystematic(self, group, name, component, level=0):
        #component.name = self.name+'_'+name
        #component.object.Name = component.name
        #component.isSystematics = True
        #if level==0:
            #print '___________________________________________________'
        #print 'Level ', level
        ##print 'Adding systematic'
        ##print component
        ##print 'to'
        ##print self
        #if not group in self.systematics: self.systematics[group] = []
        #if component in self.systematics[group]: return
        #self.systematics[group].append(component)
        ## Propagate to all combined components
        #print '>> Combined tree'
        #self.printCombinedTree()
        #print '>> Sys tree'
        #self.printSysTree()
        #print '>> Comp tree'
        #self.printComponentTree()
        #for combined in self.combined:
            #if component==combined: continue # don't loop infinitely
            #if combined.isSystematics: continue # don't apply systematics to systematics
            #print 1
            ##print combined
            #print '>>>> Combined tree'
            #combined.printCombinedTree()
            #print '>>>> Sys tree'
            #combined.printSysTree()

            #combinedsys = copy.deepcopy(combined)
            #print 2
            #combinedsys.replaceComponent(self, component)
            #print 3
            #combinedsys.systematics = {}
            #component.combined.append(combinedsys)
            #combined.addSystematic(group, name, combinedsys, level+1)


    def printComponentTree(self, level=1):
        print '|'*level, self.name
        for comp in self.components:
            comp.printComponentTree(level+1)

    def printCombinedTree(self, level=1):
        print '|'*level, self.name
        for comb in self.combined:
            comb.printCombinedTree(level+1)

    def printSysTree(self, level=1):
        print '|'*level, self.name
        for sys in self.systematics.values():
            for s in sys:
                s.printSysTree(level+1)

    def __str__(self):
        return self.object.__str__()

    def __eq__(self,other):
        return self.object==other.object




def createRawComponent(**args):
    object = Object()
    object.Name   = args.get('Name', '')
    object.File   = args.get('File', '')
    object.Type   = args.get('Type', '')
    object.Object = args.get('Object', '')
    #
    component = Component()
    component.name = args.get('Name', '')
    component.object = object
    return component


def createCombinedComponent(**args):
    names = {}
    components = []
    for key,value in args.items():
        if key is 'Name': continue
        if key is 'Form': continue
        names[key] = value.name
        components.append(value)
    object = Object()
    object.Name   = args.get('Name', '')
    object.File   = ''
    object.Type   = 'Combined'
    object.Object = args.get('Form',None).format(**names)
    #
    component = Component()
    component.name = args.get('Name', '')
    component.object = object
    component.components = components
    for comp in components:
        comp.combined.append(component)
    return component

def createCombinedSysComponent(**args):
    names = {}
    components = []
    for key,value in args.items():
        if key is 'Name': continue
        if key is 'Form': continue
        names[key] = value.name
        components.append(value)
    object = Object()
    object.Name   = args.get('Name', '')
    object.File   = ''
    object.Type   = 'Combined'
    object.Object = args.get('Form',None).format(**names)
    #
    component = Component()
    component.name = args.get('Name', '')
    component.object = object
    component.components = components
    component.isSystematics = True
    return component


def findComponent(name, components):
    for component in components:
        if name==component.name:
            return component
    raise StandardError('Cannot find component '+name)


def listDependencies(fakeFactor,dependencies):
    if fakeFactor in dependencies: return
    dependencies.append(fakeFactor)
    for syss in fakeFactor.systematics.values():
        for sys in syss:
            listDependencies(sys,dependencies)
    for comp in fakeFactor.components:
        listDependencies(comp,dependencies)


