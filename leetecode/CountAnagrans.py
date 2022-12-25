from collections import Counter
from functools import cache
class Solution:
    def countAnagrams(self, s: str) -> int:
        MOD = 10**9+7
        @cache
        def fact(n,m):
            if n == 0:
                return 1
            return (n * fact(n-1,m)) % m
        @cache
        def fast_pow(a, b, m):
            if b == 0:
                return 1
            if b == 1:
                return a % m
            if b % 2 == 0:
                return fast_pow(a * a % m, b // 2, m)
            else:
                return (a * fast_pow(a * a % m, b // 2, m)) % m
        def solve(word):
            n = len(word)
            d = fact(n,MOD)
            cnt = Counter(word)
            for k in cnt:
                x = cnt[k]
                if(x<2): continue
                inv = fast_pow(fact(x,MOD),MOD-2,MOD)
                d = (d*inv)%MOD
            return d
        words = s.split(' ')
        res = 1
        for w in words:
            res  = (res*solve(w))%MOD
        return res
