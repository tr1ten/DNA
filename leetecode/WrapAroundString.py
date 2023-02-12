from collections import defaultdict
class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        i=0
        res = 0
        p = "$"+p
        dp = defaultdict(int)
        for j in range(1,len(p)):
            if((ord(p[j])-ord(p[j-1]))%26!=1): i = j
            dp[p[j]] = max(dp[p[j]],j-i+1)
            
        return sum(dp.values())
                