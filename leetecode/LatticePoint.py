class Solution:
    def countLatticePoints(self, circles: List[List[int]]) -> int:
        ivals = [[] for x in range(201)]
        for cx,cy,cr in circles:
                for k in range(-cr,cr+1):
                    d = math.floor(math.sqrt(cr*cr - k*k)) # lil bit of geometry
                    ivals[cx+k].append((cy-d,cy+d)) # add the y interval 
        res = 0
        for x in ivals:
            x.sort() # common merge subroutine
            last = -1 
            for ival in x:
                if(ival[1]<=last): continue # will not contribute to ans
                res +=(ival[1]-max(ival[0],last+1) + 1)
                last = max(ival[1],last)
        return res
                    
        