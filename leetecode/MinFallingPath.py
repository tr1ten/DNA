import heapq
# djisktra - TLE no need of priority queue since we have to process all edges and nodes anyway
class Solution:
    def minFallingPathSum(self, m: List[List[int]]) -> int:
        n = len(m)
        heap = [(m[0][i],0,i) for i in range(n)]
        heapq.heapify(heap)
        MAX = 10**5
        d = [[MAX]*n for i in range(n)]
        for i in range(n): d[0][i] = m[0][i]
        while(len(heap)>0):
            w,i,j = heapq.heappop(heap)
            if(i==n-1 or w>d[i][j]): continue
            for dx in (-1,0,1):
                y,x=i+1,j+dx
                if(x>=0 and x<n and d[y][x]>w+m[y][x]):
                    d[y][x]=w+m[y][x];
                    heapq.heappush(heap,(d[y][x],y,x));
        return min(d[n-1])

# without priority queue AC but bad runtime
import heapq
from queue import Queue
class Solution:
    def minFallingPathSum(self, m: List[List[int]]) -> int:
        n = len(m)
        q = Queue(maxsize=n*n)
        MAX = 10**5
        d = [[MAX]*n for i in range(n)]
        for i in range(n): 
            q.put((m[0][i],0,i))
            d[0][i] = m[0][i]
        while(not q.empty()):
            w,i,j = q.get()
            if(i==n-1 or w>d[i][j]): continue
            for dx in (-1,0,1):
                y,x=i+1,j+dx
                if(x>=0 and x<n and d[y][x]>w+m[y][x]):
                    d[y][x]=w+m[y][x];
                    q.put((d[y][x],y,x));
        return min(d[n-1])
    

# Good runtime
class Solution:
    def minFallingPathSum(self, m: List[List[int]]) -> int:
        n = len(m)
        MAX = 10**5
        d = [[MAX]*n for i in range(n)]
        for i in range(n):  d[0][i] = m[0][i]
        for i in range(1,n):
            for j in range(n):
                d[i][j] = min(d[i-1][j], MAX if(j-1<0) else d[i-1][j-1],MAX if(j+1>=n) else d[i-1][j+1]) + m[i][j]
        return min(d[n-1])