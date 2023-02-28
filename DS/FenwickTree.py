class FenwickTree:
    def __init__(self, n):
        self.tree = [0]*(n+1)
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
    m, n = map(int, input().split())
    nums = list(map(int, input().split()))
    ft = FenwickTree(nums)
    for x in range(m):
        ft.update(x, nums[x])
    for i in range(n):
        a, b, c = map(int, input().split())
        if a == 1:
            ft.update(b-1, c-nums[b-1])
            nums[b-1] = c
        else:
            print(ft.rangeSum(b-1, c-1))