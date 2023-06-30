import sys
MOD = 10000007
def mod(x):
    return (x%MOD + MOD)%MOD
sys.setrecursionlimit(1000000)
def fast_pow(a, b):
    return pow(a,b,MOD);
# input
def solve():
    pass
# input processing
while(1):
    n,k = map(int,input().split());
    if n==0:break
    res = mod(fast_pow(n,k) + 2*fast_pow(n-1,k)  + fast_pow(n,n) + 2*fast_pow(n-1,n-1))
    print(res)
    