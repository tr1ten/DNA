class Solution:
    def longestDecomposition(self, s: str) -> int:
        P = 31
        MOD = 10**9 + 7
        def greedy(i,j):
            if(i>j): return 0
            if(i==j): return 1
            res = 1
            rh=h=0
            p = 1
            while(i<j):
                h = (h+((ord(s[i])-ord('a')+1)*p)%MOD)%MOD
                p *= P
                rh = (rh*P+(ord(s[j])-ord('a')+1))%MOD
                if(h==rh): 
                    res = max(res,greedy(i+1,j-1)+2)
                    break
                i +=1
                j -=1
            return res
        return greedy(0,len(s)-1)