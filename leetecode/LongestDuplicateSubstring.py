P = 31
MOD = 10**9 + 7
def fast_pow(a, b, m):
    if b == 0:
        return 1
    if b == 1:
        return a % m
    if b % 2 == 0:
        return fast_pow(a * a % m, b // 2, m)
    else:
        return a * fast_pow(a * a % m, b // 2, m) % m
    
def rabin(s):
    n = len(s);
    pp = [1]*n
    pinv = [1]
    for i in range(1,n): 
        pp[i] = (pp[i-1]*P)%MOD
        pinv.append(fast_pow(pp[i],MOD-2,MOD));
    hash = [0]*(n+1) # 1 index hash
    for i in range(n): hash[i+1] = (hash[i] + ((ord(s[i])-ord('a')+1)*pp[i])%MOD )%MOD
    # for substring i,j do hash[j+1] - hash[i] + MOD
    # cur = (hash*pp[i])
    return hash,pp.pinv

class Solution:
    def longestDupSubstring(self, s: str) -> str:
        hash,pp,pinv = rabin(s)
        print(pp,hash)
        def check(x):
            st = set()
            for i in range(0,len(s)-x+1):
                j = i + x -1
                cur = ((hash[j+1]-hash[i])*pinv[i])%MOD
                if(cur in st): return (i,j)
                st.add(cur)
            return None
        lo,hi = 0,len(s)
        res = {0,-1}
        while(lo<=hi):
            mid = (lo+hi)//2
            temp = check(mid)
            if(temp): 
                res = temp
                lo = mid+1
            else: hi = mid-1
        return s[res[0]:res[1]+1]
                
    