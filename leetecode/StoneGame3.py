class Solution:
    def stoneGameIII(self, nums: List[int]) -> str:
        @cache
        def f(idx):
            if(idx>=len(nums)): return 0
            res =float('-inf')
            sm  = 0
            for i in range(idx,min(idx+3,len(nums))):
                sm += nums[i]
                res = max(res,sm-f(i+1))
            return res
        res = f(0)
        if(res>0): return 'Alice'
        elif(res<0): return 'Bob'
        else: return "Tie"