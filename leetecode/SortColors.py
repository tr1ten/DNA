from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        if(len(nums) > 1):
            p1, p, p2 = 0, 0, len(nums)-1
            while p <= p2:

                if(nums[p] == 2):
                    nums[p], nums[p2] = nums[p2], nums[p]
                    p2 -= 1
                elif nums[p] == 1:
                    p += 1
                else:
                    nums[p], nums[p1] = nums[p1], nums[p]
                    p1 += 1
                    p += 1
