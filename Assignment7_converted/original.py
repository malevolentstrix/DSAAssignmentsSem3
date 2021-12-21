n=int(input())
def get_key(g,k):
  for x,y in g.items():
    for z in y.items():
      if z==k:
        return x
def get_value(a,g,val,i):
    d=0
    if len(val)!=0:
        d=max(val)
    for x, y in a.items():
        if d == y and x in g[i]:
            return x
def update_val(pr, vert):
    ind =[a for a,b in pr if vert==b]
    return ind[0]
pr = []
def isEmpty():
    if len(pr) == 0:
       return True
    else:
        return False
def update_key(val,wt1,ind):
    pr[ind]=(wt1,val)
    return 0
def insert(data,val):
    pr.append((data,val))
def pop():
        min = 0
        for i in range(len(pr)):
              if  pr[i] < pr[min] :
                   min= i
        item = pr[min]
        del pr[min]
        return item
def main():
    graph=[]
    for i in range(n):
        graph.append([x for x in input().split()])
    return graph
def incident_edges(graph):
    edges=[]
    wt={}
    for i in range(len(graph)):
        adj_ver=[graph[i][x] for x in range(2,len(graph[i]),2)]
        [edges.append(int(graph[i][x])) for x in range(3,len(graph[i]),2) if int(graph[i][x]) not in edges]
        W=[int(graph[i][x]) for x in range(3,len(graph[i]),2)]
        wt[graph[i][0]]=dict(zip(adj_ver,W))
    return wt,edges
def BFS(root_vert,in_edg):
    not_BFS=[]
    level=[root_vert]
    visit=[]
    total_levels=[]
    visit.append(root_vert)
    total_levels.append(level)
    while len(level)>0:
        next_levl=[]
        for ver in level:
            for ever_vert in in_edg.get(ver):
                 if ever_vert not in visit:
                     if in_edg.get(ver).get(ever_vert) not in not_BFS:
                         not_BFS.append(in_edg.get(ver).get(ever_vert))
                     visit.append(ever_vert)
                     next_levl.append(ever_vert)
        if len(next_levl)>0:
            total_levels.append(next_levl)
        level=next_levl
    return not_BFS,total_levels

def prims(g,n):
    MST = {}
    dic=[{} for i in range(len(g.keys()))]
    vert=[i for i in g]
    MST_1=dict(zip(vert,dic))
    flag = True
    for i in g:
        for j in i:
            if flag is True:
                flag = False
                insert(0, j)
            else:
                insert(float('inf'), j)
    while not isEmpty():
        wt, v = pop()
        if len(pr)<n-1:
            MST_1[get_key(g,(v, wt))][v] = wt
        MST[v] = wt
        for i in g[v]:
            if any(i == b for a, b in pr) is True:
                wt1 = g.get(v).get(i)
                val = update_val(pr, i)
                ind = pr.index((val, i))
                if wt1 < pr[ind][0]:
                    update_key(i, wt1, ind)
    return MST_1,MST,MST.values()
def long_path(g,root_vert,visit,dep):
    visit[root_vert] =True
    if len(g[root_vert])!=0:
      for i in g[root_vert]:
        if not visit[i]:
            long_path(g, i, visit, dep)
        dep[root_vert]=max(dep[root_vert],1+dep[i])
    return dep
def long_path__weight(MST,n,total_vert):
    visited=dict(zip(total_vert,[False]*n))
    dp = dict(zip(total_vert,[0]*n))
    dep=long_path(MST,graph[0][0],visited,dp)
    g1 = g2 = MST
    a1 = [graph[0][0]]
    total_wt = []
    for i in a1:
        va = []
        if i in g1:
            for j in g1[i]:
                va.append(dep[j])
            if len(MST[i])!=0:
                total_wt.append(g2[i][get_value(dep, MST, va, i)])
            a1.append(get_value(dep, MST, va, i))
    print(len(total_wt),sum(total_wt))
def opt1(g):
    print(len(g)-1,end=" ")
    for i in range(1,len(g)):
        print(len(g[i]),end=" ")
def opt2(g):
    for i in range(len(g)-1, len(g)):
        for j in g[i]:
            print(j,end=" ")
def opt3(MST,edge):
    not_MST=[]
    [not_MST.append(x) for x in edge if x not in MST.values()]
    print(len(not_MST),sum(not_MST))
def opt4(MST,g):
    total_vert=[i for i in g]
    long_path__weight(MST, len(total_vert), total_vert)
def opt5(BFS,MST):
    BFS_not_in_MST=[]
    MST_not_in_BFS=[]
    for i in BFS:
        if i not in MST:
            BFS_not_in_MST.append(i)
    for i in MST:
        if i not in BFS:
            MST_not_in_BFS.append(i)
    print(len(BFS_not_in_MST),len(MST_not_in_BFS)-1)
graph=main()
vert_wts,edge=incident_edges(graph)
MST_1,MST,not_MST=prims(vert_wts,n)
op=int(input())
if op==1:
    opt1(BFS(graph[0][0], vert_wts)[1])
if op==2:
    opt2(BFS(graph[0][0], vert_wts)[1])
if op==3:
    opt3(MST,edge)
if op==4:
    print(MST_1)
    opt4(MST_1,vert_wts)
if op==5:
    opt5(BFS(graph[0][0], vert_wts)[0],not_MST)