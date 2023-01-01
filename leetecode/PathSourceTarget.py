class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        n = len(graph)
        res = []
        def dfs(u,path):
            path.append(u)
            if(u==n-1):
                res.append(tuple(path))
                path.pop()
                return;
            for v in graph[u]:
                dfs(v,path)
            path.pop()
        
        dfs(0,[])
        return res