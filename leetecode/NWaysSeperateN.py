def zfunc(s:str):
    l,r = 0,0
    z = [0]*len(s)
    for i in range(1,len(s)):
        if(i<=r): z[i] = min(r-i+1,z[i-l]) # jump start by using past knowledge
        while(i+z[i]<len(s) and s[z[i]]==s[i+z[i]]): 
            z[i] +=1 # try bigger length
        if(i+z[i]-1>r): # increase the range 
            l = i
            r = l+z[i]-1
    return z
class Solution:
    def numberOfCombinations(self, num: str) -> int:
        dp = [[0]*(len(num) +1) for i in range(len(num))] # dp[i][sz]: starting at i and atleast of sz length
        mod = 10**9 + 7
        dp.append([1]*(len(num) + 1) )
        # optimize pre compute z for each suffix
        ps = []
        for i in range(len(num)): ps.append(zfunc(num[i:]))

        for i in range(len(num)-1,-1,-1):
            if(num[i]=='0'): continue
            for j in reversed(range(1,1+len(num))):
                if(i+j>len(num)): continue
                if i+j==len(num) or (i+2*j <=len(num) and (ps[i][j]==j or num[ps[i][j]]<=num[i+j+ps[i][j]] ) ):
                    dp[i][j] +=dp[i+j][j]
                elif j+1<=len(num): dp[i][j] +=dp[i+j][j+1]
                if(j+1<=len(num)): dp[i][j] +=dp[i][j+1]
                dp[i][j]%=mod
        # print(dp)
        return dp[0][1]
                
