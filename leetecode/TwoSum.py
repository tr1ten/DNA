class Solution:
    def twoSum(self, nums, target: int):
        setted = {}

        for index, value in enumerate(nums):
            compliment = target - nums[index]
            if compliment in setted:
                return [index, setted[compliment]]
            else:
                setted[nums[index]] = index
