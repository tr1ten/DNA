# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
import bisect
from collections import Counter
def solution(A, X):
    # Implement your solution here
    sc = []
    cnt = Counter(A)
    A = sorted(cnt.keys())
    res = 0
    for h in A:
        minw = -(-X//h)
        ws = len(sc) - bisect.bisect_left(sc,minw)
        c = min(cnt[h]//2,1)
        res +=ws*(c)
        if cnt[h]>=4: res+=1
        if c: sc.append(h)
    return res

A = list(map(int,input().split()))
X=  int(input())
print(solution(A,X))