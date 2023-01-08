class Solution:
	# @param A : string
	# @param B : string
	# @return an integer
	def numDistinct(self, A, B):
		dp = [[0]*(len(B)+1) for i in range(len(A)+1)]
		ways = [[0]*(len(B)+1) for i in range(len(A)+1)]
		# for i in range(len(A)+1): ways[i][0] = 1
		# for i in range(len(B)+1): ways[0][i] = 1
		ways[0][0] = 1
		for i in range(1,len(A)+1):
			for j in range(1,len(B)+1):
				if(A[i-1]==B[j-1]):
					dp[i][j] = dp[i-1][j-1]+1
					ways[i][j] += ways[i-1][j-1]
					if(dp[i-1][j]==dp[i][j]): 
						ways[i][j] +=ways[i-1][j]
					if(dp[i][j-1]==dp[i][j]): 
						ways[i][j] +=ways[i][j-1]
					
				else:
					if(dp[i-1][j]>=dp[i][j-1]):
						dp[i][j] = dp[i-1][j]
						ways[i][j] += ways[i-1][j]
					if(dp[i][j-1]>=dp[i-1][j]):
						dp[i][j] = dp[i][j-1]
						ways[i][j] += ways[i][j-1]
		return ways[-1][-1] if(dp[-1][-1]==len(B)) else 0
s = Solution().numDistinct("rabbbit","rabbit")

						
					
						
					
					
