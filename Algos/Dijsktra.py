import heapq
from collections import *
# general k minimum dijsktra O(K(VLOGV + E))
def dijsktra(src,k,adj): 
        dist = defaultdict(list)
        q = [(0,src)]
        dist[src] = []
        while(q):
            c,u  = heapq.heappop(q) # once pop out we know this is min
            if not dist[u] or dist[u][-1]!=c: dist[u].append(c) # rather than using distance, we use array size as status to know if its optimal or not
            else: continue # required! for time complexity
            for v,w in adj[u]:
                if(len(dist[v]) == k): continue 
                cost = c + w;
                heapq.heappush(q,(cost,v))