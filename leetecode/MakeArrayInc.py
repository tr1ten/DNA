import bisect
class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        arr2 = sorted(set(arr2))
        def bigger(x):
            indx = bisect.bisect_right(arr2,x)
            if(indx==len(arr2)): return None
            return  arr2[indx]
        @cache
        def solve(idx,prev):
            if(idx==len(arr1)): return 0
            r1,r2 = float('inf'),float('inf')
            if(arr1[idx]>prev): r1 = solve(idx+1,arr1[idx])
            big = bigger(prev)
            if(big is not None): r2 = solve(idx+1,big) + 1
            return min(r1,r2)
        res = solve(0,float('-inf')) 
        return -1 if(res==float('inf')) else res
            