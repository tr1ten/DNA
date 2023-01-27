import heapq
class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        def count(x): # count number of element less than x in mat
            cnt = 0
            for i in range(m):
                cnt += min(x//(i+1),n)
            return cnt
        l,h = 0,n*m # binary search the min value of mid such that count(mid)>=k
        while(l<h):
            mid = (l+h)//2
            if(count(mid)>=k):
                h = mid
            else:
                l = mid+1
        
        return h

            
        
        