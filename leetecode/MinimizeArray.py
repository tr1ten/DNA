import bisect
class RG:
    def __getitem__(self, key):
        return key
class Solution:
    def minimizeArrayValue(self, A: List[int]) -> int:
        def ok(x):
            d = 0
            for i in reversed(range(1,len(A))):
                if(A[i]+d>x):d += A[i]-x
                else: d = 0
            return A[0]+d<=x
        res = bisect.bisect_left(RG(),True,0,max(A)+1,key=ok) # ultimate binary search hahaha
        return res
