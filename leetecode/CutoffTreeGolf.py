import heapq
# A* algorithm
class Solution:
    def cutOffTree(self, forest: List[List[int]]) -> int:
        n,m = len(forest),len(forest[0])
        start = [0,0]
        forest.append([0]*m) # out of bound handle
        for i in range(n+1): forest[i].append(0)
        trees = [
            (forest[y][x],y,x)
            for y in range(n)
            for x in range(m)
            if(forest[y][x]>1)
        ]
        # check if connected or not
        dirs = list(zip([0,0,1,-1],[1,-1,0,0]))
        q = [start]
        visited = set()
        for y,x in q:
            if((y,x) in visited or not forest[y][x]): continue
            visited.add((y,x))
            q += ((y+dy,x+dx) for dy,dx in dirs)
        if(not all([(y,x) in visited for (_,y,x) in trees])): return -1

        # main problem
        def distance(sx,sy,tx,ty):
            cur,nxt = [(sy,sx)],[]
            md = abs(sx-tx)+abs(sy-ty)
            visited = set()
            detours = 0
            while(len(cur)+len(nxt)>0):
                if(not cur):
                    cur,nxt = nxt,[]
                    detours +=1
                y,x = cur.pop()
                if(y==ty and x==tx): return md+2*detours
                if((y,x) not in visited):
                    visited.add((y,x))
                    for ny,nx,closer in ((y+1,x,y<ty),(y-1,x,y>ty),(y,x+1,x<tx),(y,x-1,x>tx)):
                        if(forest[ny][nx]): (cur if closer else nxt).append((ny,nx))
        trees.sort()
        return sum([distance(sx,sy,tx,ty) for ((_,sy,sx),(_,ty,tx)) in zip([[0,0,0]]+trees,trees)]) 

        