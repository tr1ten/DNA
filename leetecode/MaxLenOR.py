# 1- The idea for optimised solution is that we need to find out the condition where we can stop looking for different ans.
# 2- we will take two value with curr_or=arr[i] and pre_or=0 and we will traverse from i to 0 until we make sure we have reached the origin or where pre_or become  equal to curr_or.
from collections import OrderedDict
class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        BITS = 32 # total bits in number
        od = OrderedDict()
        r = set()
        for j,x in enumerate(arr):
            items = list(reversed(od.items()))
            # print(od)
            k = 0
            val = x
            r.add(x)
            while(k<len(items)):
                _,idx = items[k]
                while(k<len(items) and items[k][1]==idx):
                    val |= 1<<items[k][0]
                    k +=1
                r.add(val)
            for i in range(BITS):
                if(x&(1<<i)>0):
                    if(i in od): del od[i]
                    od[i] = j
        # print(r)
        return len(r)
