from collections import deque
class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        cells = list(map(tuple,cells))
        def check(days):
            water = set(cells[:(days)])
            dq = deque()
            for i in range(col):
                if((1,i+1) not in water): dq.append((0,i))
            while(dq):
                i,j = dq.popleft()
                if(i==row-1): return True
                for dy,dx in [(-1,0),(1,0),(0,1),(0,-1)]:
                    y,x = dy+i,dx+j
                    if(x>=0 and y>=0 and x<col and y<row and (y+1,x+1) not in water):
                        water.add((y+1,x+1))
                        dq.append((y,x))
            return False

        high = len(cells)
        low = 0
        while(low<high):
            mid = (low+high)//2;
            print("checling for ",high,low,mid)
            if(check(mid)):
                high = mid+1
            else:
                low = mid-1
        return high-1
    
    

class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        ds = DSU(row*col + 2) # two dummy nodes left, right border 
        for i in range(row): 
            ds.union(0,i*col + 1) # connect left node to all left border cell
            ds.union(row*col+1,i*col + col) # connect left node to all left border cell
        water = set()
        for days,(r,c) in enumerate(cells):
            water.add((r-1,c-1))
            for dy,dx in [(-1,0),(1,0),(0,1),(0,-1),(-1,-1),(1,-1),(-1,1),(1,1)]: # connect water from all 8 sides
                    y,x = dy+r-1,dx+c-1
                    if(x>=0 and y>=0 and x<col and y<row and (y,x) in water): # check if we can connect water cells
                        ds.union((r-1)*col+c -1 + 1,y*col + x+1)
            if(ds.find(0)==ds.find(row*col+1)): return days # if left border is connected to right via water cells then not possible
        return len(cells) # best case 
