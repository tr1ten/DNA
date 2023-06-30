t = int(input())
for _ in range(t):
    s = input()
    A = 26
    cost = [[0]*A for i in range(A)]
    for i in range(A):
        cost[i] = list(map(int,input().split()))
    dp = [[float('inf')]*A for i in range(len(s))]
    par = [[j for j in range(A)] for i in range(len(s))]
    
    for i in range(A):
        dp[0][i] = cost[ord(s[0]) - ord('a')][i]
    for i in range(len(s)-1):
        for j in range(A):
            for k in range(j,A):
                val = dp[i][j] + cost[ord(s[i+1]) - ord('a')][k]
                if dp[i+1][k]>val:
                    dp[i+1][k] = val
                    par[i+1][k] = j
    
    mn = 0;
    for x in range(A):
        if dp[-1][x]<dp[-1][mn]:
            mn = x
    res = ""
    p = mn
    for x in range(len(s)-1,-1,-1):
        res += chr(p+ord('a'))
        p = par[x][p]
    print(min(dp[-1]),res[::-1])