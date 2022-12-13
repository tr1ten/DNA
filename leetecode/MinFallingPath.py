import heapq
class Solution:
    def minFallingPathSum(self, m: List[List[int]]) -> int:
        n = len(m)
        heap = [(m[0][i],0,i) for i in range(n)]
        heapq.heapify(heap)
        res = 10**5
        while(len(heap)>0):
            w,i,j = heapq.heappop(heap)
            if(i==n-1):
                res = min(res,w)
                continue
            for dx in (-1,0,1):
                if(j+dx>=0 and j+dx<n):
                    heapq.heappush(heap,(w+m[i+1][j+dx],i+1,j+dx));
        return res