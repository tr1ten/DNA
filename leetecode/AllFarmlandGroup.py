from queue import Queue
class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        n = len(land)
        m = len(land[0])
        res = []
        def bfs(i,j):
            adj = ((0,1),(0,-1),(1,0),(-1,0))
            q = Queue(maxsize=m*n);
            endx = j;
            endy = i;
            q.put((i,j))
            while(not q.empty()):
                u,v = q.get()
                for dy,dx in adj:
                    y = u+dy;
                    x = v+dx;
                    if(y<0 or x<0 or y>=n or x>=m or land[y][x]==0): continue;
                    land[y][x] = 0
                    q.put((y,x));
                endx = max(v,endx);
                endy = max(u,endy);
            return [i,j,endy,endx];
        for i in range(n):
            for j in range(m):
                if(land[i][j]):
                    res.append(bfs(i,j));
        return res
            
            