import bisect
MAX=2*(10**3) + 1
def sieves():
    primes = [True]*MAX
    for i in range(2,MAX):
        if(not primes[i]): continue
        for j in range(i*i,MAX,i):
            primes[j] = False
    only_primes = [i for i in range(2,MAX) if(primes[i])]
    return only_primes  
PRIMES = sieves()
class Solution:
    def primeSubOperation(self, nums) -> bool:
        for i in range(len(nums)-2,-1,-1):
            a,b = nums[i],nums[i+1]
            if(a<b): continue
            pinx = bisect.bisect_right(PRIMES,a-b)
            if(pinx==len(PRIMES) or PRIMES[pinx]>=a): return False
            nums[i] = a-PRIMES[pinx]
        return True
def main():
    obj = Solution()
    print(obj.primeSubOperation([6,8,11,12]))

main()