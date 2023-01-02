class Solution:
    def appealSum(self, s: str) -> int:
        dp = [0]*len(s)
        dp[0] = 1 # dp[i] - store total appeal of string ending at index i
        m = [-1]*26 # latest occurence of character
        m[ord(s[0])-ord('a')] = 0
        for i in range(1,len(s)):
            dp[i] = dp[i-1] + (i-m[ord(s[i])-ord('a')]) # last + value increased due to this character - extra added value due to duplicate character
            m[ord(s[i])-ord('a')] = i
        return sum(dp)