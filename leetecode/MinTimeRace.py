class Solution:
    def minimumFinishTime(self, tires: List[List[int]], ct: int, nl: int) -> int:
        """
            Observation : constraint of number of laps and max value of change tire and min value of r
        """
        dp = [float('inf')]*nl
        # precompute dp for lap using single tire 
        for f,r in tires:
            t = 0
            for i in range(min(18,nl)):
                t +=f*pow(r,i)
                dp[i] = min(dp[i],t)
        # try combining tires 
        for i in range(nl):
            for j in range(0,i):
                dp[i] = min(dp[i],dp[j]+dp[i-j-1]+ct)
        return dp[-1]