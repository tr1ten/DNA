class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort()
        res = 0
        for k in reversed(range(len(nums))):
            j= k-1
            i=0
            while(i<j):
                if(nums[k]<nums[i]+nums[j]):
                    res += j-i
                    j -=1
                else:
                    i +=1
        return res
                
