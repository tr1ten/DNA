MOD =7696602525769
P = 100003
MAXN = 10**5+ 3;
pp = [1]
def powers():
    for i in range(len(pp),MAXN):
        pp.append((pp[-1]*P)%MOD)
def hash(s):
    n = len(s)
    h = 0
    for i in range(n):
        h = (h + (s[i] + 1)*pp[n-i-1])%MOD
    return h
def rolling_hash(old_hash,k,prev,next):
    return (((old_hash + MOD-prev*(pp[k-1]))*P)%MOD + next)%MOD
powers()

class Solution:
    def longestCommonSubpath(self, n: int, paths: List[List[int]]) -> int:
        def ok(x):
            old = None
            for i,s in enumerate(paths):
                if x>len(s): return False
                new = set()
                hh = hash(s[:x])
                if not old or hh in old: new.add(hh)
                for j in range(x,len(s)):
                    hh = rolling_hash(hh,x,s[j-x]+1,1+s[j])
                    if not old or hh in old: new.add(hh)
                old = new
                if not old: return False
            return True
        r = 0
        for i in range(32,-1,-1):
            if(ok(r + (1<<i))): r += (1<<i);
        return r