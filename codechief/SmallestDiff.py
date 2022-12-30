import sys
T = int(sys.stdin.readline())
for _ in range(T):
    N,M = map(int, sys.stdin.readline().split())
    mat = map(int, sys.stdin.readline().split())
    mx = mat[0]
    mxInd = 0
    mn = mat[0]
    mnInd = 0
    for i in range(N*M):
        if(mat[i]>mx):
            mx = mat[i]
            mxInd = i
        if(mat[i]<mn):
            mn = mat[i]
            mnInd = i
    mat[0],mat[mxInd] = mat[mxInd],mat[0]
    mat[N*M-1],mat[mnInd] = mat[mnInd],mat[N*M-1]
    for i in range(N):
        for j in range(M):
            print(mat[i*M+j],end=" ")
        print()