import sys

def solve(s):
    dp = [0]*(len(s)+1)
    dp[-1] = 1
    if(s[-1]!='0'): dp[len(s)-1] = 1
    for i in reversed(range(0,len(s)-1)):
        if(s[i]=='0'): continue
        dp[i] = (dp[i+1])+(dp[i+2] if(s[i]<'2' or (s[i+1]<='6' and s[i]=='2')) else 0)
    return dp[0]
# input
while(True):
    s = sys.stdin.readline().strip()
    if(s[0]=='0'): break
    print(solve(s))