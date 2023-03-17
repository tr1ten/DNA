class Node:
    def __init__(self):
        self.c = 0
        self.left = None
        self.right = None
class Solution:
    def numOfWays(self, nums: List[int]) -> int: 
        mod = 10**9 + 7
        def dp(arr):
            if(len(arr)<=2): return 1
            left = [x for x in arr if(x<arr[0]) ]
            right = [x for x in arr if(x>arr[0]) ]
            return dp(left)*dp(right)*math.comb(len(arr)-1,len(left))
        return (dp(nums)-1+mod)%mod