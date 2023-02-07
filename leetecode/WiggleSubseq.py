# DP - O(N^2)
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[1]*2 for i in range(n)] # dp[i][0] - max len of wiggle subseq if current is smaller then prev, 1- if bigger 
        for i in range(n):
            for j in range(0,i):
                if(nums[i]>nums[j]): dp[i][1] = max(dp[i][1],dp[j][0]+1)
                if(nums[i]<nums[j]): dp[i][0] = max(dp[i][0],dp[j][1]+1)
        return max(dp[-1][0],dp[-1][1]) # we can prove that last el can always be the part of max len subseq
        
# Simple greedy, choose front by default since it always be the part of largest subseq
# O(N)
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        idx = 1
        while(idx<n and nums[idx]==nums[0]): idx+=1 # find second number of subseq
        if(idx>=n): return 1
        prev = nums[0]
        larger = nums[idx]>nums[0] # flag which toggle on each new element, determine whether the next el should be larger than prev or not
        res = 1
        for i in range(1,n-1):
            if((larger and nums[i]>prev and larger and nums[i+1]<=nums[i]) or (not larger and nums[i]<prev and nums[i+1]>nums[i])): # always choose max for larger and smallest for not larger
                res +=1
                larger = not larger # toggle
                prev = nums[i]
        if(prev!=nums[-1]): res+=1 # check if last element already included or not
        return res 
        