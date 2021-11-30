class Solution:
    def findMaxConsecutiveOnes(self, nums) -> int:
        pointer = 0
        array = [0]
        for number in nums:
            if number:
                array[pointer] +=1
            else:
                array.append(0)
                pointer +=1
        return max(array)