from typing import List


class Solution:
    def threeSum(self, nums):
        if(len(nums)<3):
            return []
        nums.sort()
        pt1 = 0 
        pt2 = 1
        pt3 = len(nums) -1 
        triplets = []
        while  pt2 < pt3 and pt1<pt2 and nums[pt1]<=0 :
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
                s = a+b+c
                if((s)==0):
                    triplets.append([a,b,c])
                    pt3 -=1
                elif(s>0):
                    pt3 -=1
                else:
                    pt2 +=1
            pt1 +=1
            pt2 = pt1 +1
            pt3 = len(nums) -1
        return triplets
                    
                    
            
print(Solution().threeSum([0,0,0]
))