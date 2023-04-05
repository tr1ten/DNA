# palindromic range query dp[i][j] max len pali in i...j 
def ff(s):
    n = len(s)
    dp = [[0] * n for _ in range(n)]
    
    for i in range(n-1, -1, -1):
        dp[i][i] = 1
        for j in range(i+1, n):
            if s[i] == s[j]:
                dp[i][j] = dp[i+1][j-1] + 2
            else:
                dp[i][j] = max(dp[i+1][j], dp[i][j-1])
    
    return dp
class Solution:
    def longestPalindrome(self, w1: str, w2: str) -> int:
        def palis(s):
            dp = ff(s)
            res = [0]*(len(s)+1)
            for i in range(len(s)):
                res[i] = dp[i][-1]
            return res
        def f(word1,word2):
            dp1 = palis(word1)
            word2 = word2[::-1]
            dp2 = palis(word2)
            dp = [[0]*(len(word2)+1) for i in range(len(word1)+1)]
            res = 0
            # print(dp1,dp2)
            for i in range(1,1+len(word1)):
                for j in range(1,1+len(word2)):
                    if(word1[i-1]==word2[j-1]): dp[i][j] = dp[i-1][j-1] + 1
                    else: dp[i][j] = max(dp[i-1][j],dp[i][j-1])
                    if(dp[i][j]): res = max(res,2*dp[i][j]+max(dp1[i],dp2[j]))
            return res
        return f(w1,w2)

             