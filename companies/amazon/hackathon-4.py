def solve(S,K):
    mem = dict()
    def dp(idx,cur,state):
        key = (idx,cur,state)
        if key in mem: return mem[key]
        if cur>K: return 0
        if idx==S: return 1
        res = dp(idx+1,cur+1,state)
        if state+1<4: res += dp(idx,0,state+1)
        mem[key] = res
        return res
    return dp(0,0,1)

S,K = map(int,input().split())
print(solve(S,K))