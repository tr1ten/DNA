from collections import deque
# use bfs to traveerse the tree
# at each child node we made single swap from parent greedily ( that is we will not try all possible swaps), try to repair first unplaced number
# level of bfs for the shortest k
class Solution:
    def kSimilarity(self, s1: str, s2: str) -> int:
        q = deque()
        q.append((s1,0))
        if(s1==s2): return 0
        def swap(st,i,j):
            ls = list(st)
            ls[i],ls[j] = ls[j],ls[i] 
            return "".join(ls)
        st = set()
        st.add(s1)
        while(len(q)):
            s,l = q.popleft();
            i = 0
            while(i<len(s1) and s[i]==s2[i]): 
                i +=1
            for j in range(i+1,len(s1)):
                if(s[j]==s2[j] or s[j]!=s2[i]): continue
                tar  = swap(s,i,j)
                if(tar==s2):
                    return l+1
                if(tar in st): continue
                st.add(tar)
                q.append((tar,l+1))
                
        return 0