from queue import Queue
class Solution:
    def magnificentSets(self, n: int, edges: List[List[int]]) -> int:
        adj = [[] for i in range(n)]
        for u,v in edges:
            adj[u-1].append(v-1)
            adj[v-1].append(u-1)
        visited = [False]*n
        def dfs(u):
            q = Queue(maxsize=n)
            visited[u] =True
            q.put(u)
            l = 0
            while(not q.empty()):
                l +=1
                sz = q.qsize()
                vis = [False]*n
                for i in range(sz):
                    ui = q.get()
                    vis[ui]= True
                    for vi in adj[ui]:
                        if(vis[vi]): return -1
                        if(not visited[vi]):
                            visited[vi] = True
                            q.put(vi)
            return l;
        res = 0
        for i in range(n):
            if(not visited[i]):
                k =dfs(i)
                if(k<0): return -1
                res +=k
            
        return res

