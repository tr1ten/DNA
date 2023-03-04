class Solution:
    def minimumTime(self, s: str) -> int:
        dp  = [[0]*3 for i in range(len(s))]
        dp[0][0] = s[0]=='1'
        dp[0][1] = 2*(s[0]=='1')
        dp[0][1] = s[0]=='1'
        for i in range(1,len(s)):
            if(s[i]=='0'):
                dp[i] = dp[i-1]
                dp[i][2] +=1
            else:
                dp[i][0] = i+1
                dp[i][1] = min(dp[i-1][0],dp[i-1][1]) + 2
                dp[i][2] = min(dp[i-1][2],dp[i-1][1],dp[i-1][0])+1
        return min(dp[-1])
# todo by kadane n + minsubarray