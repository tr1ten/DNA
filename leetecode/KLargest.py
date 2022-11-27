class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def pivot(i,j):
            p = i-1
            pv = nums[j];
            for m in range(i,j):
                if(nums[m]<pv):
                    p +=1
                    nums[p],nums[m] = nums[m],nums[p]
            p +=1
            nums[j],nums[p] = nums[p],nums[j]
            return p
        res = -1
        t = (len(nums)-k)
        def quick(i,j):
            if(i>=j): return -1;
            p = pivot(i,j)
            if(p==t):
                return nums[p]
            elif(p>t):
                return quick(i,p-1);
            else:
                return quick(p+1,j);
        return quick(0,len(nums)-1)