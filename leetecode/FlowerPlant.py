class Solution:
    def gardenNoAdj(self, n: int, paths: List[List[int]]) -> List[int]:
        adj = [[] for i in range(n)]
        res = [-1]*n
        N = 4
        for u,v in paths:
            adj[u-1].append(v-1)
            adj[v-1].append(u-1)
        def dfs(u):
            nonlocal res
            for v in adj[u]:
                if(res[v]!=-1): 
                    if(res[v]==res[u]): return False
                    continue
                for t in range(1,N+1):
                    if(res[u]==t): continue
                    res[v] = t
                    if(dfs(v)): break
                    res[v] = -1
                if(res[v]==-1): return False
            return True
        for u in range(n):
            if(res[u]==-1):
                for t in range(1,N+1):
                    res[u] = t
                    if(dfs(u)): break
                    res[u] = -1
        return res