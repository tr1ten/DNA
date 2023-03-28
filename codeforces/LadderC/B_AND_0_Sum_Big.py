import math
def f(n,k): return (n**k)%(10**9 + 7)
t = int(input())
while(t):
    n,k= map(int,input().split())
    print(f(n,k))
    t -=1