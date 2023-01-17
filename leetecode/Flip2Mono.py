class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        n = len(s)
        ltr = [0]*(n)
        rtl = [0]*(n)
        for i in range(n):
            ltr[i] = (1 if(s[i]=='1') else 0) + (ltr[i-1] if i-1>=0 else 0)
            rtl[n-i-1] = (1 if(s[n-i-1]=='0') else 0) + (rtl[n-i] if n-i<n else 0)
        mn = inf
        # print(ltr,rtl)
        for i in range(len(s)):
            mn = min(mn,ltr[i]+rtl[i]-1)
        return mn

