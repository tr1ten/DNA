class Solution:
    def minCost(self, dp):
        n,m = len(dp),len(dp[0])
        if(m==1 and n>1): return -1
        for idx in range(n-2,-1,-1):
            suff = [float('inf')]*(m+1) 
            for i in reversed(range(m)):
                 suff[i] = min(suff[i+1],dp[idx+1][i])
            pref = float('inf')
            for i in range(m):
                dp[idx][i] = dp[idx][i] + min(pref,suff[i+1])
                pref = min(pref,dp[idx+1][i])
        return min(dp[0])