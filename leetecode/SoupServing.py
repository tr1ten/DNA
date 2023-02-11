class Solution:
    def soupServings(self, n: int) -> float:
        @cache
        def f(a,b):
            if(a<=0 and b>0): return 1
            if(b<=0): return 0
            res = 0
            res += 0.25*f(max(0,a-100),b)
            res += 0.25*f(max(0,a-75),max(b-25,0))
            res += 0.25*f(max(0,a-50),max(b-50,0))
            res += 0.25*f(max(0,a-25),max(b-75,0))
            return res
        return f(n,n)
            