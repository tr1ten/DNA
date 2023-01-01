class Solution:
    def findLUSlength(self, strs: List[str]) -> int:
        res = -1
        strs.sort(key=lambda s: -len(s))
        for i in range(len(strs)):
            fl = True
            for j in range(len(strs)):
                if(i==j or len(strs[i])>len(strs[j])): continue
                p1,p2 = 0,0
                while(p1<len(strs[i]) and p2<len(strs[j])):
                    if(strs[i][p1]==strs[j][p2]):
                        p1 +=1
                    p2 +=1
                if(p1==len(strs[i])): fl = False
            if(fl): return len(strs[i])
        return -1

            
            