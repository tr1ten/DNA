def sieve(N):
    prime = [1]*N
    prime[0] = 0
    prime[1] = 0
    prms = []
    for i in range(2,N):
        if not prime[i]: continue
        prms.append(i)
        for j in range(2*i,N,i):
            prime[j] = 0
    return prms
import bisect
class Solution:
    def countPrimes(self,L,R):
        primes = sieve(R+1)
        return len(primes) - bisect.bisect_left(primes,L)