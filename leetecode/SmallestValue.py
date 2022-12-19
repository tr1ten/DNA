import math
class Solution:
    def smallestValue(self, n: int) -> int:
        maxN = n+1
        spf = [i for i in range(maxN)]
        spf[1] = 0
        def sieve():
            spf[1] = 1
            for i in range(4, maxN, 2):
                spf[i] = 2
            for i in range(3, math.ceil(math.sqrt(maxN))):
                if (spf[i] == i):
                    
                    for j in range(i * i, maxN, i):
                        
                        if (spf[j] == j):
                            spf[j] = i

        def getFactorization(x):
            ret = list()
            while (x != 1):
                ret.append(spf[x])
                x = x // spf[x]

            return ret
        sieve()
        while(n>2 and spf[n]!=n):
            n = sum(getFactorization(n))
        return n
            

        
        