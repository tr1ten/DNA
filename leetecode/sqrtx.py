def binarysearch(arr,target):
    start = 0
    end = len(arr)-1
    while start <= end:
        mid = (end+start)//2
        if(target == arr[mid]*arr[mid]):
            return arr[mid]
        if((arr[mid]*arr[mid])>target):
            end = mid - 1
        else:
            start = mid + 1
    return arr[mid] if (arr[mid]*arr[mid]<target or mid==0)  else arr[mid-1]
print(binarysearch((range(1,9)),8))