class Solution:
    def palindromePartition(self, s: str, K: int) -> int:
        n = len(s)
        MAX = 101
        def cost(i,j):
            res = 0
            while(i<j):
                if(s[i]!=s[j]):
                    res +=1
                i +=1
                j -=1
            return res
        @cache
        def solve(idx,k):
            if(n-idx<k): return  MAX;
            if(k==0): return cost(idx,n-1)
            mn = MAX
            for j in range(idx,n-k):
                mn = min(mn,cost(idx,j)+solve(j+1,k-1))
            return mn
        return solve(0,K-1)
                