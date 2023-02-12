class Solution:
    def minimumScore(self, s: str, t: str) -> int:
        ns,nt = len(s),len(t)
        pref = [ns]*(nt+1) # occ of char t[i] in s
        suff = [-1]*(nt+1) # occ of char t[i] in reversed s
        pref[0] = -1
        suff[-1] = ns
        ti = 0
        for i in range(ns):
            if(ti>=nt): break
            if(s[i]==t[ti]): 
                pref[ti+1] = i;
                ti +=1
        ti = nt-1
        for i in reversed(range(ns)):
            if(ti<0): break
            if(s[i]==t[ti]): 
                suff[ti] = i;
                ti -=1
        # print(pref,suff)
        def check(x):
            for i in range(0,nt-x+1):
                if(pref[i]<suff[i+x]): return True
            return False
        lo,hi=0,len(t)
        while(lo<hi):
            mid=(lo+hi)//2;
            if(check(mid)): hi=mid
            else: lo=mid+1
        return lo