from collections import deque
import heapq
def dijsktra(src, adj):
    n = len(adj)
    dist = [float('inf')]*n
    par = [i for i in range(n)]
    q = [(0, src)]
    dist[src] = 0
    par[src] = src
    while (q):
        c, u = heapq.heappop(q)
        if c > dist[u]:
            continue
        for v, w in adj[u]:
            if dist[v] > dist[u]+w:
                dist[v] = dist[u] + w
                par[v] = u;
                heapq.heappush(q, (dist[v], v))
    return dist,par

def leaves(u,p,adj):
    q= deque()
    q.append(u)
    ret = []
    vis = set([u,p])
    while q:
        lvl = []
        sz = len(q)
        for  i in range(sz):
            v = q.popleft()
            lvl.append(v)
            for u,w in adj[v]:
                if u not in vis: 
                    q.append(u)
                    vis.add(u)
        ret = lvl
    return ret
def solve(edges):
    n = len(edges) +1
    adj = [[] for i in range(n)]
    for u,v in edges:
        u -=1
        v -=1
        adj[u].append((v,1))
        adj[v].append((u,1))
    d,_ = dijsktra(0,adj)
    v1 = d.index(max(d))
    d2,par = dijsktra(v1,adj)
    v2 = d2.index(max(d2))
    path = [v2]
    while par[path[-1]]!=path[-1]:
        path.append(par[path[-1]])
    res = [0]*n
    mid = len(path)//2
    print(v1,v2,path)
    if len(path)%2==0:
        c1,c2 = path[mid-1],path[mid]
        for v in leaves(c1,c2,adj) + leaves(c2,c1,adj):
            res[v] = 1
    else:
        c1 = path[mid]
        for v in leaves(c1,c1,adj):
            res[v] = 1
        
    return res

print(solve([[1,2],[2,3],[3,4],[3,5],[1,6],[1,7]]))
print(solve([[2,1]] ))