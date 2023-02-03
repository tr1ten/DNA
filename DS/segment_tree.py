from typing import List

class RangeQuery :
    def __init__(self,n:int) :
        # approx power of 2
        self.n =  2**(n-1).bit_length()
        self.tree = [0] * (2 * self.n + 1) # 1 based indexing 
        self.max_tree = [0]*(2 * self.n + 1)
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
        mid = (ns+ne)//2;
        left,right = self._childs(node)
        return self._query_sum(ns,mid,start,min(mid,end),left) + self._query_sum(mid+1,ne,max(start,mid+1),end,right)
    def query_sum(self,left,right):
        return self._query_sum(0,self.n-1,left,right,1);
    
    def _query_max(self,ns:int,ne:int,start:int,end:int,node:int) -> int:
        if(ns==start and ne==end): # perfect match
            return self.max_tree[node] 
        if(ne < start or end<ns): return float('-inf') # doesn't lie in the range
        mid = (ns+ne)//2;
        left,right = self._childs(node)
        return max(self._query_max(ns,mid,start,min(mid,end),left),self._query_max(mid+1,ne,max(start,mid+1),end,right))
    def query_max(self,left,right):
        return self._query_max(0,self.n-1,left,right,1);
            
def main():
    n = 5
    arr = [1,2,3,4,5]
    rq = RangeQuery(n)
    for i in range(n):
        rq.update(i,arr[i])
    print(rq.tree,rq.max_tree)
    print(rq.query_sum(0,4))
    rq.update(0,10)
    print(rq.query_max(0,2))
    
if __name__ == "__main__":
    main()
    