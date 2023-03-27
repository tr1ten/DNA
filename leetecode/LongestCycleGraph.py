# Simple version of cses planet
class Solution:
    def longestCycle(self, nxt: List[int]) -> int:
        res = -1
        n = len(nxt)
        status = [False]*n
        for u in range(n):
            cur = u
            path = [cur]
            while(nxt[cur]!=-1 and not status[nxt[cur]]):
                status[cur] = True # mark as dirty
                cur = nxt[cur]
                path.append(cur)
            isCycle = False
            cl = 0
            for v in path:
                isCycle |=(nxt[cur]==v)
                if(isCycle): cl +=1
            if(isCycle): res = max(res,cl)
        return res