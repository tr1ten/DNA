import heapq
# A* Algorithm similar to bfs 
# optimality depend on heuristic choosen
class Solution:
    def shortestPathBinaryMatrix(self, A: List[List[int]]) -> int:
        if A[0][0]!=0: return -1
        dq = []
        n = len(A)
        def heur(x,y):
            return max(abs(n-x) , abs(n-y))
        dist = defaultdict(lambda :float('inf'))
        dq.append((1+heur(0,0),0,0))
        dist[(0,0)] = 1
        adj = (-1,1,0)
        while(dq):
            c,u,v = heapq.heappop(dq)
            if u==n-1 and v==n-1: return dist[u,v]
            for dx in adj:
                if dx+u<0 or dx+u>=n: continue
                for dy in adj:
                    x,y = u+dx,v+dy
                    if y<0 or y>=n: continue
                    if not A[y][x] and dist[(x,y)]>dist[u,v]+1:
                        dist[(x,y)] = dist[u,v]+1
                        heapq.heappush(dq,(dist[(x,y)] + heur(x,y),x,y))
        return -1
        