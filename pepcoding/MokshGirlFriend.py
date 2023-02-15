import sys
from array import array

# input
t = 1
# solve here
def update(diff,x,l,r):
    diff[l] +=x
    if(r+1<len(diff)): diff[r+1] -=x;
def cvt(diff):
    arr = array('l')
    for i in range(len(diff)): arr.append(0)
    arr[0] = diff[0]
    for i in range(1,len(diff)): arr[i] = diff[i]+arr[i-1]
    return arr
# input processing
for _ in range(t):
    N,Q,M  = map(int,input().split())
    diff = array('l')
    for i in range(N): diff.append(0)
    queries = []
    for _ in range(Q):
        l,r = map(int,input().split())
        update(diff,1,l,r)
        queries.append((l,r))
    pref_eq = array('l')
    pref_just_larger = array('l')
    for i in range(N+1): pref_eq.append(0)
    for i in range(N+1): pref_just_larger.append(0)
    arr = cvt(diff)
    for i in range(1,len(diff)+1):
        pref_eq[i] = pref_eq[i-1] + (1 if(arr[i-1]==M) else 0)
        pref_just_larger[i] = pref_just_larger[i-1] + (1 if(arr[i-1]==M+1) else 0)
    total_cnt = pref_eq[-1]
    res = 0
    for l,r in queries:
        res = max(res,total_cnt-(pref_eq[r+1]-pref_eq[l])+(pref_just_larger[r+1]-pref_just_larger[l]))
    print(res)
