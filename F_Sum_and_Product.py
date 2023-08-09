import sys
from collections import Counter
import math
def issq(x):
    a = int(math.sqrt(x))
    return a**2 == x
# input
t = int(sys.stdin.readline())
# solve here
def solve():
    n = int(input())
    A = list(map(int,input().split()))
    cnt = Counter(A)
    q = int(input())
    for _ in range(q):
        x,y = map(int,input().split())
        d = x*x - 4*y
        if d<0 or not issq(d):
            print(0,end=" ")
            continue
        sq = math.sqrt(d)
        a1 = 0
        b1 = 0
        if (x + sq)%2==0:
            a = (x+sq)//2
            a1 = (cnt[a])
        if (x - sq)%2==0:
            b = (x-sq)//2
            b1 = cnt[b]
        print(a1*(a1-1)//2 if d==0 else a1*b1,end=" ")
    print()
        
        
# input processing
for _ in range(t):
    solve()