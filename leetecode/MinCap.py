from sortedcontainers import SortedList
from typing import List
class Solution:
    def minimumFuelCost(self, rs: List[List[int]], st: int) -> int:
        n = len(rs)+1
        adj = [[] for i in range(n)]
        for r in rs:
            adj[r[0]].append(r[1]);
            adj[r[1]].append(r[0]);
        visited = [False]*n;
        res = 0;
        def dfs(u):
            nonlocal res
            visited[u] = True;
            ss = SortedList(key=lambda x:-x)
            for v in adj[u]:
                if(not visited[v]):
                    ss.update(dfs(v))
            if(st==1): res +=1;
            else:
                if(len(ss)==0): 
                    res+=1
                    ss.add(1)
                else:
                    x = ss.pop()
                    if(x<st):
                        ss.add(x+1)
                    else:
                        res +=1
                        ss.add(1)
            return ss
        for v in adj[0]:
            dfs(v)
        return res
m = Solution()
print(m.minimumFuelCost([[0,1],[0,2],[1,3],[1,4],[2,5],[2,6],[3,7],[3,8],[4,9],[4,10],[5,11],[5,12],[6,13],[6,14]], 2))
                