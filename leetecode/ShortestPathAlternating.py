from collections import deque
class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        # create adjacency list
        adj = [{-1:[],1:[]} for i in range(n)]
        for u,v in redEdges:
            adj[u][-1].append(v)
        for u,v in blueEdges:
            adj[u][1].append(v)
        dq = deque() # simple bfs
        dq.append((0,0,-1)) # (node,step,color)
        dq.append((0,0,1))
        d = [float('inf')]*n
        d[0] = 0
        while(dq):
            node,step,color = dq.popleft()
            while adj[node][-color]:
                child = adj[node][-color].pop() # destroy the edges (Or bridges) to avoid loops due to parallel or self edges
                if(d[child]>step+1): d[child] = step+1
                dq.append((child,step+1,-color))
        
        return [-1 if x==float('inf') else x for x in d]
        