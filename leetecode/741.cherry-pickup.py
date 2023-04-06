#
# @lc app=leetcode id=741 lang=python3
#
# [741] Cherry Pickup
#

# @lc code=start
# think differently, maybe two people == equivalent one people twice
# O(n^3)
class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if(n==1 or grid[0][0]==-1): return max(0,grid[0][0])
        @cache
        def dp(i1,j1,i2,j2): # row col diff
                if(min(i1,j1,i2,j2)<0 or max(i1,j1,i2,j2)>=n or min(grid[i1][j1],grid[i2][j2])<0): return -1
                if((i1,j1)==(i2,j2)==(n-1,n-1)): return grid[i1][j1] 
                r = max(dp(i1+1,j1,i2+1,j2),dp(i1+1,j1,i2,j2+1),dp(i1,j1+1,i2+1,j2),dp(i1,j1+1,i2,j2+1))
                if(r<0): return -1
                return grid[i1][j1] + r + (grid[i2][j2] if (i1,j1)!=(i2,j2) else 0)
        return max(0,dp(0,0,0,0))
        
# @lc code=end

