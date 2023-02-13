class Solution:
    def jump(self, nums: List[int]) -> int:
        """
            Greedy: Choose that index from given range that can take us farthest ie max possible value of j 
        """
        i = 0
        j = 0
        n = len(nums)
        res = 0
        while(j<n-1):
            ci = j # default index to jump from 
            while(i<=j): # check all possible indices from i to j
                if(i+nums[i]>ci+nums[ci]): ci = i # best index to jump from
                i +=1
            j = ci + nums[ci]
            res +=1
        return res
            
