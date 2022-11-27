class Solution:
    def countPalindromes(self, s: str) -> int:
        MOD = 10**9 + 7
        res = 0
        dp = [[[[0]*11 for i in range(11)] for i in range(11)] for i in range(11)]
        for x in s:
            i = ord(x) - ord('0')
            for j in range(10):
                for k in range(10):
                    dp[j][i][k][i] += dp[j][i][k][10]
                    dp[j][k][i][10] += dp[j][k][10][10]
                    res =( res+dp[i][j][k][j])%MOD
                dp[j][i][10][10] += dp[j][10][10][10];
            dp[i][10][10][10] +=1
        for i in range(10):
            for j in range(10):
                for k in range(10):
                    res 
        print(dp[1][0][3][0])    
        return res
def main():
    s = Solution()
    print(s.countPalindromes("10301"))
main()