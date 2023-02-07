class Solution:
    """
        Intuition: Why not directly DP? Because it would be inefficient here.
        Since we already know possible answers, we just need to check each one efficiently and choose min ans that satisfies the condition.
    
    """
    def minCapability(self, nums: List[int], K: int) -> int:
        def ok(x): # generic okay function for exhaustive binary search
            p=0
            pp = 0
            for k in nums:
                if(k<=x):
                    pp,p = p,max(pp+1,p)
                else:
                    pp = p
            return p>=K
        lo = 0
        hi = len(nums)-1
        temp = nums[:] # copy and sort
        temp.sort()
        while(lo<hi):
            mid = (lo+hi)//2
            if(ok(temp[mid])): hi = mid
            else: lo = mid+1
        return temp[lo]
