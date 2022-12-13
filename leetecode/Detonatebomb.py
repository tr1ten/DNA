class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        def dist(x, y):
            return math.sqrt(sum((px - py)**2  for px, py in zip(x,y)))
        n = len(bombs)
        adj = [[] for i in range(n)]
        for u in range(n):
            x1,y1,r1 = bombs[u]
            for v in range(u+1,n):
                x2,y2,r2 = bombs[v]
                d = dist((x1,y1),(x2,y2))
                if(d<=r1):
                    adj[u].append(v)
                if(d<=r2): adj[v].append(u)
                
        def dfs(u,visited):
            visited[u] = True
            res = 1
            for v in adj[u]:
                if(not visited[v]):
                    res +=dfs(v,visited)
            return res
        res = 0
        for i in range(n):
            res = max(res,dfs(i,[False]*n))
        return res