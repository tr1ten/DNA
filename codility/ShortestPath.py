from collections import defaultdict,deque
def prefix2d(mat):
    for i in range(1,len(mat)):
        mat[i][0] += mat[i-1][0]
    for i in range(1,len(mat[0])):
        mat[0][i] += mat[0][i-1]
    for i in range(1,len(mat) ):
        for j in range(1,len(mat[0])):
            mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1]
    
def solve(n,m,x1,x2,y1,y2):
    mat = [[0]*(m+1) for i  in range(n+1)]
    for i in range(len(x1)):
        mat[y2[i] + 1][x1[i]] -=1
        mat[y1[i]][x2[i] + 1] -=1
        mat[y1[i]][x1[i]] +=1
        mat[y2[i] + 1][x2[i] + 1] +=1
    prefix2d(mat)
    dist = defaultdict(lambda : float('inf'))
    dist[(0,0)] = 0
    q = deque()
    q.append((0,0))
    dx = [0,0,-1,1]
    dy = [-1,1,0,0]
    while q:
        x,y = q.popleft()
        if x==m-1 and y == n-1: return dist[x,y]
        for k in range(4):
            j = dx[k] + x
            i = dy[k] + y
            if i<n and i>=0 and j<m and j>=0 and mat[i][j]==0 and dist[j,i]==float('inf'):
                dist[j,i] = dist[x,y] + 1
                q.append((j,i))
    return -1
m = int(input())
n = int(input())
x1 = list(map(int,input().split()))
y1 = list(map(int,input().split()))
x2 = list(map(int,input().split()))
y2 = list(map(int,input().split()))
print(solve(n,m,x1,x2,y1,y2))
