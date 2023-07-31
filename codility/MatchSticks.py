def sub(A,tar): # https://leetcode.com/problems/matchsticks-to-square/
    N  = 1<<len(A)
    pending = [0]*(N)
    dp = [0]*(N)
    for mask in range(N):
        for i in range(len(A)):
            if mask&(1<<i)==0 or dp[mask]>dp[mask^ (1<<i)]: continue
            sub = mask^ (1<<i)
            if pending[sub]+A[i]==tar:
                pending[mask] = 0
                dp[mask] = dp[sub]+1
            elif pending[sub]+A[i]<tar:
                pending[mask] = pending[sub] +A[i]
                dp[mask] = dp[sub]
    return dp[N-1]==4
def solve(A):
    n = len(A)
    sums = set()
    for mask in range(1<<n):
        sm = 0
        for i in range(n):
            if mask&(1<<i):
                sm +=1
        sums.add(sm)
    for sm in sorted(sums,reverse=1): # O(4^N) check for all possbile sums
        if sub(A,sm): return sm
    return 0;
A = list(map(int,input().split()))
print(solve(A))