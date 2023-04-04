PRIMES = [1,2,3,5,7,11,13,17,19,23,29]
@cache
def get_mask(x):
    if(x==1): return 0 # not a prime ikr
    mask = 0
    for i in range(1,len(PRIMES)):
        p = PRIMES[i]
        if((x%p)==0):
            c =0
            while(x%p==0): 
                c +=1
                x //=p
                if(c>1): return 0
            mask |= 1<<i
    return mask

class Solution:
    def numberOfGoodSubsets(self, A: List[int]) -> int:
        mod = 10**9 + 7
        masks = [get_mask(x) for x in A if(get_mask(x))]
        cnt = Counter(masks)
        masks = list(sorted(set(masks)))
        @cache
        def pick(idx,mask):
            if(idx==len(masks)): return 1
            res=  pick(idx+1,mask)
            if((mask&masks[idx])==0): res+= cnt[masks[idx]]*pick(idx+1,mask|masks[idx])
            return res%mod
        return ((pick(0,0)-1)*pow(2,(A.count(1)),mod))%mod