import math
n = 1000
dp = [0]*n
for i in range(1,n):
    for j in range(1,int(math.sqrt(i))+1):
        dp[i] |= not dp[i-j*j]
        if(dp[i]): break
i = 0
while(i<n):
    j = i
    cnt = 0
    while(j<n and dp[i]==dp[j]):
        cnt +=1
        j+=1
    print(cnt,end='  ')
    i = j