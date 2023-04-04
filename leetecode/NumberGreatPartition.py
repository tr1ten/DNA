class Solution:
    def countPartitions(self, A: List[int], k: int) -> int:
        if(sum(A)<2*k): return 0
        mod = 10**9 + 7
        dp = [[0]*k for i in range(len(A)+1)]
        for i in range(k): 
            dp[len(A)][i] = 1
            
        for idx in reversed(range(len(A))):
            for sm in reversed(range(k)):
                dp[idx][sm] += dp[idx+1][sm]
                if(sm+A[idx]<k): dp[idx][sm] += dp[idx+1][sm+A[idx]]
                dp[idx][sm] %=mod
        return (pow(2,len(A),mod) +mod-2*dp[0][0])%mod