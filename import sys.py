import sys
import time
from collections import defaultdict
from functools import reduce

MOD = int(1e9 + 7)
INF = float('inf')

def euc(x1, x2, y1, y2):
    return (x1 - x2) ** 2 + (y1 - y2) ** 2

def pyn(x):
    print("YES" if x else "NO")

def testcase():
    n = int(input().strip())
    a = []
    for _ in range(n):
        x, y = map(int, input().strip().split())
        a.append((x, y))

    xs, ys, xf, yf = map(int, input().strip().split())
    mn = INF
    for i in range(n):
        mn = min(mn, euc(xf, a[i][0], yf, a[i][1]))
    mn2 = euc(xs, xf, ys, yf)
    
    pyn(mn2 < mn)

if __name__ == "__main__":
    T = int(input().strip())
    for _ in range(T):
        testcase()
