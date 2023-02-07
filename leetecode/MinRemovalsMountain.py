class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)
        lis = [1]*n
        for i in range(n):
            for j in range(i+1,n):
                if(nums[i]<nums[j]): lis[j] = max(lis[j],lis[i]+1);
        lds = [1]*n
        for i in reversed(range(n)):
            for j in range(i-1,-1,-1):
                if(nums[i]<nums[j]): lds[j] = max(lds[j],lds[i]+1);
        res = 0
        for i in range(n):
            if(lis[i]!=1 and lds[i]!=1):
                res = max(lis[i]+lds[i]-1,res)
        return len(nums)-res