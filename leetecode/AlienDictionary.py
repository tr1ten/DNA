from typing import (
    List,
)
from collections import *
import heapq
class Solution:
    """
    @param words: a list of words
    @return: a string which is correct order
    """
    def alien_order(self, w: List[str]) -> str:
        adj = defaultdict(list)
        ind = {y:0 for x in w for y in x}
        for i in range(len(w)-1):
            for x,y in zip(w[i],w[i+1]):
                if x!=y:
                    adj[x].append(y)
                    ind[y] +=1
                    break
            else:
                if len(w[i])>len(w[i+1]): return "" # edge case where invalid string given
        dq=  []
        for x in ind:
            if ind[x]==0: dq.append(x)
        heapq.heapify(dq) # need lexigraphiclly smallest ordering
        res = ""
        while(dq):
            u = heapq.heappop(dq)
            res +=u
            for v in adj[u]:
                ind[v] -=1
                if ind[v]==0: heapq.heappush(dq,v)
        return "" if len(res)!=len(ind) else res

            

