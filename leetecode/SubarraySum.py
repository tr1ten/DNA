class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        if(max(arr)<0): return max(arr)
        def solve(nums):
            dp = [0]*len(nums)
            sm = 0
            for i in range(len(nums)):
                sm = max(nums[i],sm+nums[i])
                dp[i] = sm
            return [0]+dp
        pref = solve(arr)
        suff = solve(arr[::-1])[::-1]
        res = float('-inf')
        # print(pref,suff)
        for i in range(len(arr)):
            res = max(res,max(pref[i]+suff[i+1],pref[i],suff[i+1])+max(0,arr[i]))
        return res