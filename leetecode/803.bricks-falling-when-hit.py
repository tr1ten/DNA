#
# @lc app=leetcode id=803 lang=python3
#
# [803] Bricks Falling When Hit
#

# @lc code=start
class Solution:
    def hitBricks(self, grid: List[List[int]], hits: List[List[int]]) -> List[int]:
        n,m = len(grid),len(grid[0])
        master = n*m
        def cvt(x,y):
            return y*n + x
        ds = DSU(n*m +1)
        # first apply all operation 
        for y,x in hits:
            grid[y][x] = 0
        dx,dy =  [0,0,-1,1], [1,-1,0,0]
        for i in range(n):
            for j in range(m):
                if i == 0: ds.union(cvt(j,i),master)
                for k in range(4):
                    y,x=i+dy[k],j+dx[k]
                    if(y>=0 and x>=0 and x<m and y<n): ds.union(cvt(j,i),cvt(x,y))
        for i,j in reversed(hits):
            print(ds.sz[ds.find(master)])
            for k in range(4):
                    y,x=i+dy[k],j+dx[k]
                    if(y>=0 and x>=0 and x<m and y<n): ds.union(cvt(j,i),cvt(x,y))
            print(ds.sz[ds.find(master)])
        return []
            
            
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
# @lc code=end

