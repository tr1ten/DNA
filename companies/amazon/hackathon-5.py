import bisect
from collections import *
from itertools import accumulate
def solve2(arr):
    presum=[0]
    for i in arr: presum+=[presum[-1]+i]   

    n, dp, prev, cur = len(arr)-1, Counter(), Counter(),0
    for i in range(n):
        i+=1

        cur=max(cur,prev[i])

        dp[i]=(i-cur-1) + dp[cur]

        idx=bisect.bisect_left(presum,2*presum[i]-presum[cur])   

        prev[idx]=i

    return n-dp[n]
def solve(A):
    n = len(A)
    dp = [0]*(n+1)
    merge = [float('inf')]*(n+1)
    pre = [float('inf')]*(n+1)
    eve = list(range(n+1))
    merge[0] = 0;
    pre[0] = 0;
    for i in range(1,n+1):
        pre[i] = A[i-1]+pre[i-1]
        idx = bisect.bisect_right(eve,pre[i],key=lambda j:merge[j]+pre[j])-1
        merge[i] = pre[i]-pre[idx]
        dp[i]=dp[idx]+1
    return dp[-1]

    
n = int(input())
A = list(map(int,input().split()))
print(solve(A))

