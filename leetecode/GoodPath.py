from collections import defaultdict,OrderedDict
class Solution:
    def numberOfGoodPaths(self, vals: List[int], edges: List[List[int]]) -> int:
        d = defaultdict(list)
        adj = [[] for i in range(len(vals))]
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
        for i in range(len(vals)): d[vals[i]].append(i)
        sd = OrderedDict(sorted(d.items(),key=lambda t:t[0]));
        uf = DSU(len(vals))
        res = len(vals)
        for v in sd:
            for u in sd[v]:
                for a in adj[u]:
                    if(vals[a]<=vals[u]): uf.union(u,a)
            cnt = defaultdict(int)
            for u in sd[v]:
                cnt[uf.find(u)] +=1
            for k,v in cnt.items():
                res += v*(v-1)//2;
        return res;
            
    
    
class DSU:
    def __init__(self, N):
        self.par = list(range(N))
        self.sz = [1] * N

    def find(self, x):
        if self.par[x] != x:
            self.par[x] = self.find(self.par[x])
        return self.par[x]

    def union(self, x, y):
        xr, yr = self.find(x), self.find(y)
        if xr == yr:
            return False
        if self.sz[xr] < self.sz[yr]:
            xr, yr = yr, xr
        self.par[yr] = xr
        self.sz[xr] += self.sz[yr]
        return True