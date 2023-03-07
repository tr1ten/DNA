
def factors(x):
    ret = set()
    if(x==1): return ret
    for i in range(2,1001):
        if((x%i)==0):
            ret.add(i)
            while(x%i==0): x //=i
    if(x>1): ret.add(x)
    return ret
class Solution:
    def findValidSplit(self, nums: List[int]) -> int:
        suff = Counter() 
        for x in nums:
            for f in factors(x):
                suff[f] +=1
        pref = set()
        for i in range(len(nums)-1):
            x = nums[i]
            for f in factors(x):
                pref.add(f)
                suff[f] -=1
                if(suff[f]==0):
                    pref.remove(f)
                    del suff[f]
                    break
            if(len(pref)==0): return i
            
        return -1