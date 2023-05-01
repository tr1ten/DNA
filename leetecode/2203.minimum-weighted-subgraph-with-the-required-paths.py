#
# @lc app=leetcode id=2203 lang=python3
#
# [2203] Minimum Weighted Subgraph With the Required Paths
#

# @lc code=start
import heapq
class Solution:
    def minimumWeight(self, n: int, edges: List[List[int]], s1: int, s2: int, dest: int) -> int:
        adj1 = [[] for i in range(n)]
        adj2 = [[] for i in range(n)]
        for u,v,w in edges:
            adj1[u].append((v,w))
            adj2[v].append((u,w))
        def dijsktra(src,adj):
            dist = [float('inf')]*n
            q = [(0,src)]
            dist[src] = 0
            while(q):
                c,u  = heapq.heappop(q)
                if c>dist[u]: continue
                for v,w in adj[u]:
                    if dist[v] > dist[u]+w:
                        dist[v] = dist[u] + w;
                        heapq.heappush(q,(dist[v],v))
            return dist
        ds1 = dijsktra(s1,adj1)
        ds2 = dijsktra(s2,adj1)
        dd = dijsktra(dest,adj2)
        res = float('inf')
        for i in range(n):
            res = min(res,ds1[i] + ds2[i] + dd[i])
        return -1 if res==float('inf') else res
        
        
                        
            
        
# @lc code=end

