class Solution:
    def findWords(self, board, words):
        suffix = set()
        ws = set(words) # also include the reverse
        # for w in ws:
        #     suffix.update({w[i:] for i in range(0,len(words))});
        mem = dict()
        n = len(board)
        # this will return all the suffixes that start from board(x,y)
        def dfs(x,y,prev):
            if(x<0 or y<0 or x>=n or y>=n):
                return [""]
            if((x,y) in mem): return mem[(x,y)]
            adj = [[0,1],[1,0],[-1,0],[0,-1]]
            res = []
            for i,j in adj:
                if(prev[0]==x+i and prev[1]==y+j): continue
                p = dfs(x+i,j+y,(x,y))
                for s in p:
                    pass
                    # if((board[x][y]+s) in suffix):
                    #     res.append(board[x][y]+s)
            mem[(x,y)] = res
            return res
        return dfs(0,0,(-1,-1))
