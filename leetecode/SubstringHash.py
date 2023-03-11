class Solution:
    def subStrHash(self, s: str, p: int, mod: int, k: int, hsh: int) -> str:
        n = len(s)
        h = 0
        p = 1
        j = n-1
        for i in reversed(range(n)):
            if(j-i+1>k):
                h = ((h*p +mod - (ord(s[j])-ord('a')+1)*pow(p,k,mod))%mod + (ord(s[i])-ord('a')+1))%mod
                j -=1
                if(h==hsh): return s[i:j+1]
            else:
                h = (h*p + (ord(s[i])-ord('a')+1))%mod
        return s