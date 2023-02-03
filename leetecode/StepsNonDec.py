class Solution:
    def totalSteps(self, nums: List[int]) -> int:  
        n = len(nums)
        dp = [0]*n # number of rounds to remove this element else 0
        st = []
        for i,x in enumerate(nums):
            while(st and nums[st[-1]]<=x): # find all smaller elements before and get max+1
                dp[i] = max(dp[i],dp[st.pop()]+1)
            if(not st): dp[i] = 0
            else: dp[i]= max(1,dp[i])
            st.append(i)
        return max(dp)