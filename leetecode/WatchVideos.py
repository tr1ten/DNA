class Solution:
    def watchedVideosByFriends(self, W: List[List[str]], F: List[List[int]], id: int, level: int) -> List[str]:
        d = [float('inf')]*len(F)
        q = deque()
        q.append(id)
        d[0] = 0
        while(q):
            u = q.popleft()
            for v in F[u]:
                if(d[v]>d[u]+1):
                    q.append(v)
                    d[v] = d[u] + 1
        cnt = Counter()
        for i,x in enumerate(d):
            if(x==level): cnt += Counter(W[i])
        res = sorted([(y,x) for x,y in cnt.items()])
        return map(lambda x:x[1],res)