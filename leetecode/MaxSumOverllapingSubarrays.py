class Solution:
    def maxSumTwoNoOverlap(self, nums: List[int], l1: int, l2: int) -> int:
        n = len(nums)
        def solve(x,y):
            # first max x size subarray then y size
            dp1 = [0]*n
            dp2 = [0]*n
            dp1[x-1] = sum(nums[:x])
            sm = dp1[x-1]
            for i in range(x,n):
                sm += -nums[i-x]+nums[i]
                dp1[i] = max(dp1[i-1],sm)
            dp2[-y] = sum(nums[-y:])
            sm = dp2[-y]
            for i in reversed(range(0,n-y)):
                sm += -nums[i+y]+nums[i]
                dp2[i] = max(dp2[i+1],sm)
            return max([x+y for x,y in zip(dp1[:-1],dp2[1:])])

        return max(solve(l1,l2),solve(l2,l1))
        
                