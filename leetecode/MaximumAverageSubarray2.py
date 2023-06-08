from typing import (
    List,
)
import bisect
class Solution:
    """
    @param nums: an array with positive and negative numbers
    @param k: an integer
    @return: the maximum average
    """
    def max_average(self, A: List[int], k: int) -> float:
        def ok(x):
            temp = [y-x for y in A]
            curr = 0
            pref = 0
            pmin = 0
            for j in range(len(temp)):
                if j<k: 
                    curr += temp[j]
                else:
                    curr += temp[j]
                    pref += temp[j-k]
                    pmin = min(pref,pmin)
                    if(curr-pmin>=0): return True
            return curr>=0
        lo,hi = min(A),max(A)
        epsilon = 0.001 # near to limit, lower more fast bs
        error = 1 # when to stop bs
        prev = hi # this is necessary otherwise error might be to low
        ans= float('-inf')
        while(error>epsilon):
            mid = (lo+hi)/2
            if ok(mid):     
                lo = mid
                ans = lo    
            else:
                hi = mid
            error = abs(mid-prev)
            prev = mid
        return ans
