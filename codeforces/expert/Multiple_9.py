import sys

# input
t = int(sys.stdin.readline())
sys.setrecursionlimit(100000)
sys.set_int_max_str_digits(1000000)
def dp(idx,m,s,mem):
    if idx==len(s): return m==0
    if(mem[idx][m]!=-1): return mem[idx][m];
    if s[idx]!='?': return dp(idx+1,(m+int(s[idx]))%9,s,mem)
    res = 0
    for i in range(1 if idx==0 else 0,10):
        res += dp(idx+1,(m+i)%9,s,mem)
    mem[idx][m] =res;
    return res
# solve here
def solve():
    n = int(input())
    s = input()
    mem = [[-1 for i in range(10)] for i in range(len(s))]
    print(dp(0,0,s,mem))
    
# input processing
for _ in range(t):
    solve();