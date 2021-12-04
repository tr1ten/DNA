class Solution:
    def rob(self, nums):
        def bestD(nums,pointer,cache):
            if(pointer is None):
                return max(bestD(nums,0,cache),bestD(nums,1,cache))
            if(pointer>=len(nums)):
                return 0
            if(len(nums)-pointer<3):
                return nums[pointer]
            if(pointer in cache):
                return cache[pointer]
            cache[pointer] = max(nums[pointer]+bestD(nums,pointer+2,cache),nums[pointer]+bestD(nums,pointer+3,cache))
            return cache[pointer]
                    
                
        return bestD(nums,None,{})
print(Solution().rob([1,2,3,1,4]))