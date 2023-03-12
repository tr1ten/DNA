class Solution:
    def superEggDrop(self, k: int, n: int) -> int:
        @cache
        def dp(i,f): # i egg and f floor
            if(f<=1): return f
            if(i==1): return f
            res = float('inf')
            lo,hi = 1,f-1
            while(lo<=hi):
                x = (lo+hi)//2
                left = dp(i-1,x-1)
                right = dp(i,f-x)
                res = min(max(left,right)+1,res)
                if(left==right): break
                if(left>right): hi = x-1
                else: lo = x+1
            return res
        return dp(k,n)
            
class Solution:
    def superEggDrop(self, k: int, n: int) -> int:
        dp = [[0]*(n+1) for i in range(k+1)]
        for i in range(n+1): dp[1][i] = i;
        for i in range(1,k+1): dp[i][1] = 1;
        for i in range(2,k+1):
            x = 1
            for f in range(2,n+1):
                while x<=f and dp[i-1][x-1]<dp[i][f-x]: x +=1
                dp[i][f] =dp[i-1][x-1]+1
        return dp[k][n]
    
    
# reverse thinking rather than finding min moves we can find max floors
import bisect
class Solution:
    def superEggDrop(self, k: int, n: int) -> int:
        M = n
        dp = [[0]*(M+1) for i in range(k+1)]
        for i in range(M+1): dp[1][i] = i;
        for i in range(1,k+1): dp[i][1] = 1;
        for i in range(2,k+1):
            for m in range(2,M+1):
                dp[i][m] = dp[i-1][m-1] + dp[i][m-1]+1
        return bisect.bisect_left(dp[-1],n)
            

            
            