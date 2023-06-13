import heapq
N,M,K = map(int,input().split())
adj = [[] for i in range(N)]
for i in range(M):
    u,v,c = map(int,input().split())
    adj[u-1].append((v-1,c))
    adj[v-1].append((u-1,c))
S = 0
dist = [[float('inf')]*(K+1) for i in range(N)]
for i in range(K+1): dist[S][i] = 0
dq = [(0,0,0)] # no skip
while(dq):
    cost,u,k = heapq.heappop(dq)
    if dist[u][k]<cost: continue
    for v,c in adj[u]:
        if dist[v][k]>dist[u][k] + c:
            dist[v][k] = dist[u][k]+c; # no skip
            heapq.heappush(dq,(dist[v][k],v,k))
        if k+1<=K and dist[v][k+1]>dist[u][k]: # skip
            dist[v][k+1] = dist[u][k];
            heapq.heappush(dq,(dist[v][k+1],v,k+1))
print(" ".join(map(lambda x:str(min(x)),dist))) # taking all skips might not always give optimal result so min