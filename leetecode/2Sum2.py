from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        p1 = 0
        p2 = len(numbers)-1
        while p1<p2:
            s = numbers[p1] + numbers[p2] - target
            if(s==0):
                return [p1,p2]
                p1 +=1
            elif(s<0):
                p1 +=1
            else:
                p2 -=1
        