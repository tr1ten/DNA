class Solution:
    def maximumANDSum(self, nums: List[int], nk: int) -> int:
        nums.extend([0]*(2*nk-len(nums)))
        n = len(nums)
        dp =  [0 for i in range(1<<n)]
        for x in range(1,1<<n):
            slot = -(-x.bit_count()//2)
            for i in range(n):
                if(x&(1<<i)==0): continue
                dp[x] = max(dp[x],dp[x^(1<<i)] + (nums[i]&slot)) 
        return dp[(1<<n)-1]