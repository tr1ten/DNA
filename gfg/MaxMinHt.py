#User function Template for python3
class Solution():
    def maximizeMinHeight(self, n, k, w, a):
        df = [0]*(n+w)
        df[0] = a[0]
        for j in range(1,n): df[j] = a[j]-a[j-1]
        def valid(x):
            dk = k
            diff = df[:]
            prev = 0
            for l in range(n):
                cur = prev+diff[l]
                if(cur<x):
                    e = x-cur
                    diff[l] += e
                    diff[l+w] -=e
                    dk -=e
                    cur = x
                    if(dk<0): return False
                prev = cur
            return True
                
        lo,hi = 0,10**10
        while(lo<hi):
            mid = (lo+hi)//2;
            if(valid(mid)): lo = mid+1
            else: hi = mid
        return lo-1


#{ 
 # Driver Code Starts
#Initial Template for Python 3
T = 1
for _ in range(T):
    n,k,w = map(int, input().split())
    arr = [int(i) for i in input().split()]
    print(Solution().maximizeMinHeight(n, k, w,arr))

# } Driver Code Ends