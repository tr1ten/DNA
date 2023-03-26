class Solution:
    def collectTheCoins(self, coins: List[int], edges: List[List[int]]) -> int:
        n = len(coins)
        if(not edges): return 0
        if(coins,count(1)<2): return 0
        adj = [[] for x in range(n)]
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
        s0 = coins.index(1)
        s1 = adj[s0][0] # any random vertex
        s2 =-1
        for x in adj[s1]:
            if(x!=s0):
                s2 = x
                break
        if(s2==-1): return 0
        # print(s1,s2
        def greed(u,p):
            # print(u,p)
            cnc = 2 if coins[u] else 3
            ed = 0
            for v in adj[u]:
                if(v==p): continue
                d,e = greed(v,u)
                cnc = min(d,cnc)
                ed +=e
            if(cnc==0): return (0,ed+1)
            return (cnc-1,ed)
        a,b = greed(s2,-1)
        return b if(a==0) else 0