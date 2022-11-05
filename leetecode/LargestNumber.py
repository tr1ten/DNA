from functools import cmp_to_key
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        if(nums.count(0)==len(nums)): return "0"
        def cmp(a,b):
            aa = str(a)
            bb = str(b)
            f = aa+bb
            g = bb+aa
            if(f<g): return 1
            elif(f>g): return -1
            else: return 0
        nums = sorted(nums,key=cmp_to_key(cmp))
        res = "".join([str(x) for x in nums]);
        return res