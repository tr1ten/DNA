class Solution:
    def minimumEffortPath(self, grid: List[List[int]]) -> int:
        n,m=len(grid),len(grid[0])
        maxs = [[float('inf')]*m for i in range(n)]
        q = []
        maxs[0][0] = 0
        q.append((0,0,0))
        while(q):
            d,x,y = heapq.heappop(q)
            if(d>maxs[y][x]): continue
            for nx,ny in [(x+dx,y+dy) for dx,dy in zip([0,0,1,-1],[1,-1,0,0])]:
                if(nx<0 or nx>=m or ny>=n or ny<0): continue
                d = max(maxs[y][x],abs(grid[y][x]-grid[ny][nx]))
                if(d>=maxs[ny][nx]): continue
                maxs[ny][nx] = d
                heapq.heappush(q,(d,nx,ny))
        return maxs[-1][-1]     