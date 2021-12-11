def binarysearch(arr,target):
    start = 0
    end = len(arr)-1
    while start <= end:
        mid = (end+start)//2
        if(target == arr[mid]):
            return mid
        if(arr[mid]>target):
            end = mid - 1
        else:
            start = mid + 1
    return -1
print(binarysearch([1,3,5,7,8,10],2))