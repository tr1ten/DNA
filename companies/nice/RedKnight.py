from collections import *
import sys
t = int(sys.stdin.readline())
def solve(A):
    df = (defaultdict(lambda :[float('-inf'),float('-inf') ] ))
    for x in A:
        key = (str(x)[0],str(x)[-1])
        if df[key][0] < x :
            df[key][1] = df[key][0]
            df[key][0] = x
        elif df[key][1] < x :
            df[key][1] = x
    return max(-1,max([x+y for x,y in df.values()]))
for _ in range(t):
    A = map(int,input().split())
    print(solve(A))