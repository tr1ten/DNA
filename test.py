def isPrime(x):
    for i in range(2,int(x**0.5) + 1):
        if x%i==0:
            return False
    return True
def isPali(x):
    return x==x[::-1]
class Solution:
    def primePalindrome(self, n: int) -> int:
        for i in range(n,10000000):
            if isPali(str(i)) and isPrime(i):
                print(i)
        return 0
spol = Solution().primePalindrome(2)