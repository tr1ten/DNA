class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        i=0
        res = 0
        p = "$"+p
        done = set()
        for j in range(1,len(p)):
            pref = p[i:j]
            if((ord(p[j])-ord(p[j-1]))%26!=1 or pref in done): i = j
            if(pref[i:j+1] not in done): res += (j-i+1)
            done.add(pref[i:j+1])
        return res
                