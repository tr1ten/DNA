from collections import Counter
class Solution:
    def minCost(self, nums: List[int], k: int) -> int:
        n = len(nums)
        pre =  [[0]*(n) for i in range(n)]
        for i in range(0,n):
            cnt = Counter()
            r = 0
            for j in range(i,len(nums)):
                cnt[]
                if(nums[j] in s):
                    if(nums[j] in c): r+=1
                    else: 
                        r +=2
                        c.add(nums[j])
                s.add(nums[j])
                pre[i][j] = r
        dp = [0]*(n+1)
        for idx in reversed(range(n)):
            res = float('inf')
            for i in range(idx,len(nums)):
                res = min(res,pre[idx][i]+dp[i+1])
            dp[idx] = k+res
        return dp[0]
                
                
        