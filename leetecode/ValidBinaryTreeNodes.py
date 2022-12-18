from DS import dsu
class Solution:
    def validateBinaryTreeNodes(self, n: int, lc: List[int], rc: List[int]) -> bool:
        uf = dsu.DSU(n)
        ind = [0 for i in range(n)]
        for i in range(n):
            if(lc[i]!=-1):
                if(uf.find(lc[i])==uf.find(i)): return False
                uf.union(i,lc[i])
                ind[lc[i]]+=1
            if(rc[i]!=-1):
                if(uf.find(rc[i])==uf.find(i)): return False
                uf.union(i,rc[i])
                ind[rc[i]] +=1
        return uf.cnt==1 and max(ind)<2
