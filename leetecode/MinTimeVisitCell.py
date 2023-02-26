import heapq
class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        if(grid[0][1]>1 and grid[1][0]>1): return -1 # every where back and forth possible except first cell
        h = []
        h.append((0,0,0))
        MAX = 10**5 + 1
        while(h): # dijstra with back and forth
            t,y,x= heapq.heappop(h)
            if(y==len(grid)-1 and x==len(grid[0])-1): return t
            for dx,dy in [(1,0),(-1,0),(0,1),(0,-1)]:
                i,j = dy+y,dx+x
                if( i>=len(grid) or i<0 or j<0 or j>=len(grid[0])): continue
                heapq.heappush(h,(max(t+1,grid[i][j] + (grid[i][j]-1-t)%2) ,i,j)) # back forth can increase time 
                grid[i][j] = MAX
        return -1
        
        