from collections import defaultdict
def solve(A):
    prs = []
    for i in range(0,len(A)-1,2):
        prs.append((A[i],A[i+1]))
    dp = defaultdict(int) # max len of domino ending with x
    for x,y in prs:
        dp[y] = max(dp[y],dp[x]+1)
    return len(prs) - max(dp.values())


A = list(map(int,input().split()))
print(solve(A))