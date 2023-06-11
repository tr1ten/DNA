import sys
# Maximum Subarray Sum having size at most k
# https://leetcode.com/discuss/interview-question/3624333/Maximum-Subarray-Sum-having-size-at-most-k
# input
# t = int(sys.stdin.readline())
# monotonic stack
from collections import *
def solve(A,k):
    dq = deque()
    start,end = 0,0
    sm = 0
    res=0
    for i,x in enumerate(A):
        sm +=x
        while(dq and dq[0][1]<i-k): dq.popleft()
        while(dq and dq[-1][0]>=sm): dq.pop()
        val = sm-(dq[0][0] if dq else 0)
        if val>res:
            start,end = dq[0][1] if dq else i,i
            res = val
        dq.append((sm,i))
    return A[start+1:end+1]
for _ in range(1):
    n = int(input())
    A = list(map(int,input().split()))
    k = int(input())
    print(solve(A,k))