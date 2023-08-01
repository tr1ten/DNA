def solve(A,B,S):
    n = len(A)
    if n>S: return False
    colors = [-1]*n
    adj = [[] for i in range(S)]
    for i in range(n):
        adj[A[i]-1].append(i)
        adj[B[i]-1].append(i)
    def rec(u,color):
        if colors[u]!=-1: return colors[u] == color
        colors[u] = color
        for v in adj[color]:
            if v == u: continue
            if not rec(v,(B[v] if A[v]==color+1 else A[v]) - 1): 
                colors[u] = -1
                return False
        return True
    for i in range(n):
        if colors[i]!=-1: continue
        if rec(i,A[i]-1): continue
        if rec(i,B[i]-1): continue
        return False
    return True
            
A = list(map(int,input().split()))
B = list(map(int,input().split()))
S = int(input())
print(solve(A,B,S))