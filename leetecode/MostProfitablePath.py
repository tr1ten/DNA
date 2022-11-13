from typing import List
class Solution:
    def mostProfitablePath(self, edges: List[List[int]], bob: int, amount: List[int]) -> int:
        n = edges.__len__()+1;
        INF = 10**9 +1;
        al = [[] for i in range(n)]
        for u,v in edges:
            al[u].append(v)
            al[v].append(u)
        reach_at = [INF]*n
        def dfs(u,t):
            if(u==0): return True
            for v in al[u]:
                if(reach_at[v]==INF):
                    reach_at[v] = t+1
                    if(dfs(v,t+1)): return True
                    reach_at[v] = INF
            return False
        reach_at[bob] = 0
        dfs(bob,0)
        visited = [False]*(n)
        def ldfs(u,t):
            res=0;
            if(reach_at[u]==INF): res+= amount[u];
            else:
                if(reach_at[u]==t): res += amount[u]//2;
                elif(reach_at[u]>t): res+= amount[u];
            visited[u] = True
            tp = -INF
            leaf = True
            for v in al[u]:
                if(not visited[v]):
                    leaf = False
                    tp = max(tp,ldfs(v,t+1))
            return res if leaf else res+tp;
        return ldfs(0,0);
            
                
        
        

            
            