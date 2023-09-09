from collections import Counter
from functools import cache
def solve(A):
    cnt = Counter()
    for x in A:
        cnt[x] += x
    si = sorted(set(A))
    @cache
    def dp(idx,taken):
        if idx==len(si): return 0
        res = dp(idx+1,False)
        if si[idx]-1 not in cnt or not taken:
            res = max(res,cnt[si[idx]]+dp(idx+1,True))
        return res
    return dp(0,False)
print(solve([3,3,3,4,4,1,8]))

    