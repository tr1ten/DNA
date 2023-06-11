import sys


# input
# solve here
def solve(P,F,m):
    v = sorted(zip(P,F),reverse=True)
    dups = []
    vis = set()
    sm = 0
    res= 0 
    for i,(p,f) in enumerate(v):
        if i<m:
            sm +=p
            if f not in vis: vis.add(f)
            else: dups.append((p,f))
            res = max(res,sm+len(vis)**2)
        else:
            if not dups: return res
            if f in vis: continue
            val = sm-dups[-1][0]+p + (len(vis)+1)**2
            if val>res: 
                sm = sm -dups.pop()[0] + p
                vis.add(f)
                res = val
    return res
for _ in range(1):
    P,F,m=list(map(int,input().split())),list(map(int,input().split())),int(input())
    print(solve(P,F,m))