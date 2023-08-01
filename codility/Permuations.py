import math
mod = 10**9 + 7
def cycle_lcm(A):
    n = len(A)
    vis = [0]*n
    prod = 1 
    gcd = -1
    for i in range(n):
        if vis[i]: continue
        cur = i
        lg = 0
        while not vis[cur]:
            vis[cur] = True
            cur = A[cur] - 1
            lg+=1
        prod = prod*lg%mod
        if gcd==-1: gcd = lg
        else: gcd = math.gcd(gcd,lg)
    return (prod*pow(gcd,mod-2,mod))%mod

A = list(map(int,input().split()))
print((cycle_lcm(A)-1+mod)%mod)