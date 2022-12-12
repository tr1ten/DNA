from collections import Counter
class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        left = Counter(nums)
        end = dict()
        for x in nums:
            if(end.get(x-1,0)>0):
                end[x] = end.get(x,0) + 1
                end[x-1] -=1
            elif(left.get(x+1,0)>0 and left.get(x+2,0)>0):
                left[x+1] -=1
                left[x+2] -=1
                end[x] = end.get(x,0) + 1
            else:
                return False
        return True
