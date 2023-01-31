class Solution:
    def search(self, nums: List[int], target: int) -> int:
        lo = 0
        hi = len(nums)-1
        while(lo<=hi):
            mid = (lo+hi)//2
            if(nums[mid]==target): return True
            if(nums[lo]>=nums[hi]): # if lo and hi possibly on different side 
                if(target<=nums[hi]):# last side
                    lo +=1
                else: # first side
                    hi -=1
            else: # normal binary search
                if(nums[mid]<target):
                    lo = mid+1
                else: hi = mid-1
        return False