import sys
from collections import deque

# input
t = 1
# solve here
def bfs(starts,grid):
    N,M = len(grid),len(grid[0])
    dist = [[float('inf')]*M for i in range(N)]
    move = [[""]*M for i in range(N)]
    q = deque()
    q.extend(starts)
    for y,x in starts: dist[y][x] = 0
    adj = [(1,0),(-1,0),(0,1),(0,-1)]
    dirs = ['R','L','D','U']
    while q:
        y,x = q.popleft()
        for dir,(dx,dy) in zip(dirs,adj):
            nx,ny = x+dx,y+dy
            if 0<=nx<M and 0<=ny<N and grid[ny][nx] == '.' and dist[ny][nx] > dist[y][x]+1:
                dist[ny][nx] = dist[y][x]+1
                move[ny][nx] = dir
                q.append((ny,nx))
    return dist,move
def bfs2(starts,grid):
    N,M = len(grid),len(grid[0])
    dist = [[float('inf')]*M for i in range(N)]
    q = deque()
    q.extend(starts)
    for y,x in starts: dist[y][x] = 0
    adj = [(1,0),(-1,0),(0,1),(0,-1)]
    while q:
        y,x = q.popleft()
        for dx,dy in adj:
            nx,ny = x+dx,y+dy
            if 0<=nx<M and 0<=ny<N and grid[ny][nx] != '#' and dist[ny][nx] > dist[y][x]+1:
                dist[ny][nx] = dist[y][x]+1
                q.append((ny,nx))
    return dist

# input processing
for _ in range(t):
    N,M = map(int, input().split())
    grid = []
    a_start = []
    m_start = []
    for i in range(N):
        grid.append(list(input()))
        for j in range(M):
            if grid[i][j] == 'A':
                a_start.append((i,j))
            if grid[i][j] == 'M':
                m_start.append((i,j))
    dist1,moves = bfs(a_start,grid)
    dist2 = bfs2(m_start,grid)
    flag = False
    cs = []
    for i in [0,-1]:
        for j in range(M):
            if(grid[i][j]!='#' and dist1[i][j]!=float('inf') and dist1[i][j]<dist2[i][j]):
                cs.append((i,j))
                flag = True
                break
    if(not flag): 
        for j in [0,-1]:
            for i in range(N):
                if(grid[i][j]!='#' and dist1[i][j]!=float('inf') and dist1[i][j]<dist2[i][j]):
                    cs.append((i,j))
                    flag = True
                    break
    if(not flag): print("NO")
    else:
        i,j = cs[0]
        print("YES")
        si,sj = a_start[0]
        dxy = {'L':(1,0),'R':(-1,0),'U':(0,1),'D':(0,-1)}
        print(dist1[i][j])
        if(dist1[i][j]==0): continue
        rm = ""
        while(moves[i][j]):
            m = moves[i][j]
            rm +=m
            dx,dy = dxy[m]
            i,j = i+dy,j+dx
        print(rm[::-1])
            
        
    
    
    from collections import deque
class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        dq = deque()
        dq.append((0,0,0)) # src,time
        visited = set()
        while(dq):
            y,x,t = dq.popleft()
            if(y==len(grid)-1 and x==len(grid[0])-1): return t
            for dx,dy in [(1,0),(-1,0),(0,1),(0,-1)]:
                i,j = dy+y,dx+x
                if( i>=len(grid) or i<0 or j<0 or j>=len(grid[0]) or (i,j) in visited or grid[i][j]>t+1): continue
                visited.add((i,j))
                dq.append((i,j,t+1))
                
        return -1
        
        