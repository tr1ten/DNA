from sortedcontainers import SortedSet
class Solution: 
    
    def orderOfLargestPlusSign(self, n: int, mines: List[List[int]]) -> int:
        def floor(cont, value):
            """Return smaller or equal value than the given value."""
            i = cont.bisect_right(value) - 1
            if i < 0:
                return -1
            return cont[i]

        def ceil(cont, value):
            """Return larger or equal value than the given value."""
            i = cont.bisect_left(value)
            if i >= len(cont):
                return n
            return cont[i]
        ys = [SortedSet() for i in range(n)]
        xs = [SortedSet() for i in range(n)]
        for x,y in mines:
            ys[y].add(x);
            xs[x].add(y)
        
        res = 0
        for y in range(n):
            for x in range(n):
                if(x in ys[y]): continue;
                li = max(floor(ys[y],x),-1)
                ri = min(ceil(ys[y],x),n)
                ui = max(floor(xs[x],y),-1)
                di = min(ceil(xs[x],y),n)
                print(y,x,li,ri,ui,di,(x-li,ri-x,y-ui,di-y))
                res = max(res,min(x-li,ri-x,y-ui,di-y))
        return res