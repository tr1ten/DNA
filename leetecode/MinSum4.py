class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        nums.sort()
        @lru_cache(None)
        def solve(t):
            if(t==0): return 1
            if(t<0): return 0
            res = 0
            for x in nums:
                if(x>t): break
                res += solve(t-x)
            return res
        return solve(target)