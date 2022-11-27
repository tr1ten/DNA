# TLE N^3
class Solution:
    def splitArray(self, nums: List[int], K: int) -> int:
        n = len(nums)
        MAX = 10**9 + 1
        pref = [0]*(n+1)
        for i in range(1,n+1): pref[i] = pref[i-1] + nums[i-1]
        @cache
        def solve(idx,k):
            if(idx==n): return 0 if(k==0) else MAX
            if(n-idx<=k): return MAX
            if(k==0): return pref[n]-pref[idx]
            res = MAX
            for j in range(idx,n-k):
                res = min(res,max(pref[j+1]-pref[idx],solve(j+1,k-1)))
            return res
        return solve(0,K-1)

# exhaustive binary search
class Solution:
    def splitArray(self, nums: List[int], K: int) -> int:
        n = len(nums)
        lo = max(nums)
        hi = sum(nums)
        while(lo<hi):
            mid = (lo+hi)//2
            tot,cnt = 0,1
            for x in nums:
                if(tot+x<=mid):
                    tot += x
                else:
                    tot = x
                    cnt +=1
            if(cnt<=K):
                hi = mid
            else:
                lo = mid+1
        return hi
                
                    