from functools import cache
from itertools import accumulate
@cache
def fast_pow(a, b, m):
    if b == 0:
        return 1
    if b == 1:
        return a % m
    if b % 2 == 0:
        return fast_pow(a * a % m, b // 2, m)
    else:
        return a * fast_pow(a * a % m, b // 2, m) % m
mod = 10**9 + 7
t = int(input())
while(t):
    t -= 1
    n,m = map(int,input().split())
    a = list( map(int,input().split()))
    s = input()
    p = [[0]*(n+1) for j in range(n+1)]  # prob of sum i to j at current query
    p[0][n-1] = 1
    for idx in range(m+1): # we will try to find out the contribution of each prob
        tp = [[0]*(n+1) for j in range(n+1)] 
        if(idx-1>=0): # calculate probabilty from difference array
            if(s[idx-1]=='L'):
                for i in range(n):
                    for j in range(1,n+1):
                        p[i][j] += p[i][j-1] 
                        p[i][j] %= mod
            else:
                for j in range(n):
                    for i in range(1,n+1):
                        p[i][j] += p[i-1][j] 
                        p[i][j] %= mod
        if idx==m: continue
        for i in range(n):
            for j in range(i,n):
                if i==j: # this will still contribute to next state
                    tp[i][i] = (tp[i][i]+p[i][j])%mod
                    if(s[idx]=='L'): tp[i][i+1] = (tp[i][i+1]-p[i][j])%mod
                    else: tp[i+1][i] = (tp[i+1][i]-p[i][j])%mod
                    continue
                inv = fast_pow(j-i,mod-2,mod)
                prob  = (inv*p[i][j])%mod
                if(s[idx]=='L'):
                    tp[i][i] = (tp[i][i]+prob)%mod
                    tp[i][j] = (tp[i][j] -prob)%mod
                else:
                    tp[i+1][j] = (tp[i+1][j]+prob)%mod
                    tp[j+1][j] = (tp[j+1][j]-prob)%mod
        p = tp
    res = 0
    for i in range(n):
        sm = 0
        for j in range(i,n):
            sm =(sm+a[j])%mod
            res += (p[i][j]*sm)%mod
            res %=mod
    print(res)
            