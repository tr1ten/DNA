class Solution:
    def maximumInvitations(self, nxt: List[int]) -> int:
        n = len(nxt)
        prev =[ [] for i in range(n)]
        for  i in range(n):
            prev[nxt[i]].append(i)
        mxc = 0
        P = [False]*n
        for i in range(n):
            cur = i
            p = deque([cur])
            while(not P[nxt[cur]]):
                cur = nxt[cur]
                p.append(cur)
                P[cur] = True
            while(p and p[0]!=nxt[cur]): p.popleft()
            mxc = max(mxc,len(p))
        @cache
        def dfs(u):
            d = 0
            for v in prev[u]:
                if v==nxt[u]: continue
                d = max(d,dfs(v))
            return d+1
        pair = 0
        vis = set()
        for i in range(n):
            if i==nxt[nxt[i]] and nxt[i] not in vis and i not in vis:
                pair +=dfs(i)+dfs(nxt[i])
                vis.add(i)
                vis.add(nxt[i])
        return max(mxc,pair)
                