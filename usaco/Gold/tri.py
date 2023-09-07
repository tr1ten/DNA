import heapq
class Solution:
    # @param A : integer
    # @param B : list of list of integers
    # @return a list of integers
    def solve(self, A, B):
        m = len(B)
        ans = [0]*(A+1)
        ans[0] = -1
        B = [[x,y,z,i] for i,(x,y,z) in enumerate(B)]
        B.sort()
        for x,y,z,i in B:
            ans[y] = m+1
        i = 1
        j = 0
        pq = []
        while i<=A:
            while j<m and B[j][0]==i:
                heapq.heappush(pq,(B[j][1],j))
                j+=1
            if pq and ans[i]==0:
                _,idx = pq[0]
                if B[idx][1]<=i: return [-1]
                B[idx][2] -=1
                ans[i] = B[idx][-1]+1
                if B[idx][2]==0: heapq.heappop(pq)
            i +=1
        if pq: return [-1]
        return ans
                
            
            
s = Solution()
print(s.solve(6,[[1,5,1],[1,6,1],[1,2,1]]))
print(s.solve(2,[[1,2,1]]))
print(s.solve(3,[[1,2,2]]))
