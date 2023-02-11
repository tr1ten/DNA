from collections import deque,Counter
class Solution:
    def recoverArray(self, n: int, sums: List[int]) -> List[int]:
        def coq(subsums):
            if(len(subsums)==1): return [] # base case
            # assuming subset to be sorted
            mx = subsums[-1]
            mxx = subsums[-2]
            num = mx-mxx
            # assuming negative branch
            cand_set = []
            to_add = Counter()
            isvalid = False
            for x in (subsums):
                if(to_add[x]!=0): 
                    cand_set.append(x)
                    if(x==0): isvalid= True # if no zero is preset in new subsum that it is not valid subsum
                    to_add[x]-=1
                    continue
                to_add[x+num] +=1
            r2 = coq(cand_set)
            if(isvalid): return [-num]+r2
            # assuming positive branch
            cand_set = []
            to_add = Counter()
            for x in reversed((subsums)):
                if(to_add[x]!=0): 
                    cand_set.append(x)
                    to_add[x] -=1
                    continue
                to_add[x-num]+=1
            r1 = coq(cand_set)
            return [num]+r1
        sums.sort()
        return coq(sums)