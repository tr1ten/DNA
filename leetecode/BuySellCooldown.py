class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        cool,buy,sell,sold = 0,float('-inf'),0,0
        for x in prices:
            sold = sell
            sell = buy+x
            buy = max(buy,cool-x)
            cool = max(cool,sold)
        return max(cool,sell)