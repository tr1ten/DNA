class Solution:
    def ways(self, pizza: List[str], k: int) -> int:
        n,m = len(pizza),len(pizza[0])
        mod = 10**9 + 7
        pref = [[0]*(m+1) for i in range(n+1)]
        for i in range(n-1,-1,-1):
            for j in range(m-1,-1,-1):
                pref[i][j] = pref[i+1][j]+pref[i][j+1]+(pizza[i][j]=='A')-pref[i+1][j+1]
        @cache
        def get(i1,i2,j1,j2): # get prefix sum of rect
            area = pref[i1][j1]+pref[i2+1][j2+1]-pref[i1][j2+1]-pref[i2+1][j1];
            return area
        @cache
        def f(i1,j1,p):
            if(p==k-1): return 1
            res= 0 
            i2,j2 = n-1,m-1
            for i in range(i1,i2):
                if(get(i1,i,j1,j2)>0 and get(i+1,i2,j1,j2)>0):
                    res += f(i+1,j1,p+1)
                    res %=mod
            for j in range(j1,j2):
                if(get(i1,i2,j1,j)>0 and get(i1,i2,j+1,j2)>0 ):
                    res += f(i1,j+1,p+1)
                    res %=mod
            return res
        return f(0,0,0)