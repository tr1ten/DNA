class Solution:
    def countRectangles(self, rts: List[List[int]], points: List[List[int]]) -> List[int]:
        MXY = 102
        m = [[] for i in range(MXY)]
        for i in range(len(points)):
            x,y = points[i]
            m[y].append((x,i))
        res = [0]*len(points)
        rts.sort()
        cnts = [0]*MXY
        mem = [None]*(len(rts)) # no of rects having ht higher than h
        for i in reversed(range(len(rts))):
            l,h = rts[i]
            for y in range(1,h+1):
                cnts[y] +=1
            mem[i] = tuple(cnts)

        for y in range(1,MXY):
            if(not m[y]): continue
            m[y].sort()
            j = 0
            for k in range(len(rts)):
                l,h = rts[k]
                if(y>h or j==len(m[y])): continue
                if(m[y][j][0]<=l):
                    res[m[y][j][1]] += mem[k][y]
                    j +=1
        return res
                
        