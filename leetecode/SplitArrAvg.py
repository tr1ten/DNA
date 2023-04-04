# meet in the middle
import bisect
class Solution:
    def splitArraySameAverage(self, A: List[int]) -> bool:
        def subset_sum(vec,left,right):
            n = right-left+1
            sums = [0]*(1<<n)
            for mask in range(0,1<<n):
                sm=0
                for i in range(0,n):
                    if((mask&(1<<i))>0): sm+=vec[left+i]
                sums[mask] = (sm)
            return sums
        def solve(n,k,vec):
            left_sums = subset_sum(vec,0,(n//2)-1)
            right_sums = subset_sum(vec,(n//2),n-1)
            right_sums.sort()
            res = 0
            for sm in left_sums:
                target = k-sm
                eq= bisect.bisect_left(right_sums,target)
                larger= bisect.bisect_right(right_sums,target)
                res += larger-eq
            return res
        a = sum(A)/len(A)
        return solve(len(A),0,[x-a for x in A])>=3
