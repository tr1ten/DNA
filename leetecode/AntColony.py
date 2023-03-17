# number of topo sorts
class Solution:
    def waysToBuildRooms(self, prevRoom: List[int]) -> int:
        adj  = [[] for i in range(len(prevRoom))]
        for i,x in enumerate(prevRoom):
            if(x==-1): continue
            adj[x].append(i)
        szs = [1 for i in range(len(prevRoom))]
        def pre(u):
            for v in adj[u]:
                pre(v);
                szs[u] += szs[v]
        mod = 10**9 + 7
        @cache
        def dp(u):
            w = 1
            sz = 0
            for v in adj[u]:
                sz += szs[v]    
                w = (w*dp(v)*math.comb(sz,szs[v]))%mod
            return w
        pre(0)
        return dp(0)