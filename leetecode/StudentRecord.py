from functools import cache
class Solution:
    def checkRecord(self, N: int) -> int:
        MOD = 10**9 + 7
        # dp n, absent count, late count
        dp = [[[0]*3 for i in range(2)] for i in range((N+1))]
        dp[1][0][0] = dp[1][0][1] = 3 # 1 absent and 0/1 late
        dp[1][1][0] = dp[1][1][1] = dp[1][0][2]= 2 # 1 absent 
        dp[1][1][2] = 1 # absent and late
        for i in range(2,N+1):
            dp[i][0][0] = (dp[i-1][0][0]+dp[i-1][1][0]+dp[i-1][0][1])%MOD # P A L
            dp[i][1][0] = (dp[i-1][1][0] + dp[i-1][1][1])%MOD # P L
            dp[i][0][1] = (dp[i-1][0][2] + dp[i-1][1][0] + dp[i-1][0][0])%MOD # L A P
            dp[i][1][1] = (dp[i-1][1][2] + dp[i-1][1][0])%MOD # L or P
            dp[i][0][2] = (dp[i-1][1][0] + dp[i-1][0][0])%MOD # A or P
            dp[i][1][2] = dp[i-1][1][0] # P
        
        # print(dp)
        return dp[-1][0][0]