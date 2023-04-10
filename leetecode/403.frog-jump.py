#
# @lc app=leetcode id=403 lang=python3
#
# [403] Frog Jump
#

# @lc code=start
class Solution:
    def canCross(self, stones: List[int]) -> bool:
        d = {stones[i]:i for i in range(len(stones))}
        # @cache
        # def dp(i,k):
        #     if(i==len(stones)-1): return True
            # if(k>1 and stones[i]+k-1 in d and dp(d[stones[i]+k-1],k-1)): return True
            # if(k>0 and stones[i]+k in d and dp(d[stones[i]+k],k)): return True
            # if(stones[i]+k+1 in d and dp(d[stones[i]+k+1],k+1)): return True
        #     return False
        n = len(stones)
        dp = [[False]*n for i in range(n)]
        for k in range(n): dp[0][k] =  True
        for i in range(n-1,-1,-1):
            for k in range(n):
                f = False
                if(k>1 and stones[i]+k-1 in d and dp[d[stones[i]+k-1]][k-1] ): f = True
                if(k>0 and stones[i]+k in d and dp[d[stones[i]+k]][k]): f = True
                if(k+1<n and stones[i]+k+1 in d and dp[d[stones[i]+k+1]][k+1] ): f = True
                dp[i][k] = f
        return dp[0][0]     
# @lc code=end

