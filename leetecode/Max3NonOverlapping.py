class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        K,n = 3,len(nums) # K subarrays 
        dp = [[0]*(n+1) for i in range(K+1)] # dp[i][j] - max sum of i non overapping subarrays till jth index
        dec = [[0]*(n+1) for i in range(K+1)] # dec[i][j] whose last index caused dp[i][j]
        pref = [0]*(n+1) # prefix sum for convience
        for i in range(1,n+1): pref[i] = pref[i-1]+nums[i-1] # we can use sliding window to calculate k sum but this is more clean imo
        for i in range(1,K+1):
            for j in range(k,n+1):
                dp[i][j] = max(dp[i][j-1],pref[j]-pref[j-k]+dp[i-1][j-k]) # generic dp either continue with previous max or choose this sum with prev max
                if(dp[i][j]>dp[i][j-1]): dec[i][j] = j # to build ans we need to track decision made during dp
                else: dec[i][j] = dec[i][j-1]
        res = []
        cur,m = n,K # backtrack dp to get ans
        while(m>0 and cur>0):
            cur = dec[m][cur]-k
            res.append(cur)
            m -=1
        return reversed(res) 