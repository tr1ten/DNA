def solve(A):
    dp = [1]*len(A)
    for i in range(len(A)):
        for j in range(i+1,len(A)):
            if A[j]==3*A[i]:
                dp[j] = max(dp[j],dp[i]+1)
    return max(dp)

n = int(input())
A = list(map(int,input().split()))
print(solve(A))