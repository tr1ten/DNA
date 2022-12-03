from typing import List;
class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        n = len(grid)
        m = len(grid[0])
        visited = [[[False]*4 for j in range(m)] for i in range(n)]
        adj = (
        ((0,0,3),(0,0,1),(-1,0,2)),
        ((0,0,2),(0,0,0),(0,1,3)),
        ((0,0,1),(0,0,3),(1,0,0)),
        ((0,0,0),(0,0,2),(0,-1,1))
        )
        res = 0
        def dfs(i,j,k):
            visited[i][j][k] = True;
            for p in range(3):
                di,dj,dk = adj[k][p];
                y,x,z = di+i,dj+j,dk;
                if(y<0 or x<0 or y>=n or x>=m or visited[y][x][z]): continue;
                if(grid[y][x]==" " or (grid[y][x]=='/' and p!=1) or (grid[y][x]=='\\' and p!=0)): 
                    dfs(y,x,z);
                
                    
        for i in range(n):
            for j in range(m):
                for k in range(4):
                    if(not visited[i][j][k]):
                        print("start ",i,j,k)
                        dfs(i,j,k);
                        res +=1
        return res
    
def main():
    s = Solution()
    print(s.regionsBySlashes([" /","  "]))

main()
                
                    
                    
                    
                