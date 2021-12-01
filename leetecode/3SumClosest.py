from typing import List


class Solution:
    def threeSumClosest(self, nums,target):
        nums.sort()
        pt1 = 0 
        pt2 = 1
        pt3 = len(nums) -1 
        minDiff = 11000
        minClosestVal = 0
        while  pt2 < pt3 and pt1<pt2 :
            if(pt1 > 0 and nums[pt1]==nums[pt1-1]):
                pt1 +=1
                pt2 +=1
                continue
            while pt2 < pt3:
                a,b,c = nums[pt1],nums[pt2],nums[pt3]
                if(pt2>pt1+1 and b==nums[pt2-1]):
                    pt2 +=1
                    continue
                if(pt3<(len(nums)-1) and c==nums[pt3+1]):
                    pt3 -=1
                    continue
                s =  a+b+c
                ab = abs(s-target)
                if((ab<minDiff)):
                    minDiff = ab
                    minClosestVal = s
                if((s-target)>0):
                    pt3 -=1
                else:
                    pt2 +=1
            pt1 +=1
            pt2 = pt1 +1
            pt3 = len(nums) -1
        return minClosestVal
                    
                    
            
print(Solution().threeSumClosest( [0,2,1,-3],1
))