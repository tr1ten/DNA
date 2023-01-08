class Solution:
    def minTime (self, arr, n, k):
        def ok(x):
            sm = 0
            t = k-1
            for m in arr:
                if(m>x): return False
                if(sm+m>x):
                    if(t==0): return False
                    t -=1
                    sm = m
                else:
                    sm +=m
            return True
        h = sum(arr)
        l = 1
        while(l<h):
            mid = (l+h)//2
            if(ok(mid)): h = mid
            else: l = mid+1
        return l    