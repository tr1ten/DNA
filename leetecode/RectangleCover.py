class Solution:
    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        # main idea
        # rectangle must consist of 4 corners with min top left and max bottom right
        # apart from main rect corner points, all other points must be repeated even times
        # area of all rectangles must be equal to area of main rectangle
        x2=y2 = float('-inf')
        x1=y1 = float('inf')
        s = set()
        area = 0
        for x,y,a,b in rectangles:
            x1 = min(x,x1)
            y1 = min(y,y1)
            x2 = max(x2,a)
            y2 = max(y2,b)
            area += (a-x)*(b-y)
            # create a set of all points in the rectangle
            bl = str(x) + " " + str(y)
            tl  = str(x) + " " + str(b)
            br = str(a) + " " + str(y)
            tr = str(a) + " " + str(b)
            if(bl in s): s.remove(bl)
            else: s.add(bl)
            if(tl in s): s.remove(tl)
            else: s.add(tl)
            if(tr in s): s.remove(tr)
            else: s.add(tr)
            if(br in s): s.remove(br)
            else: s.add(br)
        if((str(x1) + " " + str(y1) not in s) or (str(x2) + " " + str(y1) not in s) or (str(x1) + " " + str(y2) not in s) or (str(x2) + " " + str(y2) not in s) or len(s)!=4 ): return False
        return area == (x2-x1) * (y2-y1)
