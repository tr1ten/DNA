from functools import cache
def solve(s):
    op = [i for i in range(len(s)) if s[i]=='(']
    cl = [i for i in range(len(s)) if s[i]==')']
    @cache
    def rec(i,j):
        if i==len(op) or j==len(cl): return 0
        res = rec(i,j+1) # skip closing
        if op[i]<cl[j]: res = max(res,cl[j]-op[i] + rec(i+1,j+1))
        return res
    return rec(0,0)
for _ in range(1):
    s = input()
    print(solve(s))