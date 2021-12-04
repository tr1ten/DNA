class Solution(object):
    def longestConsecutive(self, nums):
        if(len(nums)==0):
            return 0
        """
        :type nums: List[int]
        :rtype: int
        """
        startset = set()
        numset = set(nums)
        maxCons = 1
        for el in numset:
            if((el-1) not in numset):
                startset.add(el)
        i = 1
        for e in startset:
            while 1:
                if((e+i) in numset ):
                    i +=1
                else:
                    break
            if(i>maxCons):
                maxCons = i
            i = 1
        return maxCons
                    
        
print(Solution().longestConsecutive([9,1,4,7,3,-1,0,5,8,-1,6]))