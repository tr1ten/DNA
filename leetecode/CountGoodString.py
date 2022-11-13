class Solution:
    def countGoodStrings(self, low: int, high: int, z: int, o: int) -> int:
        dp = [0]*(high+1)
        dp[0] = 1
        total = 0
        MOD = 10**9 + 7
        for n in range(1,high+1):
            if(n-o>=0): 
                dp[n] += dp[n-o];
            if(n-z>=0): 
                dp[n] += dp[n-z]
            if(n>=low and n<=high):
                total = (total+dp[n])%MOD
        return total;   