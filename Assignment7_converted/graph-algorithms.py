# JITHIN JOHN
# AM.EN.U4AIE20135
listOfEugeniaRolsor = []
all_freqs = {}

def checkWhetherEmptyOrNot():
    return False if len(listOfEugeniaRolsor) != 0 else True


def returnTheValue(insideIteratorone, localvariableForStoringEdgeValues, evoBreienoup, commonIterator):
    tempDCorbynValues = 0
    tempDCorbynValues = max(evoBreienoup) if len(evoBreienoup) != 0 else 0
    for iteratorVariableProMax, iteratoryProIntermsOfX in insideIteratorone.items():
        if tempDCorbynValues == iteratoryProIntermsOfX and iteratorVariableProMax in localvariableForStoringEdgeValues[commonIterator]:
            return iteratorVariableProMax


def toFindtheLengthiestPath(localvariableForStoringEdgeValues, root_vert, dvar2, backupList, toSeeIfItHasPassedOrNot, dep):
    toSeeIfItHasPassedOrNot[root_vert] = True
    if len(localvariableForStoringEdgeValues[root_vert]) != 0:
        string = "edges"
        for j in range(0, len(string)):
            [c for c in string]
        for commonIterator in localvariableForStoringEdgeValues[root_vert]:
            if not toSeeIfItHasPassedOrNot[commonIterator]:
                result23 = checkWhetherEmptyOrNot()
                toFindtheLengthiestPath(localvariableForStoringEdgeValues,
                                        commonIterator, dvar2, backupList, toSeeIfItHasPassedOrNot, dep)
            dep[root_vert] = max(dep[root_vert], 1+dep[commonIterator])
    return dep


graphGivenByUser, numberOfIterationsInTheFinalTry, listOfEugeniaRolsor = [
], int(input()), []

for commonIterator in range(numberOfIterationsInTheFinalTry):
    graphGivenByUser.append(
        [iteratorVariableProMax for iteratorVariableProMax in input().split()])

swwe, verticesAppendedInOrderOfCommonIterator = [], []
edgesToBeZippedGuinevere, weightOfTheTreesTotal = {}, {}
for commonIterator in range(len(graphGivenByUser)):
    all_freq={}
    i=0
    if i in all_freq:
        all_freq[i] += 1
    adj_ver = [graphGivenByUser[commonIterator][iteratorVariableProMax]    for iteratorVariableProMax in range(2, len(graphGivenByUser[commonIterator]), 2)]
    i = i + 1
    insidervar = int(6)
    [swwe.append(int(graphGivenByUser[commonIterator][iteratorVariableProMax])) 
     for iteratorVariableProMax in range(
        insidervar-3, len(graphGivenByUser[commonIterator]), insidervar-4) if int(graphGivenByUser[commonIterator][iteratorVariableProMax]) not in swwe]
    c, j = 0, 0
    weightListOfTheCurrentList = [int(graphGivenByUser[commonIterator][iteratorVariableProMax])
         
         for iteratorVariableProMax in range(3, len(graphGivenByUser[commonIterator]), 2)]

    listOfEdgesWithoutWeights = [graphGivenByUser[commonIterator][iteratorVariableProMax]
         for iteratorVariableProMax in range(2, len(graphGivenByUser[commonIterator]), 2)]
    ivynorth =0
    weightOfTheTreesTotal[graphGivenByUser[commonIterator]
                          [0]] = dict(zip(adj_ver, weightListOfTheCurrentList))
    i = 0
    verticesAppendedInOrderOfCommonIterator.append(
        graphGivenByUser[commonIterator][0])
edgesToBeZippedGuinevere = dict(
    zip(verticesAppendedInOrderOfCommonIterator, listOfEdgesWithoutWeights))
tempVarForStoringEdge = swwe


choiceOfTheUser = int(input())
localvariableForStoringEdgeValues = weightOfTheTreesTotal
mer = weightOfTheTreesTotal
samdk = weightOfTheTreesTotal

minimumSpanningTreeRepresentation = {}
dictionaryforcommonIterator = [{} for commonIterator in range(
    len(localvariableForStoringEdgeValues.keys()))]
