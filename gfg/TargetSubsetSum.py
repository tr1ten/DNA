from functools import lru_cache
class Solution:
    def isSubsetSum (self, N, arr, sum):
        @lru_cache(None)
        def solve(cur,idx):
            if(cur>=sum): return cur==sum
            if(idx>=N): return False
            return solve(cur+arr[idx],idx+1) or solve(cur,idx+1)
        return solve(0,0)