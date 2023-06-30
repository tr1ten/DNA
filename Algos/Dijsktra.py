import heapq
from collections import *
# general k minimum dijsktra O(K(VLOGV + E))


def dijsktra(src, k, adj):
    dist = defaultdict(list)
    q = [(0, src)]
    dist[src] = []
    while (q):
        # once pop out we know this is min, first pop u is always min
        c, u = heapq.heappop(q)
        if not dist[u] or (len(dist[u]) < k and dist[u][-1] != c):
            # rather than using distance, we use array size as status to know if its optimal or not
            dist[u].append(c)
        else:
            continue  # required! for time complexity
        for v, w in adj[u]:
            if (len(dist[v]) == k):
                continue
            cost = c + w
            heapq.heappush(q, (cost, v))
    return dist


def dijsktra(src, adj):
    n = len(adj)
    dist = [float('inf')]*n
    par = [i for i in range(n)]
    q = [(0, src)]
    dist[src] = 0
    par[src] = 0
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


import heapq
def dijsktra(adj,S,K):
    N = len(adj)
    dq = []
    dist = [[float('inf')]*(K+1) for i in range(N)]
    for i in range(K+1): dist[S][i] = 0
    dq = [(0,0,0)] # no skip
    while(dq):
        cost,u,k = heapq.heappop(dq)
        if dist[u][k]<cost: continue
        # if k==K: continue
        for v,c in adj[u]:
            if dist[v][k]>dist[u][k] + c:
                dist[v][k] = dist[u][k]+c; # no skip
                heapq.heappush(dq,(dist[v][k],v,k))
            if k+1<=K and dist[v][k+1]>dist[u][k]: # skip
                dist[v][k+1] = dist[u][k];
                heapq.heappush(dq,(dist[v][k+1],v,k+1))
    return dist
def main():
    N,M,K = map(int,input().split())
    adj = [[] for i in range(N)]
    for i in range(M):
        u,v,c = map(int,input().split())
        adj[u-1].append((v-1,c))
        adj[v-1].append((u-1,c))
    dist = dijsktra(adj,0,K)
    print(" ".join(map(lambda x:str(x[-1]),dist)))