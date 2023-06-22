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
    p = [[[0]*(n+1) for j in range(n+1)] for i in range(m+1)] # prob of sum i to j at kth query
    p[0][0][n] = -1
    p[0][0][n-1] = 1
    for idx in range(m+1): # we will try to find out the contribution of each prob
        for i in range(n):
            for j in range(1,n+1):
                p[idx][i][j] += p[idx][i][j-1] 
                # p[idx][i][j] %= mod
        if idx==m: continue
        for i in range(n):
            for j in range(i,n):
                if i==j: # this will still contribute to next state
                    p[idx+1][i][i] = (p[idx+1][i][i]+p[idx][i][j])%mod
                    p[idx+1][i][i+1] = (p[idx+1][i][i+1]-p[idx][i][j])%mod
                    continue
                inv = fast_pow(j-i,mod-2,mod)
                prob  = (inv*p[idx][i][j])%mod
                if(s[idx]=='L'):
                    p[idx+1][i][i] = (p[idx+1][i][i]+prob)%mod
                    p[idx+1][i][j] = (p[idx+1][i][j] -prob)%mod
                else:
                    p[idx+1][i+1][j+1] = (p[idx+1][i+1][i+1]+prob)%mod
                    p[idx+1][j][j+1] = (p[idx+1][i+1][j+1]-prob)%mod
    res = 0
    for i in range(n):
        sm = 0
        for j in range(i,n):
            sm =(sm+a[j])%mod
            res += (p[m][i][j]*sm)%mod
            res %=mod
    print(res)
            