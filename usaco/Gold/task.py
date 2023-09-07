from collections import Counter
def solve(A,k):
    def ok(x):
        tk = 1
        mx = 0
        i = 0
        for j in range(len(A)):
            if max(mx,A[j])*(j-i+1) > x:
                mx = 0
                tk +=1
                i = j
            mx = max(mx,A[j])
        return tk<=k
        
    lo,hi = 0,10**10
    ans = 0
    while lo <= hi:
        mid = (lo+hi)//2
        if ok(mid):
            hi = mid-1
            ans = mid
        else:
            lo = mid+1
    return ans
A = list(map(int,input().split()))
k = int(input())
print(solve(A,k))