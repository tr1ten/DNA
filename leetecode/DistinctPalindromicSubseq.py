class Solution:
    def countPalindromicSubsequences(self, s: str) -> int:
        mod = 10**9 + 7
        @cache
        def dp(i,j,k):
            if(i>j): return 0
            if(i==j): return s[i]== chr(k+ord('a'))
            if(s[i]!=chr(k+ord('a')) or chr(k+ord('a'))!=s[j]): return (dp(i,j-1,k) + dp(i+1,j,k) - dp(i+1,j-1,k))%mod
            return 2+ (sum([dp(i+1,j-1,x) for x in range(4)]))%mod
        return sum([dp(0,len(s)-1,x) for x in range(4)])%mod