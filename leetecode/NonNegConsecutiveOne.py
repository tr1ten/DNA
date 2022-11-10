import math
# part 1: recognize the pattern of fibonacci sequence since msb depend on previous msb
# part 2 (little complex): if cur and prev are set then we can't have more possible numbers after that bit else continue to check rest 
# Time complexity: O(logn) or O(1) if n range is fixed
class Solution:
    def findIntegers(self, n: int) -> int:
        # we can use magic number as well but this is more readable
        d = math.floor(math.log2(n));
        # we can do it in single pass but this is more readable
        dp = [[0]*(d+1) for i in range(2)] # dp[i][j] = number of possible numbers with jth bit set and ith bit set -> 1x(possibilities if prev bit is 1) + 1x(if 0) 
        # for last bit is not set then that mean we can have either 0 or 1 for this position so we add both possibilities -> 1x(possibilities prev bit is 0)
        # else we need to put 0 here and get all possible numbers for next position
        # base case
        dp[0][d] = 1;
        dp[1][d] = 1;
        for i in range(d-1,-1,-1):
            dp[0][i] = dp[0][i+1] + dp[1][i+1]
            dp[1][i] = dp[0][i+1]
        prev = False
        res = 0
        for i in range(0,d+1):
            cur = (n & 1<<(d-i))>0;
            if(cur):
                res += dp[0][i]
                if(prev): return res
            prev = cur
        return res+1; # include itself (since no two one's)