class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        dp = [0]*(k+1)
        for pile in piles:
            sm = 0
            ndp = dp[:]
            for j in range(len(pile)):
                sm += pile[j]
                for i in range(0,k-j):
                    dp[i+j+1] = max(dp[i+j+1],ndp[i]+sm)
        return dp[-1]