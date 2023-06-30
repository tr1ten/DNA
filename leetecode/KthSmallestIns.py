class Solution:
    def kthSmallestPath(self, dest: List[int], k: int) -> str:
        n,m = dest
        n +=1
        m +=1
        dp = [[0]*m for i in range(n)] 
        dp[n-1][m-1] = 1
        for i in range(n-1,-1,-1):
            for j in range(m-1,-1,-1):
                if j-1>=0: dp[i][j-1] +=dp[i][j]
                if i-1>=0: dp[i-1][j] += dp[i][j]
        def backtrack(i,j,target):
            print(i,j,target)
            if i==0 and j==0: return ""
            if i+1>=n: return "H"+backtrack(i,j+1,target)
            if j+1>=m: return "V"+backtrack(i+1,j,target)
            if dp[i+1][j]>=target: return "V"+backtrack(i-1,j,target)
            return "H"+backtrack(i,j-1,target-dp[i-1][j])
        print(dp)
        return backtrack(n-1,m-1,k)[::-1]