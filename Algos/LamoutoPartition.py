# odd...even
# not ordered
def seg(arr):
    i = 0
    for j in range(len(arr)):
        if arr[j]%2==1:
            arr[j],arr[i] = arr[i],arr[j]
            i +=1
    

arr = [2,1,4,1,3,6,10,9]
seg(arr)
print(arr)