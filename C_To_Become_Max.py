import sys

from collections import deque
# input
t = int(sys.stdin.readline())
# solve here
def solve():
    n,k = map(int,input().split())
    A = list(map(int,input().split()))
    def ok(x):
        for i in range(len(A)):
            req = x
            ck = k
            for j in range(i,n):
                if A[j]>=req: return 1
                cost = req-A[j]
                if ck<cost: break
                ck -=cost
                req -=1
        return 0
    lo,hi = max(A),10**10
    ans = lo
    while lo<=hi:
        mid = (lo+hi)//2
        if ok(mid):
            lo = mid+1
            ans = mid
        else: hi =  mid-1
    return ans
                
# input processing
for _ in range(t):
    print(solve())