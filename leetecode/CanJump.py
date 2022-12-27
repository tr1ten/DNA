class Solution:
    def canJump(self, nums: List[int]) -> bool:
        dp = [False]*len(nums)
        dp[-1] = True
        last = len(nums)-1
        for i in reversed(range(len(nums)-1)):
            if(last-i<=nums[i]):
                dp[i] = True
                last = i
        return dp[0]