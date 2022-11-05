class Solution:
    def findWords(self, board, words):
        suffix = set()
        ws = set(words) # also include the reverse
        rmap = {w[::-1]:w for w in words}
        rs = set(rmap.keys())
        for w in ws.union(rs):
            suffix.update({w[i:] for i in range(0,len(words))});
        mem = dict()
        n = len(board)
        f = set()
        # this will return all the suffixes that start from board(x,y)
        def dfs(x,y):
            if(x<0 or y<0 or x>=n or y>=n):
                return {""}
            if((x,y) in mem): return mem[(x,y)]
            adj = [[0,1],[1,0]]
            res = {""}
            for i,j in adj:
                # if(prev[0]==x+i and prev[1]==y+j): continue
                p = dfs(x+i,j+y)
                for s in p:
                    pass
                    ss = board[y][x]+s;
                    if((ss) in suffix):
                        if(ss in ws): 
                            f.add(ss)
                        elif(ss in rs):
                            f.add(rmap[ss])
                        res.add(board[y][x]+s)
            mem[(x,y)] = res
            return res
        dfs(0,0)
        print(mem)
        return list(f)

def main():
    s = Solution()
    print(s.findWords([["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]],["oath","pea","eat","rain"]))
    
if __name__ == "__main__":
    main()