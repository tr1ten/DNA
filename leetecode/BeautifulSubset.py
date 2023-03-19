class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        n = len(nums)
        if(n==1): return 1
        nums.sort()
        
        d = defaultdict(list)
        for i,x in enumerate(nums): d[x].append(i)
        cnt = Counter()
        p = 0
        for x in nums:
            p += cnt[x-k]
            cnt[x] +=1
        if(p==0): return (1<<n )- 1
        @cache
        def f(idx,mask):
            if(idx==len(nums)): return 1
            res = f(idx+1,mask)
            for i in d[nums[idx]-k]:
                if(mask&(1<<i)): return res
            res += f(idx+1,(mask | (1<<idx)))
            return res
        return f(0,0)-1
                