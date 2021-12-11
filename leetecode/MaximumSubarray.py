#Kadane's algorithm
def maxSubArray(nums):
    maxSub = nums[0]
    localMax  = 0
    for n in nums:
        if(localMax<0):
            localMax = 0
        localMax +=n
        maxSub = max(localMax,maxSub)
    return maxSub
            
print(maxSubArray( [-2,-2,-3,-1,-4,-5]))