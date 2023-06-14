#
# @lc app=leetcode id=1774 lang=python3
#
# [1774] Closest Dessert Cost
#

# @lc code=start
class Solution:
    def closestCost(self, baseCosts: List[int], toppingCosts: List[int], target: int) -> int:
        def knapsack(V,W): # generic knapsack, W= max wt, sorted V
            n,m = len(V)+1,W+1
            dp = [[False]*m for i in range(n)];
            for i in range(n): dp[i][0] = True
            for i in range(1,n):
                for j in range(1,m):
                    if V[i]>=j: dp[i][j] |= dp[i-1][j-V[i]];
            return dp[n-1]
        V = toppingCosts + toppingCosts
        V.sort()
        W = 2*max(target,max(toppingCosts))
        gres= float('inf')
        for x in baseCosts:
            dp = knapsack(V,W)
            res=float('inf')
            for w in range(1,W+1):
                if abs(res-target) > abs(target - (w+x)): res = w+x
            if abs(res-target)<abs(gres-target) or (abs(res-target)==abs(gres-target) and res<gres):
                gres= res
        return gres
            
# @lc code=end

