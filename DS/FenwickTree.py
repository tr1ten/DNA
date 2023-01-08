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

if __name__ == '__main__':
    nums = [1,2,3,4,5,6,7,8,9,10]
    ft = FenwickTree(nums)
    for i in range(len(nums)):
        ft.update(i, nums[i])
    print(ft.rangeSum(2,2))