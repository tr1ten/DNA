class Solution:
    def canMakePaliQueries(self, s: str, qr: List[List[int]]) -> List[bool]:
        mem = []
        prev = [0]*26
        mem.append((0,)*26)
        for i,x in enumerate(s):
            prev[ord(x)-ord('a')] +=1
            mem.append(tuple(prev))
        res = []
        for l,r,k in qr:
            oc = -1 if((r-l+1)%2==1) else 0
            for i in range(26):
                if((mem[r+1][i]-mem[l][i])%2==1): oc +=1
            res.append((oc//2)<=k)
        return res
            
            
        