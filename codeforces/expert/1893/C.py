# Problem: C. Freedom of Choice
# Contest: Codeforces - Codeforces Round 908 (Div. 1)
# URL: https://codeforces.com/problemset/problem/1893/C
# Memory Limit: 512 MB
# Time Limit: 3000 ms
# 
# Powered by CP Editor (https://cpeditor.org)

from collections import defaultdict
import sys

MOD = 10**9+7  # change me for god sake look at problem mod
INF = 10**17+5
A = 10**17+101
MDIFF = 10**5+1

def testcase():
    m = int(input())
    sli = 0
    sri = 0
    cnt = defaultdict(int)
    req = defaultdict(int)
    tot = 0
    for _ in range(m):
        n, l, r = map(int, input().split())
        tot += r - l
        sri += r
        sli += l
        if sri >= A:
            print(0)
            return
        b = list(map(int, input().split()))
        ci = list(map(int, input().split()))
        sm = sum(ci)
        for j in range(n):
            left = sm - ci[j]
            cnt[b[j]] += max(0, r - max(left, l))
            req[b[j]] += max(0, -(left - l))
    ans = INF
    for ss in range(sli, sri + 1):
        ex = ss - sli
        diff = ex - (tot - cnt[ss])
        ans = min(ans, max(0, diff) + req[ss])
        if ans == 0:
            break
    print(ans)

def main():
    T = int(input())
    for _ in range(T):
        testcase()

if __name__ == "__main__":
    main()