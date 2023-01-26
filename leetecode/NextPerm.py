class Solution:
    def nextPermutation(self, nums) -> None:
        def reverse(arr, i, j):
            while i < j:
                arr[i], arr[j] = arr[j], arr[i]
                i += 1
                j -= 1
        idx = -1 # one past latest pivot point
        for i in reversed(range(len(nums)-1)):
            if(nums[i+1]>nums[i]):
                idx = i
                break
        if(idx==-1): # if reverse sorted, ie last permutation
            reverse(0,len(nums)-1)
            return;
        jdx = -1 # find number to swap with 
        for i in reversed(range(len(nums))):
            if(nums[i]>nums[idx]):
                jdx = i
                break
        nums[idx],nums[jdx] = nums[jdx],nums[idx]
        reverse(nums,idx+1,jdx) # fact that idx+1 to jdx will be reversed sorted so after repalacing with lower digit it we need to start we sorted sub array
        

        
