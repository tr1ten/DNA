from collections import deque
class Solution:
    def maximumMinutes(self, grid: List[List[int]]) -> int:
        n,m = len(grid),len(grid[0])
        def bfs(starts):
            dq = deque()
            fd = [[float('inf')]*m for i in range(n)]
            for i,j in starts:
                fd[i][j] = 0
                dq.append((i,j,0))
            while(dq):
                i,j,s = dq.popleft()
                for dy,dx in [(-1,0),(1,0),(0,1),(0,-1)]:
                    y,x = dy+i,dx+j
                    if(x>=0 and y>=0 and x<m and y<n and grid[y][x]==0 and fd[y][x]>s+1):
                        fd[y][x] = s+1
                        dq.append((y,x,s+1))
            return fd
        fires = []
        for i in range(n):
            for j in range(m):
                if(grid[i][j]==1):fires.append((i,j))
        b1 = bfs(fires) # min minutes for fire to reach empty cell
        b2 = bfs([(0,0)]) # min minutes for person to reach empty cell
        if(b2[-1][-1]==float('inf') or b1[-1][-1]<b2[-1][-1]): return -1 # if we can read house before fire
        diff = b1[-1][-1] - b2[-1][-1]
        if(diff==float('inf')): return 10**9 # if fire not able to reach house 
        d1 = b1[-2][-1]-b2[-2][-1]
        d2 = b1[-1][-2]-b2[-1][-2]
        # edge case: if meet event happens on bottom right cell 
        if(d1>diff or d2>diff): return diff
        return diff-1
        
    