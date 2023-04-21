#
# @lc app=leetcode id=879 lang=python3
#
# [879] Profitable Schemes
#

# @lc code=start
class Solution:
    def profitableSchemes(self, N: int, mp: int, G: List[int], P: List[int]) -> int:
        mod = 10**9 + 7
        @cache
        def dp(idx,n,p):
            if(idx==len(P)): return p==0
            res = dp(idx+1,n,p)
            if(n>=G[idx]): res += dp(idx+1,n-G[idx],max(0,p-P[idx]))
            return res%mod
        
        return dp(0,N,mp)
            
# @lc code=end

