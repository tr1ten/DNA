from typing import List
class Solution:
    def minOperations(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        ts = sum(nums)
        queries=  sorted([(x,i) for i,x in enumerate(queries)])
        j = 0
        pref = 0
        res = [0]*len(queries)
        for x,i in queries:
            while(j<len(nums) and nums[j]<=x): 
                pref +=nums[j]
                j +=1
            res[i] = (j*x - pref + (ts-pref)-(len(nums)-j)*x)
        return res
            
            
def main():
    obj  = Solution()
    print(obj.minOperations([3,1,6,8],[1,5]))
    print(obj.minOperations([2,9,6,3],[10]))
main()
            
        