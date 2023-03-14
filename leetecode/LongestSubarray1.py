class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        prev = None
        cur =0
        res = 0 # edge case where only ones
        for x in nums:
            if(x): cur+=1
            else:
                if(prev is not None): res=  max(prev+cur,res) 
                else: res = max(res,cur-1)
                prev = cur
                cur = 0
        if(prev is not None): res=  max(prev+cur,res)
        else: res = max(res,cur-1)
        return res