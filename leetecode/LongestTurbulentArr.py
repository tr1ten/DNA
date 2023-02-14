class Solution:
    def maxTurbulenceSize(self, nums: List[int]) -> int:
        if(len(nums)<=1): return len(nums)
        s = [1,1]
        res = 1
        for i in range(1,len(nums)):
            if(nums[i]==nums[i-1]): 
                s = [1,1]
                continue
            s[nums[i]>nums[i-1]],s[nums[i]<nums[i-1]] = s[nums[i]<nums[i-1]]+1,1
            res = max(res,s[nums[i]>nums[i-1]])
        return res
