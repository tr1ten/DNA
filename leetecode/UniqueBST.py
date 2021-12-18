class Solution:
    def numTrees(self, n: int) -> int:
        cache = {0:1,1:1,2:2,3:5}
        def rec(n,cache=cache):
            if(n in cache):
                return cache[n]
            uniqBST = 0
            for i in range(n):
                cache[i] = rec(i,cache)
                cache[n-1-i] = rec(n-1-i,cache)
                uniqBST += cache[i] *cache[n-1-i]
            return uniqBST
        return rec(n,cache)
                