def makeTheIntegerZero(n1, n2):
        if n1<=n2: return -1
        ans = -1
        def ok(x):
            return n1-x*n2>0 and (n1-x*n2).bit_count()<=x<=n1-x*n2
        res= -1
        for x in range(64,0,-1):
            if ok(x):
                res = x
        return res
a,b = list(map(int,input().split()))
print(makeTheIntegerZero(a,b));