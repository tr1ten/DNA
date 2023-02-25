class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        a,b = float('-inf'),0 #  a - min cost stock, b - max profit to sell that a
        for x in prices:
            b = max(b,x+a)
            a = max(a,-x)
        return b