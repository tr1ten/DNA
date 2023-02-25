from typing import List
class Solution:
    def longestRepeating(self, s: str, qc: str, qis: List[int]) -> List[int]:
        rq = RangeQuery(len(s))
        for i in range(len(s)):
            rq.update(i,s[i])
        res = []
        for i,ind in enumerate(qis):
            rq.update(ind,qc[i])
            res.append(rq.mxsz())
        return res

class Segment:
    def __init__(self) -> None:
        self.sz = 0
        self.pref = 0
        self.prefc = '$'
        self.suff = 0
        self.suffc = '$'
        self.best = 0
        self.bestc = '$'
class RangeQuery :
    def __init__(self,n:int) :
        # approx power of 2
        self.n =  2**(n-1).bit_length()
        self.tree:List[Segment] = [Segment() for i in range((2 * self.n + 1))]  # 1 based indexing 
        
    def _parent(self,i:int) -> int:
        return i//2;
    def _childs(self,i:int) -> List[int]:
        return [2*i,2*i+1];
    def mxsz(self):
        return self.tree[1].best
    def update(self,index:int,nc:str) -> None:
        i = index+self.n # node in the tree
        self.tree[i].bestc = self.tree[i].prefc = self.tree[i].suffc = nc
        self.tree[i].sz = self.tree[i].pref = self.tree[i].suff = self.tree[i].best = 1
        i = self._parent(i)
        while(i>0):
            left,right = self._childs(i);
            par = self.tree[i];
            ls,rs = self.tree[left],self.tree[right];
            par.suff = rs.suff
            par.suffc = rs.suffc
            par.pref = ls.pref
            par.prefc = ls.prefc
            par.sz = ls.sz + rs.sz
            if(ls.suffc==rs.prefc and ls.suff+rs.pref>max(ls.best,rs.best)):
                par.best = ls.suff+rs.pref
                par.bestc = ls.suffc
                if(ls.pref==ls.sz):
                    par.pref = ls.pref+rs.pref
                if(rs.suff==rs.sz):
                    par.suff = rs.suff + ls.suff
            else:
                if(ls.best>rs.best):
                    par.best = ls.best
                    par.bestc = ls.bestc
                else:
                    par.best = rs.best
                    par.bestc = rs.bestc
            i = self._parent(i)