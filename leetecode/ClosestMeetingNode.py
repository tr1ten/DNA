from queue import Queue
class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        n = len(edges)
        def dfs(s):
            dist = [float('inf')]*n
            cur = s
            d = 0
            while(cur>=0):
                if(dist[cur]<d): break
                dist[cur] = d
                d+=1
                cur = edges[cur]
            return dist
        mn = float('inf')
        ind = -1
        for i,arr in enumerate(zip(dfs(node1),dfs(node2))):
            if(max(arr)<mn):
                ind = i
                mn = max(arr)
        return ind

            