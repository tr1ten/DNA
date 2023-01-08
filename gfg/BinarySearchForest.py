class Solution:
    def find_height(self,tree,n,k):
        def ok(x):
            return sum([max(0,h-x) for h in tree])-k
        h = 1000
        l = 0
        while(l<=h):
            mid = (l+h)//2
            d = ok(mid)
            if(d==0): return mid
            if(d>0): 
                l = mid+1
            else:
                h = mid-1
        return -1