from collections import *
def solve(nxt,k): # assume zero index
    if k==1:
        for i in range(len(nxt)): 
            if nxt[i]!=i+1: return False
    nxt = [x-1 for x in nxt]
    n = len(nxt)
    cycle = [-1]*n
    for i in range(n):
        if(cycle[i]!=-1): continue
        path =[i]
        cycle[i] = -2
        while cycle[nxt[path[-1]]]==-1:
            path.append(nxt[path[-1]])
            cycle[path[-1]] = -2 # -2 processing
        last = path[-1]
        if cycle[nxt[last]]!=-2: # if part of chain
            for v in path[::-1]: 
                cycle[v] = cycle[nxt[last]]
            continue
        cyc = False
        sz = 0
        for v in path:
            cyc = cyc | (nxt[last]==v)
            if cyc: sz +=1
        if sz!=k: return False
    return True


import sys


# input
t = int(sys.stdin.readline())
# solve 
# input processing
for _ in range(t):
    n,k = map(int,input().split())
    A = list(map(int,input().split()))
    if(solve(A,k)): print("YES")
    else: print("NO")