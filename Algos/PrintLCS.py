
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m = len(text1)
        n = len(text2)
        DP = [[0 for j in range(n + 1)] for i in range(m + 1)]
        
        ans = ''
        #calculate the length for lcs for sub string :i and :j
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if text1[i - 1] == text2[j - 1]:
                    DP[i][j] = 1 + DP[i - 1][j - 1]
                else:
                    if DP[i - 1][j] > DP[i][j - 1]:
                        DP[i][j] = DP[i - 1][j]
                    else:
                        DP[i][j] = DP[i][j - 1]
        
        u = m
        v = n
        
        while u > 0 and v> 0:
            if text1[u - 1] == text2[v - 1]:
                ans += text1[u - 1]
                u -= 1
                v -= 1
            else:
                if DP[u - 1][v] > DP[u][v - 1]:
                    u = u - 1
                else:
                    v = v - 1
        print(ans[::-1])
        return DP[m][n]
		