from collections import defaultdict
# just euler circuit
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        adj = defaultdict(list)
        for fr,to in tickets:
            adj[fr].append(to)
        for k in adj: adj[k].sort(reverse=True)
        start = "JFK"
        res = []
        def dfs(u):
            while(len(adj[u])>0):
                v = adj[u].pop()
                dfs(v)
                res.append(v)
        dfs(start)
        res.append(start)
        return res[::-1]
            
            