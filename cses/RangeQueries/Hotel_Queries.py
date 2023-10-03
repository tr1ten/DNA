from typing import List
# battle tested
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
    def _lower(self,ns:int,ne:int,node:int,key:int):
        if self.tree[node]<key:
            return -1
        if ns==ne: return ns
        mid = (ns+ne)>>1
        l,r = self._childs(node)
        left =self._lower(ns,mid,l,key)
        if left!=-1: return left
        right = self._lower(mid+1,ne,r,key)
        return right
    def lower(self,key):
        return self._lower(0,self.n-1,1,key)
    def query(self,left,right):
        return self._query(0,self.n-1,left,right,1);
   
def main():
    n,m = map(int,input().split())                                 
    arr = list(map(int,input().split()))
    grps = list(map(int,input().split()))
    rq = RangeQuery(n)
    for i in range(n):
        rq.update(i,arr[i])
    ans = []
    for x in grps:
        idx = rq.lower(x)
        ans.append(idx+1)
        if idx>=0:
            rq.update(idx,-x)
    print(*ans)
        


main()
    