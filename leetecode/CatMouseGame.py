class Solution:
    def catMouseGame(self, g: List[List[int]]) -> int:
        n = len(g)
        dq = deque()
        dp = defaultdict(int) # store who will win 1-mouse, 2-cat
        for t in [1,2]: # start from known states
            for k in range(n):
                dp[(0,k,t)] = 1
                dq.append((0,k,t))
                dp[(k,k,t)] = 2
                dq.append((k,k,t))
        nxt_sc = [[[0]*n for m in range(n)] for t in range(3)] # next state count: outdegree, number of states possible from this state
        for t in range(1,3):
            for m in range(n):
                for c in range(1,n):
                    if(t==1): nxt_sc[t][m][c] = len(g[m]);
                    else: nxt_sc[t][m][c] = len(g[c]) - (0 in g[c]);
        def parents(m,c,t): # get prev state from given state
            res = []
            for v in g[m if t==2 else c]: # opposite turn, so if current turn is cat then prev should be mouse & viceversa
                if(t==1 and v==0): continue 
                if(t==1): res.append((m,v,2))
                if(t==2): res.append((v,c,1))
            return res
        while(dq):
            m,c,t = dq.popleft() # this is nxt state, of which we know the result dp
            r = dp[(m,c,t)]
            for m1,c1,t1 in parents(m,c,t): # prev state which we want to calculate
                if((m1,c1,t1) in dp): continue # if already calculated skip
                if(r==t1): # if nxt state is winning for this animate
                    dp[(m1,c1,t1)] = r
                    dq.append((m1,c1,t1))
                else:
                    nxt_sc[t1][m1][c1] -=1 # decreease the outdegree from next state to this state
                    if(nxt_sc[t1][m1][c1]==0): # if all next nodes are losing then no choice but to give up :(
                        dp[(m1,c1,t1)] = 3-t1
                        dq.append((m1,c1,t1))
                
                    
        return dp[(1,2,1)]