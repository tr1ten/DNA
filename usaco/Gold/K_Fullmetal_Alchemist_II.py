n = int(input())
words = []
def code(x): return ord(x) - ord('a') + 1

for i in range(n):
    words.append(input())
adj = [[0]*n for i in range(n)]
import random
M = 2**61 - 1
B = 9973
total = 0
for i in range(n):
    total += len(words[i])
    for j in range(n):
        if i==j: continue
        p1 = -1+len(words[i])
        p2 = 0
        sz= 0
        pref = 0
        suff = 0 
        pp = 1
        mx = 0
        while p1-sz>=0 and p2+sz<len(words[j]): 
            pref = ((pref*B)%M + code(words[i][p1-sz]))%M
            suff = (suff + (code(words[j][p2+sz])*pp)%M)%M
            pp = (pp*B)%M
            sz+=1
            if pref==suff: mx = sz
        # print(words[i],words[j],mx)
        adj[i][j] = mx
dp = [[0]*n for i in range(1<<n)]
for state in range(1<<n):
    for last in range(n):
        if state&(1<<last)==0: continue
        for nxt in range(n):
            if (state)&(1<<nxt)!=0: continue
            ns = state|(1<<nxt)
            dp[ns][nxt] = max(dp[ns][nxt], dp[state][last] + adj[last][nxt]);
print(total-max(dp[-1]))
        