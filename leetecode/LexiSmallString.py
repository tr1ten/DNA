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

class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        ds = DSU(26);
        for x,y in zip(s1,s2):
            ds.union(ord(x)-ord('a'),ord(y)-ord('a'))
        res = ""
        for x in baseStr:
            
            for i in range(26):
                if(ds.find(i)==ds.find(ord(x)-ord('a'))):
                    res += chr(ord('a')+i)
                    break;
        return res
                    
