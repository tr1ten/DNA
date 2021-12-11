
# main idea use i for index of  last  smaller element than pivot  than i+1 would be the correct pos for pivot index
def partition(arr, l, r):
    i = l-1
    j = l
    while j<r:
        if(arr[j]<arr[r]):
            i +=1
            arr[j],arr[i] = arr[i],arr[j]
        j +=1
    arr[i+1],arr[r] = arr[r],arr[i+1]
    return i+1
def quickSort(arr, l, r):
    if(l >= r):
        return
    pi = partition(arr, l, r)
    quickSort(arr, l, pi-1)
    quickSort(arr, pi+1, r)


if(__name__ == "__main__"):
    arr = [1, 23, 41, 12, 2, 23, 0]
    quickSort(arr, 0, 6)
    print(arr)
