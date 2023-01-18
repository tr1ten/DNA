from queue import Queue
class Solution:
    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        adj = [[] for i in range(n)]
        S = 0
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
        d = [1]*n # number of child nodes including itself
        visited = [False]*n
        def dfs(u):
            visited[u] = True
            for v in adj[u]:
                if(not visited[v]):
                    d[u] +=dfs(v)
            
            return d[u]
        def bfs(s):
            q = Queue(maxsize=n)
            vis = [False]*n
            vis[s] = True
            q.put((s,0))
            res = 0
            while(not q.empty()):
                u,lev = q.get()
                for v in adj[u]:
                    if(not vis[v]):
                        vis[v]=True
                        res +=lev+1
                        q.put((v,lev+1))
            return res
        res = [None]*n # to store result
        res[0] = bfs(S) # only calculate total dist for single node
        dfs(S) # find number of childrens for each node
        def solve(u,p):
            res[u] = p-d[u]+(n-d[u])
            for v in adj[u]:
                if(not res[v]):
                    solve(v,res[u])
        for u in adj[S]:
            if(not res[u]):
                solve(u,res[S])
        return res
            
        