from typing import List
class Solution:
    def shortestPathLength(self, g: List[List[int]]) -> int:
        n = len(g)
        res = 2**31
        def array_match(a, b):
            for i in range(0, len(a)-len(b)+1):
                if a[i:i+len(b)] == b:
                    return i
            return None
        def dfs(u,vis,path):
            nonlocal res
            if(all(vis)):
                res = min(res,len(path))
                return;
            print(path)
            if(len(path)>=res): return;
            for v in g[u]:
                if(len(path)<3 or array_match(path,(u,v))==None):
                    vis[v] = True
                    dfs(v,vis,path+[v])
                    vis[v] = False
        for i in range(n):
            dfs(i,[False]*n,[i])
        return res

def main():
    s = Solution()
    print(s.shortestPathLength([[1,2,3],[0],[0],[0]]))

main()
        