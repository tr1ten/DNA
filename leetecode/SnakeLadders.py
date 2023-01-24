import collections
from queue import Queue
class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        def posToXY(p):
            y = p//n;
            x = p%n;
            if(y%2==1):
                x = n-x-1
            return (x,n-y-1);

        q = collections.deque() # queue doesn't work for some reason
        q.append((0,0))
        visited = [False]*(n*n)
        visited[0] = True
        while(q):
            curr,step = q.popleft()
            x,y = posToXY(curr)
            if(board[y][x]!=-1):
                curr = board[y][x]-1
            if(curr==(n*n-1)):
                return step
            for nxt in range(curr + 1, min(curr + 6, n*n-1)+1):
                if(visited[nxt]): continue
                visited[nxt] = True
                q.append((nxt,step+1))
        return -1

                
