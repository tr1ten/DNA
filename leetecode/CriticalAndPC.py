class Union:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n
    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa != pb:
            if self.rank[pa] >= self.rank[pb]:
                self.parent[pb] = pa
                if self.rank[pa] == self.rank[pb]:
                    self.rank[pa] += 1
            else:
                self.parent[pa] = pb
    def find(self, a):
        pa = self.parent[a]
        if pa != self.parent[pa]:
            self.parent[a] = self.find(pa)
        return self.parent[a]

class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        # Tarjan's algorithm based
        # https://chengzhaoxi.xyz/ff18e0b2.html
        # Thoughts:
        # 1. if all edges have distinct weights, there's only ONE possible MST;
        # 2. In each step of Kruskal, the graph has been already partially connected in the last step, by the edges with smaller weight;
        # 3. By Thought 2., Kruskal is generating new graphs in each step, with min-weighted edges so far (eventually this graph will become a MST).
        # Therefore, in current step, if an edge is connecting two nodes that have been connected previously already, then this edge MUST NOT be critical or pseudo-critical;
        # alternatively, if it connects two nodes that are not connected yet, this edge then MUST be either critical or pseudo-critical.
        # To check whether this edge is critical or pseudo-critical, use Tarjan to see if it's a bridge in the graph that has been generated by Kruskal so far. If it's a bridge, it's critical; if not, it's pseudo-critical.
        dsu = Union(n)
        curAdjs, levels, lows, curLevel = dict(), list(), list(), [0]
        ans = [[], []]
        mark = [-1] * len(edges)

        def tarjan(cur, prev):
            levels[cur], lows[cur], curLevel[0] = curLevel[0], curLevel[0], curLevel[0] + 1
            for (ind, c) in curAdjs[cur]:
                dsu.union(cur, c)
                if levels[c] == -1:
                    tarjan(c, ind)
                    lows[cur] = min(lows[cur], lows[c])
                    if lows[c] > levels[cur]:
                        mark[ind] = 0
                    else:
                        mark[ind] = 1
                elif ind != prev:
                    lows[cur] = min(lows[cur], levels[c])
                    mark[ind] = 1

        myEdges = defaultdict(list)
        for i in range(len(edges)):
            myEdges[edges[i][2]].append((i, edges[i][0], edges[i][1]))
        weights = sorted(myEdges.keys())
        # Kruskal: starting from the minimum edge weight
        for w in weights:
            curAdjs = defaultdict(list)
            levels, lows, curLevel[0] = [-1] * n, [-1] * n, 0
            for (ind, a, b) in myEdges[w]:
                # at current step, previously connected nodes are regarded as one node, represented by their parent node
                pa, pb = dsu.find(a), dsu.find(b)
                if pa != pb:
                    curAdjs[pa].append((ind, pb))
                    curAdjs[pb].append((ind, pa))
            # Tarjan
            for cur in curAdjs.keys():
                if levels[cur] == -1:
                    tarjan(cur, -1)

        for i in range(len(edges)):
            if mark[i] != -1:
                ans[mark[i]].append(i)
        return ans