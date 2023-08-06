import bisect
from itertools import accumulate
class Solution:
    # @param A : list of list of long
     # @return an list of long
    def solve(self, A):
        coors = set()
        for x,y in A:
            coors.add(x)
            coors.add(y)
        coors = sorted(coors)
        diff = [0]*(len(coors) + 1)
        for x,y in A:
            l,r = bisect.bisect_left(coors,x),bisect.bisect_left(coors,y)
            diff[l] +=1
            diff[r+1] -=1
        res = [0]*(len(A)+1)
        i = 0
        diff = list(accumulate(diff))
        print(coors,diff)
        while i < (len(coors)):
            sm = diff[i]
            j = i
            while j<len(coors) and sm==diff[j]:
                j +=1
            res[sm] += coors[j-1] - coors[i]+1
            i = j
        return res
 