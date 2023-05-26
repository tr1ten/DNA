from functools import lru_cache


class Solution:
    def countDivisibleSubseq(self, s, N):
        @lru_cache(None)
        def dp(i, m):
            if i == len(s):
                return 0
            r = (m*10 + int(s[i])) % N
            res = (r == 0) + dp(i, r) + dp(i, m)
            print(res, i, m)
            return res
        return dp(0, 0)
    
s = Solution()

print(s.countDivisibleSubseq("1234",4))