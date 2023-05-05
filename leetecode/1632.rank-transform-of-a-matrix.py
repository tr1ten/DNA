import heapq
class Solution:
    def matrixRankTransform(self, mat: List[List[int]]) -> List[List[int]]:
        n,m = len(mat),len(mat[0])
        el = defaultdict(list)
        for i in range(n):
            for j in range(m): el[mat[i][j]].append((i,j))
        res = [[0]*m for i in range(n)]
        rank = [0]*(n+m)
        for x in sorted(el):
            g = [i for i,j in el[x]] + [j+n for i,j in el[x]]
            ds = DSU(g)
            for i,j in el[x]: ds.union(i,j+n)
            for group in ds.groups():
                rk = max([rank[i] for i in group])
                for i in group:
                    rank[i] = rk+1
            for i,j in el[x]:
                res[i][j] = max(rank[i],rank[j+n])
        return  res


class DSU:
    def __init__(self, g):
        self.g = g
        self.par = {i:i for i in g}
        self.sz = defaultdict(lambda :1)

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
    def groups(self):
        res = defaultdict(list)
        for i in self.g:
            res[self.find(i)].append(i)
        return res.values()
