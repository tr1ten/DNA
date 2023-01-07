# we can use the sum property as well
def find_missing_numbers(nums):
    nums += [-1,-1]
    for i in range(len(nums)):
        while(nums[i]>0 and nums[i]!=nums[nums[i]-1]):
            nums[nums[i]-1],nums[i] = nums[i],nums[nums[i]-1]
    res = []
    for i,e in enumerate(nums):
        if(e!=i+1): res.append(i+1)
    if(len(res)>1): return res
    elif(len(res)==1): return res+[len(nums)]
    return [len(nums),len(nums)+1]

print(find_missing_numbers([1]))

