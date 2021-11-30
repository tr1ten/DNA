# Desc : Find Numbers with Even Number of Digits
from functools import reduce


class Solution:
    def findNumbers(self, nums) -> int:
        return reduce(lambda count, x: count+1 if len(x) % 2 == 0 else count, map(str, nums), 0)
