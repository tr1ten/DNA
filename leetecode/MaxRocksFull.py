import heapq
class Solution:
    def maximumBags(self, cp: List[int], rk: List[int], ad: int) -> int:
        q = [y-x for x,y in zip(rk,cp)]
        heapq.heapify(q)
        res =0
        while(len(q)>0 and q[0]<=ad):
            ad -= heapq.heappop(q)
            res +=1
        return res
