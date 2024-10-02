import sys


# input
t = int(sys.stdin.readline())
def add_strings(s1,s2):
    pass
# solve here
def solve():
    s = input()
    nums = s.split("+")
    res = int(nums[0]) + int(nums[-1])
    for x in nums[1:-1]:
        res += max(int(x[1:])+int(x[0]), int(x[:-1])+int(x[-1]))
    print(res)
# input processing
for _ in range(t):
    solve()