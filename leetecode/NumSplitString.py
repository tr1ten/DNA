class Solution:
    def numWays(self, s: str) -> int:
        pref=  [0]
        mod = 10**9 + 7
        cnt = s.count('1')
        if(cnt%3>0 or len(s)<3): return 0
        if(cnt==0): return ((len(s)-1)*(len(s)-2)//2)%mod
        c = cnt//3;
        r1=0
        r2 = 0
        sm = 0
        for x in s:
            sm += x=='1'
            if(sm==c): r1+=1
            if(sm==2*c): r2 +=1
            r1%=mod
            r2 %=mod
        return (r1*r2)%mod
        