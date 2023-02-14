class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        sm = 0 # regular kadane algo
        mx = 0
        mxp = 0 # max prefix sum
        p = 0
        MOD = 10**9 + 7
        for x in arr: 
            p +=x
            mxp = max(mxp,p)
            sm = max(sm+x,x)
            mx = max(mx,sm)
        mxs = 0
        p = 0
        for x in reversed(arr):
            p +=x
            mxs = max(mxs,p)
        sm = sum(arr)
        if(k==1): return mx
        # if total sum is positive then we will use it max times possible 
        return (max(0,sm*k,sm*(k-1)+max(mxp,mxs),sm*(k-2)+mxp+mxs,mxp+mxs,mx))%MOD