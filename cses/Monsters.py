import sys
from collections import deque

# input
t = 1
# solve here
def bfs(starts,grid):
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
            if 0<=nx<M and 0<=ny<N and grid[ny][nx] == '.' and dist[ny][nx] > dist[y][x]+1:
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
    dist = bfs(a_start,grid)
    print(dist)
    