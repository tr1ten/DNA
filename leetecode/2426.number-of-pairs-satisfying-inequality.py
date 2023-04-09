#
# @lc app=leetcode id=2426 lang=python3
#
# [2426] Number of Pairs Satisfying Inequality
#

# @lc code=start
class Solution:
    def numberOfPairs(self, A: List[int], B: List[int], diff: int) -> int:
        OFF = 10**4+5
        diffs = BIT(2*OFF)
        res = 0
        for i in range(len(A)):
            d = A[i]-B[i]
            j = diffs.sum(OFF+d+diff)
            res +=j
            diffs.update(OFF+d,1)
        return res

        
        
class BIT:
    def __init__(self,n:int):
       self.nums = [0]*(n+1)
    def update(self,i:int,val:int):
        i +=1
        while(i<len(self.nums)):
            self.nums[i] +=val
            i += (i&(-i))
    def sum(self,i:int) -> int:
        i +=1
        r = 0
        # i +=1, not needed here since we need sum of rank less than i rank[0...i-1]
        while(i>0):
            r += self.nums[i]
            i -= (i&(-i))
        return r
# @lc code=end

