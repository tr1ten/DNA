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