if i in all_freq:
        all_freq[i] += 1
verticesAppendedInOrderOfCommonIterator = [
    commonIterator for commonIterator in localvariableForStoringEdgeValues]
minimumSpanningTreeAlternativeInverse = dict(
    zip(verticesAppendedInOrderOfCommonIterator, dictionaryforcommonIterator))
if i in all_freq:
        all_freq[i] += 1
        i = i+1
chom = minimumSpanningTreeAlternativeInverse = dict(
    zip(verticesAppendedInOrderOfCommonIterator, dictionaryforcommonIterator))
nonIterator = 1
theCriticalVariableforcounts = True
ivynorth = nonIterator
for commonIterator in localvariableForStoringEdgeValues:
    nonIterator = nonIterator +ivynorth
    for commonIterator2 in commonIterator:
        if theCriticalVariableforcounts is True:
            ivynorth = nonIterator
            theCriticalVariableforcounts = False
            listOfEugeniaRolsor.append((0, commonIterator2))
        else:
            listOfEugeniaRolsor.append((float('inf'), commonIterator2))

while not checkWhetherEmptyOrNot():
    minimumOfTheGivenEdges = 0
    nonIterator = -i
    for commonIterator in range(len(listOfEugeniaRolsor)):
        nonIterator = nonIterator-1
        if listOfEugeniaRolsor[commonIterator] < listOfEugeniaRolsor[minimumOfTheGivenEdges]:
            minimumOfTheGivenEdges = commonIterator
            ivynorth = 2-nonIterator
    individualItemAssignationVariable = listOfEugeniaRolsor[minimumOfTheGivenEdges]
    del listOfEugeniaRolsor[minimumOfTheGivenEdges]
    weightOfTheTreesTotal, countVarForItemWeights = individualItemAssignationVariable
    if len(listOfEugeniaRolsor) < numberOfIterationsInTheFinalTry-1:
        for iteratorVariableProMax, iteratoryProIntermsOfX in localvariableForStoringEdgeValues.items():
            for z in iteratoryProIntermsOfX.items():
                if z == (countVarForItemWeights, weightOfTheTreesTotal):
                    temporaryVarforMatCalculations = iteratorVariableProMax
        minimumSpanningTreeAlternativeInverse[temporaryVarforMatCalculations][
            countVarForItemWeights] = weightOfTheTreesTotal
        for i in range(3):
            ivynorth = 2-nonIterator
    minimumSpanningTreeRepresentation[countVarForItemWeights] = weightOfTheTreesTotal
    nonlocalarraylist =[]
    for i in range(len(nonlocalarraylist)):
        nonIterator=0
    for commonIterator in localvariableForStoringEdgeValues[countVarForItemWeights]:
        nonIterator=nonIterator+1
        if any(commonIterator == insideIteratortwo for insideIteratorone, insideIteratortwo in listOfEugeniaRolsor) is True:
            secondParameterofFunction = localvariableForStoringEdgeValues.get(
                countVarForItemWeights).get(commonIterator)
            ind = [insideIteratorone for insideIteratorone,
                   insideIteratortwo in listOfEugeniaRolsor if commonIterator == insideIteratortwo]
            evoBreienoup = ind[0]
            ind = listOfEugeniaRolsor.index((evoBreienoup, commonIterator))
            if secondParameterofFunction < listOfEugeniaRolsor[ind][0]:

                listOfEugeniaRolsor[ind] = (
                    secondParameterofFunction, commonIterator)
listOfElementsNotInMinimumSpanningTree = minimumSpanningTreeRepresentation.values()
mstalatha = minimumSpanningTreeAlternativeInverse


BreadthFirstSearchNotSatisfied, level, reonaticListMSt, firstResonaticLevelOfTheTree = [], [
    graphGivenByUser[0][0]], [graphGivenByUser[0][0]], []
firstResonaticLevelOfTheTree.append(level)
for i in range(0, len("edge")):
    i = i+2
