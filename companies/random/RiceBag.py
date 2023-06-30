from collections import Counter
def solve(A):
    A.sort()
    cnt = Counter()
    for x in A:
        cnt[x*x] = cnt[x] + 1
    return max(cnt.values())
        

A = list(map(int,input().split()))
print(solve(A))