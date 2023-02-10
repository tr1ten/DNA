from collections import deque
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        dq = deque()
        n = len(grid)
        cost = [[float('inf')]*n for i in range(n)]
        for i in range(n):
            for j in range(n):
                if(grid[i][j]==1): 
                    dq.append((i,j))
                    cost[i][j] = 0
        if(len(dq)==n*n or len(dq)==0): return -1
        dX = [-1,1,0,0]
        dY = [0,0,-1,1]
        while(dq):
            y,x = dq.popleft()
            for dy,dx in zip(dX,dY):
                i = dy+y;
                j = dx+x
                if(i>=0 and i<n and j>=0 and j<n and cost[i][j]>cost[y][x]+1):
                    cost[i][j] = cost[y][x]+1
                    dq.append((i,j))
        
        c = 0
        for i in range(n):
            for j in range(n):
                c = max(cost[i][j],c)
        return c
                
        