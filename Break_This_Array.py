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
    pre=[0]
    for i in range(n): pre.append((pre[-1] + a[i])%mod)
    @cache
    def rec(i,j):
        if j-i+1==1: 
            return (pre[j+1] - pre[i] + mod)%mod
        res = 0
        inv = fast_pow(j-i,mod-2,mod)
        for k in range(i,j):
            res += (rec(i,k)*inv)%mod
            res %=mod
        return res
    print(rec(0,n-1))
            