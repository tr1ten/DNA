class Solution:
    def sortedSquares(self, A):
        return sorted(list(map(lambda x:pow(x,2),A)))
        