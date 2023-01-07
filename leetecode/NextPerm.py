class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        def reverse(arr, i, j):
            while i < j:
                arr[i], arr[j] = arr[j], arr[i]
                i += 1
                j -= 1
        idx = -1
        for i in reversed(range(len(nums)-1)):
            if(nums[i+1]>nums[i]):
                idx = i
                break
        if(idx==-1):
            nums.sort()
            return;
        jdx = -1
        for i in reversed(range(len(nums))):
            if(nums[i]>nums[idx]):
                jdx = i
                break
        nums[idx],nums[jdx] = nums[jdx],nums[idx]
        reverse(nums,idx+1,jdx)
        

        
