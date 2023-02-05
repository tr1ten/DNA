from collections import Counter
class Solution:
    def minCost(self, b1: List[int], b2: List[int]) -> int:
        cnt1 = Counter(b1)
        cnt2 = Counter(b2)
        if(any([abs(cnt1[x]-cnt2[x])%2!=0 for x in b1])): return -1 # if sum of freq of any element is odd then it is not possible to make equal
        r1 = [] # number need to be added in b1
        r2 = [] # number need to be added in b2
        for x in set(b1+b2):
            if(cnt1[x]<cnt2[x]):
                r1.extend([x]*((-cnt1[x]+cnt2[x])//2))
            if(cnt1[x]>cnt2[x]):
                r2.extend([x]*((cnt1[x]-cnt2[x])//2))
        mn = min(b1+b2)*2 # either directly swap number from r1 or r2 or use min number as intermediate to swap two number thus need two min swaps
        # align r1 and r2 in such a way that (xr1,xr2) is the pair of number to be swapped
        # one-one correspondence between r1 and r2
        r1.sort() # max number will be at the end
        r2.sort(reverse=True) # min number will be at the end 
        return sum([min(mn,min(x,y)) for x,y in zip(r1,r2)])  
                
                
            
        