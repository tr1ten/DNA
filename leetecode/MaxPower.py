from itertools import accumulate
class FenwickTree:
    def __init__(self, nums):
        self.tree = [0]*(len(nums)+1)

    def update(self, i, diff):
        i += 1
        while i < len(self.tree):
            self.tree[i] += diff
            i += i & (-i)

    def _rangeSum(self, i):
        i += 1
        sum = 0
        while i > 0:
            sum += self.tree[i]
            i -= i & (-i)
        return sum

    def rangeSum(self, i, j):
        return self._rangeSum(j) - self._rangeSum(i-1)
class Solution:
    def maxPower(self, nums: List[int], r: int, k: int) -> int:
        def ok(x):
            temp = k
            acc = FenwickTree(nums)
            for i in range(len(nums)):
                acc.update(i, nums[i])
            for i in range(len(nums)):
                dff = acc.rangeSum(max(0,i-r),min(len(nums)-1,i+r))-x
                # print(dff, temp,i, x)
                if(dff+temp<0): 
                    # print("returning ", False)
                    return False
                if(dff<0):
                    temp += dff
                    acc.update(min(len(nums)-1,i+r),-dff)
            # print("returning ",True)
            return True
        high = 10**8
        low = 0
        while(low<high):
            mid = (low+high)//2;
            if(ok(mid)):
                low = mid+1
            else:
                high = mid
        return low-1