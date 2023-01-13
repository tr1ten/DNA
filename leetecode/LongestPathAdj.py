class Solution:
    def longestPath(self, parent: List[int], s: str) -> int:
        adj = [[] for i in range(len(parent))];
        for  v,u in enumerate(parent):
            if(u==-1): continue
            adj[u].append(v)
            adj[v].append(u)
        def solve(u,p):
            lf = 0
            rf = 0
            sf  = 0
            for v in adj[u]:
                if(v==p): continue
                if(s[v]==s[u]): sf = max(sf,solve(v,u))
                else: 
                    t=solve(v,u)
                    if(t>lf): lf,rf = t,lf
                    elif(lf>=t>rf): rf = t
            return max(lf+rf+1,sf)
        return solve(0,-1);