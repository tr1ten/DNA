class Solution:
    def findAllRecipes(self, ver: List[str], ind: List[List[str]], sup: List[str]) -> List[str]:
        mem = dict()
        sup = set(sup)
        adj = {ver[i]:ind[i] for i in range(len(ver))}
        def dfs(u,path)->bool:
            if(u in path):
                return False
            if(u in sup): return True
            elif(u not in adj): return False
            path.add(u);
            for v in adj[u]:
                if(v in mem and not mem[v]): return False
                if(not dfs(v,path)):
                    mem[u] = False
                    return False
            path.remove(u)
            mem[u] = True
            return True
        res = []
        for v in adj:
            if(v in mem):
                if(mem[v]): res.append(v)
            else:
                if(dfs(v,set())): res.append(v) 
        return res

        