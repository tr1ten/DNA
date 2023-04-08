#
# @lc app=leetcode id=1928 lang=python
#
# [1928] Minimum Cost to Reach Destination in Time
#

# @lc code=start
from heapq import heappop as hpop,heappush as hpush
class Solution:
    def minCost(self, mt: int, edges: List[List[int]], P: List[int]) -> int:
        n = len(P)
        time = [float('inf')]*n
        S = 0
        D = n-1
        adj = [[] for i in range(n)]
        for u,v,e in edges:
            adj[u].append((v,e))
            adj[v].append((u,e))
        time[S] = 0
        q = [(P[S],0,S)] # cost , time , node
        while(q):
            c,t,u = hpop(q)
            if(u==D): return c
            for v,_t in adj[u]:
                if( _t+t<=mt and _t+t<time[v] ):
                    time[v] = _t+t
                    hpush(q,(c + P[v],time[v],v))
        return -1
        
# @lc code=end

