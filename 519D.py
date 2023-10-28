import sys
import string
from collections import defaultdict,Counter
def solve(vals,s):
    past = defaultdict(Counter)
    pref = 0
    res = 0
    for x in s:
        res +=past[x][pref]
        pref +=vals[ord(x) - ord('a')]
        past[x][pref] +=1 
    return res
# input
# t = int(sys.stdin.readline())
# solve here
# input processing
for _ in range(1):
    vals = list(map(int,input().split()))
    s = input()
    print(solve(vals,s))
    
    