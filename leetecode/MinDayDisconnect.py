class Solution:
    def minDays(self, grid: List[List[int]]) -> int:
        grid.append([0]*len(grid[0]))
        dx=[0,0,-1,1]
        dy = [-1,1,0,0]
        for i in range(len(grid)): grid[i].append(0) # prevent edge cases, no need for left padding as -1 == n-1
        n,m = len(grid),len(grid[0])
        ids = [[-1]*m for i in range(n)]
        low = [[-1]*m for i in range(n)]
        time = 0
        ap = 0
        cnt = 0
        one_count = 0
        def dfs(ux,uy,px,py):
            nonlocal time,ap
            low[uy][ux]=ids[uy][ux]=time
            time +=1
            child = 0
            for x,y in [(ux+xx,uy+yy) for xx,yy in zip(dx,dy)]:
                if (px,py)==(x,y) or not grid[y][x]: continue
                if ids[y][x]==-1: 
                    dfs(x,y,ux,uy)
                    child +=1
                    if(low[y][x]>=ids[uy][ux] and (px,py)!=(-1,-1)): 
                        ap+=1
                low[uy][ux] = min(low[uy][ux], low[y][x])
            if((px,py)==(-1,-1) and child>1): ap+=1
        for i in range(n-1):
            for j in range(m-1):
                one_count +=(grid[i][j]==1)
                if ids[i][j]==-1 and grid[i][j]:
                    if cnt>0: return 0
                    cnt+=1
                    dfs(j,i,-1,-1)
        if cnt==0: return 0
        return 1 if one_count == 1 or ap>0 else 2
            

    