from typing import (
    List,
)
from functools import cache
import sys
sys.setrecursionlimit(10000)
class Solution:
    """
    @param a: a list of integer
    @param b: an integer
    @return: return a list of integer
    """
    def cheapest_jump(self, a: List[int], b: int) -> List[int]:
        @cache
        def rec(i):
            if i>=len(a) or a[i]==-1: return float('inf'),[]
            if i==len(a)-1: return a[i],[i+1]
            res = (float('inf'),[],-1)
            for k in (range(i+1,min(i+b+1,len(a)))):
                res = min(res,rec(k),key=lambda x:(x[0],-len(x[1])) )
            # print("choose ",res, " at ",i)
            res = (res[0]+a[i],res[1] + [i+1])
            return res
        res = rec(0)
        if res[0]==float('inf'): return []
        # print(res)
        return res[1][::-1]
                
cs = Solution();
a = list(map(int,input().split(",")))
b = int(input())
print(cs.cheapest_jump(a,b))