class Solution:
    def numMusicPlaylists(self, N: int, goal: int, k: int) -> int:
        dp = [[0]*(N+1) for i in range(goal+1)]
        dp[0][0] = 1
        mod = 10**9 + 7
        for g in range(1,goal+1):
            for n in range(1,min(N+1,g+1)):
                dp[g][n] = n * (dp[g-1][n-1] ) +  max((n-k),0)*(dp[g-1][n])
                dp[g][n] %=mod
        return dp[goal][N]
                