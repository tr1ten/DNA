import sys
from functools import lru_cache
@lru_cache()
def dp(a,idx,state):
    if idx==len(a)-1:
        if state<4: return float('-inf') # either 4,5 state allowed for last index (4->5 zero element)
        return a[idx]
    res = -float('inf')
    if state not in [1,3,5]: res = max(res,dp(a,idx,state+1)) # not pick and move to new state
    if state<5: res = max(res,a[idx]*(1 if (state%2 == 1) else 0) + dp(a,idx+1,state+1)) # pick and move to new state
    res = max(res,a[idx]*(1 if (state%2 == 1) else 0) + dp(a,idx+1,state)) # pick and remain at current state
    return res
t = int(input())
for _ in range(t):
    input()
    A = list(map(int,input().split()))
    print(dp(tuple(A),0,1))