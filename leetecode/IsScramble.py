from collections import Counter


class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        def f(i, j,x,y):
            if (s1[i:j+1] == s2[x:y+1]):
                return True
            st1 = Counter()
            st2 = Counter()
            for k in range(j+1-i):
                st1[s1[i+k]] += 1
                st2[s2[x+k]] += 1
                if (st1 == st2 and f(i, i+k,x,i+k) and f(k+1, j,)):
                    return True
            return False
        return f(0,len(s1)-1)
    
    
from collections import Counter
class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        MAXN = 100
        n = len(s1)
        dp = [[[False]*MAXN for j in range(MAXN) ] for i in range(MAXN)] # dp[i][j][l] - s1[i:i+l] === s2[j:j+l]
        for l in range(1,n+1):
            for i in range(n-l+1):
                for j in range(n-l+1):
                    dp[i][j][1] = s1[i]==s2[j]
                    for k in range(1,l):
                        dp[i][j][l] |= (dp[i][j][k] and dp[i+k][j+k][l-k])
                        dp[i][j][l] |= (dp[i][j+l-k][k] and dp[i+k][j][l-k])
                        if(dp[i][j][l]): break
        return dp[0][0][n]

