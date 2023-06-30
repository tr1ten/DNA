import heapq

# new way of prefix sums
class Solution:
    def kthLargestValue(self, mat: List[List[int]], k: int) -> int:
        n,m = len(mat),len(mat[0])
        pref = [[mat[i][j] for j in range(m)] for i in range(n)]
        for i in range(1,n):
            for j in range(m):
                pref[i][j] ^=pref[i-1][j]
        q = []
        for j in range(m):
            for i in range(n):
                if(j!=0): pref[i][j] ^=pref[i][j-1]
                if len(q)<k: heapq.heappush(q,pref[i][j])
                elif q[0]<pref[i][j]:
                    heapq.heappop(q)
                    heapq.heappush(q,pref[i][j])
        return q[0]

        
