from typing import List
mod = 998244353
# battle tested
class RangeQuery :
    def __init__(self,n:int,bv=0,comb=max,upd=sum) :
        # approx power of 2
        self.n =  2**(n-1).bit_length()
        self.base_val = bv
        self.comb = comb    
        self.upd = upd
        self.tree = [bv for i in range((2 * self.n + 1))]  # 1 based indexing 
        
    def _parent(self,i:int) -> int:
        return i//2;
    def _childs(self,i:int) -> List[int]:
        return [2*i,2*i+1];
    
    def update(self,index:int,diff) -> None:
        i = index+self.n # node in the tree
        self.tree[i] =self.upd(self.tree[i],diff)
        i = self._parent(i)
        while(i>0): # propagate
            left,right = self._childs(i);
            self.tree[i] =  self.comb(self.tree[left],self.tree[right])
            i = self._parent(i)
        
    def _query(self,ns:int,ne:int,start:int,end:int,node:int) -> int:
        if(ns==start and ne==end): # perfect match
            return self.tree[node] 
        if(ne < start or end<ns): return self.base_val # doesn't lie in the range
        mid = (ns+ne)//2;
        left,right = self._childs(node)
        return self.comb(self._query(ns,mid,start,min(mid,end),left) , self._query(mid+1,ne,max(start,mid+1),end,right))
    
    
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

def fn(c,d,x):
    return (c*x + d)%mod
def main():
    n,m = map(int,input().split())                                 
    arr = []
    for i in range(n):
        arr.append(list(map(int,input().split())))
    rq = RangeQuery(n,(1,0),lambda x,y: (x[0]*y[0]%mod,(y[0]*x[1] + y[1])%mod ),lambda ol,nw:nw)
    for i in range(n):
        rq.update(i,arr[i])
    for i in range(m):
        t,a,b,c = map(int,input().split())
        if t==0:
            rq.update(a,(b,c))
            arr[a] = (b,c)
        else:
            c0,d0 = rq.query(a,b-1)
            print(fn(c0,d0,c))

main()
    