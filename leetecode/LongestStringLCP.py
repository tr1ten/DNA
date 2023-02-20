class Solution:
    def findTheString(self, lcp: List[List[int]]) -> str:
        n = len(lcp)
        s = ["a"]*(n)
        last = ord('b') # greedily build the string, starting from smallest alphabet
        for i in range(1,n):
            flag = False
            for j in range(0,i):
                if(lcp[i][j]>0):
                    flag = True
                    s[i] = s[j]
                    break
            if(not flag): 
                s[i] = chr(last)
                if(last>ord('z')): return ""
                last +=1
        dp = [[0]*(n+1) for i in range(n+1)] # verify the ans
        for i in range(n-1,-1,-1):
            for j in range(n-1,-1,-1):
                if(s[i]==s[j]): dp[i][j] = dp[i+1][j+1]+1
        for i in range(n):
            for j in range(n):
                if(dp[i][j]!=lcp[i][j]): return ""
        return "".join(s)