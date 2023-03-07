from os import *
from sys import *
from collections import *
from math import *

from typing import List


def countPartitions(n: int, d: int, arr: List[int]) -> int:
    # write your code here
    @lru_cache(None)
    def solve(cur, idx,target):
        if (cur > target): return 0
        if (idx >= n): return cur==target
        return solve(cur+arr[idx], idx+1,target) + solve(cur, idx+1,target)
    s = sum(arr)
    s1 = (s+d)/2
    return solve(0,0,s1)%(10**9 + 7)
