class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        mx,my = m,n
        for x,y in ops:
            mx,my = min(x,mx),min(y,my)
        return mx*my