class Solution:
    def minCapability(self, nums: List[int], K: int) -> int:
        @cache
        def f(idx,take,k,mx):
            if(k==0): return mx
            if(idx==len(nums)): return float('inf')
            res = float('inf')
            if(k==0): return mx
            if(len(nums)-idx-1-2*k<0): return f(idx+1,False,k-1,max(nums[idx],mx))
            if(take): res = min(res,f(idx+1,False,k-1,max(nums[idx],mx)))
            return min(f(idx+1,True,k,mx),res)
        return f(0,True,K,0)
            
        
        
        