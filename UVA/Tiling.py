N = 250 + 5
M = 4
dp = [[0]*M for _ in range(N)]
dp2 = [0 for _ in range(N)]

# driver code
dp[0][M-1] = 1
dp2[0] = 1;
for i in range(1, N):
    dp[i][3] = dp[i-1][0] + dp[i-1][3] + dp[i-1][0]
    dp[i][2] = dp[i-1][1]
    dp[i][1] = dp[i-1][2]
    dp[i][0] = dp[i-1][3]
    dp2[i] = dp2[i-1] + 2*dp2[i-2]

c = None
try:    
    while (1):
        n = int(input())
        print(dp[n][M-1])
except:
    pass