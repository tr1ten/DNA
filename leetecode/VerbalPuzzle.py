class Solution:
    def isSolvable(self, words: List[str], result: str) -> bool:
        words.append(result)
        def rec(assigned,i,j,tot,cur,mask):
            if i==len(words):
                cnt = int("".join(str(assigned[x]) for x in result))
                return tot==2*cnt
            if j>=len(words[i]): return rec(assigned,i+1,0,tot+cur,0,mask)
            start = 1 if j==0 else 0
            if words[i][j] in assigned: 
                return assigned[words[i][j]]>=start and rec(assigned,i,j+1,tot,cur*10 + assigned[words[i][j]],mask)
            for k in range(start,10):
                if (mask&(1<<k)): continue
                assigned[words[i][j]] = k
                if rec(assigned,i,j+1,tot,cur*10 + assigned[words[i][j]],mask | 1<<k): return 1
                del  assigned[words[i][j]] 
        return rec(dict(),0,0,0,0,0)