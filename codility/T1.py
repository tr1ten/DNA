def solve(A):
    A.sort()
    def ok(x):
        last = 0
        cnt = 0
        for i in range(len(A)):
            if A[i]-A[last]>x:
                last = i
                cnt +=1
        return cnt<=2
    lo=0
    hi = 10**10
    ans = hi
    while lo<=hi:
        mid = (lo+hi)//2
        if ok(mid):
            hi = mid-1
            ans = mid
        else: lo = mid+1
    return ans        


A = list(map(int,input().split()))
print(solve(A))