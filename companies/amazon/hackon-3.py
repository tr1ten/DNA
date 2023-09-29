def solve(A,t):
    def ok(x):
        cur = 0
        m = 1
        for k in A:
            if k>x: return False
            if cur+k>x:
                cur = 0
                m +=1
            cur +=k
        return m<=t
    ans = 0
    lo,hi = 1,10**5
    while lo<hi:
        mid = (lo+hi)//2
        if ok(mid):
            hi = mid-1
            ans = mid
        else:
            lo = mid+1
    return ans

n,t = map(int,input().split())
A = list(map(int,input().split()))
print(solve(A,t))