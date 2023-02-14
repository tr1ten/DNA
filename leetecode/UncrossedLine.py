class Solution:
    def maxUncrossedLines(self, nums1: List[int], nums2: List[int]) -> int:
        dp = [[0]*(len(nums2)+1) for i in range(2)]
        for i in range(1,len(nums1)+1):
            for j in range(1,len(nums2)+1):
                if(nums1[i-1]==nums2[j-1]): dp[1][j] = dp[0][j-1] + 1 
                else: dp[1][j] = max(dp[1][j-1],dp[0][j])
            dp[0] = dp[1]
            dp[1] = [0]*(len(nums2)+1)
        # print(dp)
        return dp[0][-1]