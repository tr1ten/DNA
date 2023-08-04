from functools import cache
S = input()
@cache
def dp(l,r,s,e):
    if l==r: return 0 if s!=e else not s==S[l];
    return min((S[l]!=s) + dp(l+1,r,s,e), (S[l]!=e) + dp(l+1,r,e,e), (S[r]!=e) + dp(l,r-1,s,e), (S[r]!=s) + dp(l,r-1,s,s))

@cache
def dp1(idx,f,c):
    if idx==len(S): return 0
    if f: return (S[idx]!=c) + dp1(idx+1,f,c)
    res = dp1(idx+1,(S[idx]!=c),S[idx]);
    res = min(res,(S[idx]!=c) + dp1(idx+1,f,c))
    return res
res = float('inf')
for s in ["a","b"]:
    for e in ["a","b"]:
        res = min(res,dp(0,len(S)-1,s,e))
print(res,min(dp1(0,0,'a'),dp1(0,0,'b')) )