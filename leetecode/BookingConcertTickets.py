from typing import List
class BookMyShow:

    def __init__(this, n: int, m: int):
        this.rq = RangeQuery(n)
        this.zeroRow = -1 # track the index of latest zero capacity row 
        for i in range(n): this.rq.update(i,m); # add capacity of each row
        this.n = n
        this.m = m

    def gather(this, k: int, mr: int) -> List[int]:
        if(k>this.m): return [] # impossible case
        lw = this.rq.lower_max(0,this.n-1,k,1) # lowest index where max>=k
        if(lw>mr): return []
        res = (lw,this.m-this.rq.max_tree[this.rq.n+lw]) # min_row,col
        this.rq.update(lw,-k) # decrease capacity
        return res
        
    def scatter(this, k: int, mr: int) -> bool:
        if(k>this.rq.query_sum(0,mr)): return False # if total cap of <=mr rows is less than k
        i = this.zeroRow+1 # start from non zero row
        while(k>0):
            cap = this.rq.tree[i+this.rq.n];
            this.rq.update(i,-min(k,cap))
            if(cap<=k):
                this.zeroRow = i # if row cap become zero update the zero tracker
            k -=min(k,cap)
            i+=1
        return True

class RangeQuery :
    def __init__(self,n:int) :
        # approx power of 2
        self.n =  2**(n-1).bit_length()
        self.tree = [0] * (2 * self.n + 1) # 1 based indexing 
        self.max_tree = [0]*(2 * self.n + 1)
    def lower_max(self,ns:int,ne:int,k:int,node:int):
        if(self.max_tree[node]<k): return float('inf') # not found in this range
        if(ns==ne): return node - self.n # found;
        mid = (ns+ne)//2;
        l,r = self._childs(node)
        return min(self.lower_max(ns,mid,k,l),self.lower_max(mid+1,ne,k,r))
        
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


# Your BookMyShow object will be instantiated and called as such:
# Input
# ["BookMyShow","gather","scatter","gather","gather","gather"]
# [[5,9],[10,1],[3,3],[9,1],[10,2],[2,0]]

obj = BookMyShow(5,9)
print(obj.gather(10,1))
print(obj.scatter(3,3))
print(obj.gather(9,1))
print(obj.gather(10,2))
print(obj.gather(2,0))