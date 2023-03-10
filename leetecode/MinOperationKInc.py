from sortedcontainers import SortedList
from bisect import bisect
class Solution:
    def kIncreasing(self, arr: List[int], k: int) -> int:
        def lis(nums):
            dp = [10**10]*(len(nums)+1)
            for x in nums: dp[bisect(dp,x)] = x
            return dp.index(10**10)
        res = 0
        for i in range(0,k):
            nums = []
            for j in range(i,len(arr),k):
                nums.append(arr[j])
            res += (len(nums)-lis(nums))
        return res

