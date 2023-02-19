class Solution:
    def squareFreeSubsets(self, nums: List[int]) -> int:
        primes = [2,3,5,7,11,13,17,19,23,29]
        MOD = 10**9 + 7
        dp = [[-1]*(1<<10) for i in range(len(nums))]
        @cache
        def prime_mask(num):
            mask = 0
            for i in range(len(primes)):
                times = 0
                while(num%primes[i]==0): 
                    num //=primes[i];
                    times+=1
                if(times>1): return -1 # not valid 
                if(times==1): mask |= 1<<i
            return mask
        def pick(idx,product_mask):
            if(len(nums)==idx): return 1
            if(dp[idx][product_mask]!=-1): return dp[idx][product_mask];
            res = pick(idx+1,product_mask)
            mask = prime_mask(nums[idx])
            if(mask!=-1 and (mask&product_mask)==0): # if no common primes
                res = (res+pick(idx+1,product_mask|mask))%MOD
            dp[idx][product_mask] = res
            return res
        return (pick(0,0)-1%MOD)%MOD
            
            
        
                    
                    