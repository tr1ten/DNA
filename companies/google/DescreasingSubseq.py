from typing import List
from bisect import bisect_right as br,insort
def min_decreasing_partitions(arr: List[int]) -> int:
    dp = [] # too bad sortedcontainers are not allowed
    for x in arr:
        ind = br(dp,x);
        if(len(dp)>ind):
            dp.pop(ind)
        insort(dp,x)
    return len(dp)

if __name__ == '__main__':
    arr = [int(x) for x in input().split()]
    res = min_decreasing_partitions(arr)
    print(res)