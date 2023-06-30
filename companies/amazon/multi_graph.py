def solve(A,n,m):
    maxs = [float('-inf')]*m # find highest value for each column
    for i in range(n):
        for j in range(m):
            maxs[j] = max(A[i][j],maxs[j])
    bp = -1
    bpl = 0
    for i in range(n): # we will find max continous sequence with highest score for each player
        pref =0 
        mxs = 0
        for j in range(m):
            if A[i][j]==maxs[j]: pref +=1
            else: pref = 0
            mxs = max(mxs,pref)
        if bp==-1 or bpl<mxs:
            bp = i
            bpl = mxs
    return bp+1 # 0 index 
            
n = int(input())
m = int(input())
A = []
for i in range(n):
    A.append(list(map(int,input().split())))

print(solve(A,n,m))