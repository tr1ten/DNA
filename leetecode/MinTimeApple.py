class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        adj = [[] for i in range(n)]
        for u,v in edges:
            adj[u].append(v);
            adj[v].append(u);
        
        def solve(u,p):
            res = 0
            for v in adj[u]:
                if(v==p): continue
                res += solve(v,u)
            if(not (res or hasApple[u])): return 0
            return res+2  if(u!=0) else res
        return solve(0,-1)