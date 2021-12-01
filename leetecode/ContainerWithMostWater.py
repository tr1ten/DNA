from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxArea = 0
        low = 0
        high = len(height) - 1
        while low < high:
            area = (high-low)*min(height[high],height[low])
            maxArea = max(maxArea,area)
            if(height[low]<height[high]):
                low +=1
            else:
                high -=1
        return maxArea
                
        