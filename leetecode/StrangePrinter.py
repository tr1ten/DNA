from typing import List
class Solution:
    def isPrintable(self, tg: List[List[int]]) -> bool:
        n = len(tg);
        m = len(tg[0]);
        cr = dict()
        for i in range(n):
            for j in range(m):
                c = tg[i][j];
                if(c not in cr):
                    cr[c] = [[i,j],[i,j]] # start y,x and end y,x
                else:
                    cr[c][0][0] = min(i,cr[c][0][0])
                    cr[c][0][1] = min(j,cr[c][0][1])
                    cr[c][1][0] = max(i,cr[c][1][0])
                    cr[c][1][1] = max(j,cr[c][1][1])
        colors = {c:i for i,c in enumerate(cr.keys())};
        adj = [[False]*len(colors) for i in range(len(colors))]
        for c in colors:
            u = colors[c]
            for i in range(cr[c][0][0],cr[c][1][0]+1):
                for j in range(cr[c][0][1],cr[c][1][1]+1):
                    v = colors[tg[i][j]]
                    if(u!=v):
                        adj[u][v] = True;
        
        visited = 0
        hasCycle = False
        target = (1<<len(colors))-1
        def dfs(u,vis):
            nonlocal hasCycle, visited
            visited |= (1<<u)
            for v in range(len(colors)):
                if(adj[u][v]):
                    if((vis&(1<<v))>0):
                        hasCycle = True
                    if(not hasCycle and (visited&(1<<v))==0):
                        dfs(v,vis | (1<<v))
        for u in range(len(colors)):
            if((visited&(1<<u))==0):
                dfs(u,1<<u);
                if(hasCycle): return False
                if(visited==target): return True
        return False
        
            
            
    
def main():
    s = Solution()
    print(s.isPrintable([[1,1,1,1],[1,2,2,1],[1,2,2,1],[1,1,1,1]]))
    print(s.isPrintable([[1,2,1],[2,1,2],[1,2,1]]))
    print(s.isPrintable([[1,1,1],[3,1,3]]))
    print(s.isPrintable([[1,1,1,1],[1,1,3,3],[1,1,3,4],[5,5,1,4]]))

main()