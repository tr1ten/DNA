MAX=2*(10**4) + 1
def sieves():
    primes = [True]*MAX
    for i in range(2,MAX):
        if(not primes[i]): continue
        for j in range(i*i,MAX,i):
            primes[j] = False
    only_primes = [i for i in range(2,MAX) if(primes[i])]
    return only_primes  
PRIMES = sieves()
SET_PRIMES = set(PRIMES)
class Solution:
    def primesum(self,A):
        for p in PRIMES:
            if(p>A): break
            if(A-p in SET_PRIMES): return [p,A-p]
        return [-1,-1]
            
     
def main():
    print(Solution().primesum(123))
main()