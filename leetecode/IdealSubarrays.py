class Solution:
    def idealArrays(self, n: int, m: int) -> int:
        MOD = (10**9)+7
        divs = [set() for i in range(m+1)] # all divisors less than given number
        for x in range(1,m+1):
            for k in range(2,int(sqrt(x))+1):
                if(x%k==0):
                    y = x//k;
                    divs[x].add(k)
                    divs[x].add(y)
            if(x!=1): divs[x].add(1)
        # Find ways to build n length strictly increasing array using given condition
        MAXN = min(n,14) # 1 2 4 ... 2^14 
        dp = [[0]*(m+1) for i in range(MAXN+1)] # strictly increasing array of divisors
        for r in range(1,m+1): dp[1][r] = 1 
        dp[1][0] = sum(dp[1])%MOD # dp[l][end]: ways to build array having end digit of length l
        for k in range(2,MAXN+1):
            for r in range(1,m+1):
                for div in divs[r]:
                    dp[k][r] += dp[k-1][div] # sum of all its divisors ways of smaller length
                    dp[k][r] %= MOD
            dp[k][0] = sum(dp[k])%MOD # total possible arrays of length k
        # Coming to actual question, building array from strictly inc array using stars and bars concept
        res = 0 
        for kinds in range(1,MAXN+1): 
            res += dp[kinds][0]*math.comb(n-1,kinds-1) # atleast one from all available kinds, so n+k-1 reduces to n-1
            res %= MOD
        return res