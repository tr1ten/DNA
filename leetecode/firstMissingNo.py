def firstMissingPositive( nums):   
    n = len(nums)
    # removing elements not inbound in [1,n]
    for i in range(n):
        if(nums[i]<1 or nums[i]>n):
            nums[i]=0
    #** storing information in index of  array to confirm that element exist
    for i in range(n):
        if(nums[i]!=0):
            nums[nums[i]%(n+1)-1] += n+1
    # checking which element in range [0,n] not exist inside nums
    for i in range(n):
        if(nums[i]<n+1):
            return i+1
    return n+1
print(firstMissingPositive([3,4,-1,1]))
