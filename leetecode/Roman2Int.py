class Solution:
    def romanToInt(self, s: str) -> int:
        d = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        d2 = ['I','V','X','L','C','D','M']
        res =0
        for i,x in enumerate(s):
            j = d2.index(x)
            if(j+1<len(d2) and i+1<len(s) and d2[j+1]==s[i+1]): res += -d[x]
            elif(j+2<len(d2) and i+1<len(s) and d2[j+2]==s[i+1]): res += -d[x]
            else: res += d[x]
        return res
            