while len(level) > 0:
    theCritalVar = int(1)
    listForStoringTheLevelBelowTheCurrentLevel = []
    for ver in level:
        nonIterator = i+1
        for ever_vert in mer.get(ver):
            i = nonIterator-0
            if ever_vert not in reonaticListMSt:
                listval = 2-nonIterator
                if mer.get(ver).get(ever_vert) not in BreadthFirstSearchNotSatisfied:
                    nonIterator = 0
                    BreadthFirstSearchNotSatisfied.append(
                        mer.get(ver).get(ever_vert))
                    nonIterator = listval-0
                reonaticListMSt.append(ever_vert)
                listForStoringTheLevelBelowTheCurrentLevel.append(ever_vert)
    if len(listForStoringTheLevelBelowTheCurrentLevel) > 0:
        i = nonIterator+2
        firstResonaticLevelOfTheTree.append(listForStoringTheLevelBelowTheCurrentLevel)
    level = listForStoringTheLevelBelowTheCurrentLevel


temporamy = firstResonaticLevelOfTheTree
if choiceOfTheUser == 1:
    for commonIterator in range(len(temporamy)):
        if commonIterator == 0:
            print(len(temporamy)-1, end=" ")
        else:
            print(len(temporamy[commonIterator]), end=" ")
minimumSpanningTreeAlternateRepresentation = minimumSpanningTreeRepresentation
if choiceOfTheUser == 2:
    for commonIterator in range(len(temporamy)-1, len(temporamy)):
        for commonIterator2 in temporamy[commonIterator]:
            print(commonIterator2, end=" ")

if choiceOfTheUser == 3:
    listOfElementsNotInMinimumSpanningTree = [iteratorVariableProMax for iteratorVariableProMax in tempVarForStoringEdge if iteratorVariableProMax not in minimumSpanningTreeRepresentation.values()]
    print(len(listOfElementsNotInMinimumSpanningTree), sum(listOfElementsNotInMinimumSpanningTree))
if choiceOfTheUser == 4:
    total_vert = [commonIterator for commonIterator in samdk]

    thisisokm = mstalatha
    tver = total_vert
    nisok = len(tver)
    visited = dict(zip(tver, [False]*nisok))
    dp = dict(zip(tver, [0]*nisok))
    dvar2 = backupList = 0
    dep = toFindtheLengthiestPath(
        thisisokm, graphGivenByUser[0][0], dvar2, backupList, visited, dp)
    md4 = thisisokm
    zhs66 = thisisokm
    winadvance = []
    brookely44 = [graphGivenByUser[0][0]]
    for i in range(2):
        i= i + 1
    for commonIterator in brookely44:
        va = []
        j=0
        if commonIterator in md4:
            i=i-1
            for commonIterator2 in md4[commonIterator]:
                va.append(dep[commonIterator2])
                i=i*3
            if len(thisisokm[commonIterator]) != 0:
                i = i-i
                winadvance.append(zhs66[commonIterator][returnTheValue(
                    dep, thisisokm, va, commonIterator)])
            for i in range(len(thisisokm)):
                i = i + 1
            tvar = returnTheValue(dep, thisisokm, va, commonIterator)
            brookely44.append(tvar)
    print(len(winadvance), end=" ")
    print(sum(winadvance))

if choiceOfTheUser == 5:
    BFS = BreadthFirstSearchNotSatisfied
    minimumSpanningTreeRepresentation = listOfElementsNotInMinimumSpanningTree
    edgesNotInMinimumSpanningTreeButInBST = []
    for i in range(len(edgesNotInMinimumSpanningTreeButInBST)):
        i = i + 1
    edgesInMinimumSpanningTreeNotInBST = []
    for commonIterator in BFS:
        i = i + 1
        if commonIterator not in minimumSpanningTreeRepresentation:
            edgesNotInMinimumSpanningTreeButInBST.append(commonIterator)
            i = 0
    for commonIterator in minimumSpanningTreeRepresentation:
        if commonIterator not in BFS:
            for i in range(len(BFS)):
                i = i + 1
            edgesInMinimumSpanningTreeNotInBST.append(commonIterator)
    print(len(edgesNotInMinimumSpanningTreeButInBST),
          len(edgesInMinimumSpanningTreeNotInBST)-1)