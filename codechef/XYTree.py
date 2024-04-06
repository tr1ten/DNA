from queue import Queue
class Node:
    def __init__(self, key):
        self.key = key
        self.bit = 0
        self.parent = None
        self.left = None
        self.right = None
T = int(input())
for _ in range(T):
    N = int(input())
    root = Node(0);
    # N-1 edges
    adj = [[] for _ in range(N+1)]
    for _ in range(N-1):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)
    parent = [None]*(N+1) # parent of node o
    freq = [0]*(N+1) # total number of descendents
    def dfs(u,p):
        parent[u] = p;
        freq[p]+=1
        for v in adj[u]:
            if(v==p): continue
            dfs(v,u)
    dfs(1,0)
    good = N-1 # number of good edges, since all will have zero value
    Q = int(input())
    for _ in range(Q):
        ls = list(map(int, input().split()))
        t = ls[0]
        if(t==2):
            if(freq[1]==-1): print(N-1)
            else: print(good)
        else:
            u = ls[1]
            if(freq[u]==0):
                freq[parent[u]] -=1 
                freq[u] -=1
                good -=1
                
                