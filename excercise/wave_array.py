def wave(arr):
    arr.sort()
    for i in range(1,len(arr),2):
        arr[i],arr[i-1] = arr[i-1],arr[i]
    return arr

print(wave([1,2,3,4]))