from typing import List

class Solution:
    def handleQuery(self, nums1: List[int], nums2: List[int], queries: List[List[int]]) -> List[int]:
        pass
    
class RangeQuery :
    def __init__(self,n:int) :
        # approx power of 2
        self.n =  2**(n-1).bit_length()
        self.zero_tree = [0] * (2 * self.n + 1) # maintain count of 0s
        self.one_tree = [0]*(2 * self.n + 1) # count of 1s
    def _parent(self,i:int) -> int:
        return i//2;
    def _childs(self,i:int) -> List[int]:
        return [2*i,2*i+1];
    
    def update(self,index:int,diff:int) -> None:
        i = index+self.n # node in the tree
        self.tree[i] +=diff
        self.max_tree[i] += diff
        i = self._parent(i)
        while(i>0):
            left,right = self._childs(i);
            self.tree[i] = (self.tree[left]+self.tree[right])
            self.max_tree[i] = max(self.max_tree[left],self.max_tree[right])
            i = self._parent(i)
        
    def _query_sum(self,ns:int,ne:int,start:int,end:int,node:int) -> int:
        if(ns==start and ne==end): # perfect match
            return self.tree[node] 
        if(ne < start or end<ns): return 0 # doesn't lie in the range