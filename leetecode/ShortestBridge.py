class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        q = deque()
        n = len(grid)
        adj= [(0,1),(1,0),(-1,0),(0,-1)]
        vis = set()
        for i in range(n):
            for j in range(n):
                if(grid[i][j]==1):
                    q.append((i,j))
                    vis.add((i,j))
                    break
            if(q): break
        while(q): # find first island
            i,j = q.popleft()
            for dx,dy in adj:
                y,x= dy+i,dx+j
                if(y>=n or x>=n or x<0 or y<0 or (y,x) in vis or grid[y][x]==0): continue
                vis.add((y,x))
                q.append((y,x))
        for i,j in set(vis):
            for dx,dy in adj:
                y,x= dy+i,dx+j
                if(y>=n or x>=n or x<0 or y<0 or (y,x) in vis): continue
                vis.add((y,x))
                q.append((0,y,x))
        while(q): # bfs from first island to find second one
            s,i,j = q.popleft()
            for dx,dy in adj:
                y,x= dy+i,dx+j
                if(y>=n or x>=n or x<0 or y<0 or (y,x) in vis): continue
                if(grid[y][x]): return s+1
                vis.add((y,x))
                q.append((s+1,y,x))

        return 0

            