class Solution:
    def search(self, nums: List[int], target: int) -> int:
        lo = 0
        hi = len(nums)-1
        while(lo<=hi):
            mid = (lo+hi)//2
            num = (nums[mid] if(nums[mid]<=nums[-1]) else float('-inf')) if(target<=nums[-1]) else (nums[mid] if(nums[mid]>=nums[0]) else float('inf'))
            if(num==target): return mid
            elif(num<target):
                lo = mid+1
            else: hi = mid-1
                
        return -1