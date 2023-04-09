from typing import List

class RangeQuery :
    def __init__(self,n:int) :
        # approx power of 2
        self.n =  2**(n-1).bit_length()
        self.tree = [0] * (2 * self.n + 1) # 1 based indexing 
        
    def _parent(self,i:int) -> int:
        return i//2;
    def _childs(self,i:int) -> List[int]:
        return [2*i,2*i+1];
    
    def update(self,index:int,diff:int) -> None:
        i = index+self.n # node in the tree
        self.tree[i] +=diff
        i = self._parent(i)
        while(i>0):
            left,right = self._childs(i);
            self.tree[i] = max(self.tree[left],self.tree[right])
            i = self._parent(i)
        
    def _query(self,ns:int,ne:int,start:int,end:int,node:int) -> int:
        if(ns==start and ne==end): # perfect match
            return self.tree[node] 
        if(ne < start or end<ns): return float('-inf') # doesn't lie in the range
        mid = (ns+ne)//2;
        left,right = self._childs(node)
        return max(self._query(ns,mid,start,min(mid,end),left) , self._query(mid+1,ne,max(start,mid+1),end,right))
    def query(self,left,right):
        return self._query(0,self.n-1,left,right,1);
   
def main():
    n = 5                                       
    arr = [-1,-2,-10,-4,-5]
    rq = RangeQuery(5)
    for i in range(n):
        rq.update(i,arr[i])
    print(rq.query(0,4))
    rq.update(0,10)
    
if __name__ == "__main__":
    main()
    