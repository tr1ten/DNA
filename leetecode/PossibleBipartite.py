class Solution:
    def possibleBipartition(self, n: int, eds: List[List[int]]) -> bool:
        adj = [[] for i in range(n)]
        for u,v in eds:
            adj[u-1].append(v-1);
            adj[v-1].append(u-1);
        visited = [0]*n
        def dfs(u,clr):
            print(u,clr)
            if(visited[u]!=0):
                if(clr==visited[u]): return True
                else: return False
            visited[u] = clr
            for v in adj[u]:
                if(not dfs(v,-1*clr)): return False
            return True
        for u in range(n):
            if(visited[u]==0 and not dfs(u,1)):
                return False
        return True