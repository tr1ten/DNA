from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        setted = {}

        for index, value in enumerate(nums):
            compliment = target - value
            if compliment in setted:
                return [index, setted[compliment]]
            else:
                setted[value] = index

