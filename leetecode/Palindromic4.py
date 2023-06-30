class Solution:
    def checkPartitioning(self, s: str) -> bool:
        # dp[i][k] - is it possibe to split prefix i length into k palindromes?
        n = len(s)
        K = 3
        dp = [[False]*(K+1) for i in range(n+1)]
        dp[0][0] = True
        pre = [[False]*n for i in range(n)]
        # preprocess palindrom queries 
        for k in range(1,n+1):
            for i in range(n-k+1):
                j = i+k-1
                if k<=2: pre[i][j] = s[i]==s[j]
                else: pre[i][j] = s[i]==s[j] and (pre[i+1][j-1] if i+1<n and j-1>=i else True)
        for i in range(1,n+1):
            for k in range(1,K+1):
                for j in range(i):
                    dp[i][k] |= (dp[j][k-1] and pre[j][i-1] )
                    if(dp[i][k]): break
        return dp[n][K]