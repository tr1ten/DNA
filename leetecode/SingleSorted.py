class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        lo,hi = 0,len(nums)-1
        if(len(nums)==1): return nums[0]
        while(hi>lo):
            mid = (hi+lo)>>1;
            if((mid+1==len(nums) or nums[mid]!=nums[mid+1]) and (mid==0 or nums[mid]!=nums[mid-1])): return nums[mid]
            if((nums[mid]==nums[mid+1] and (mid-lo+1)%2==0) or (nums[mid]!=nums[mid+1] and (mid-lo+1)%2==1)):
                hi = mid
            else:
                lo = mid+1
        return -1

