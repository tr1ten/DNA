from collections import Counter
import random

M = 2**61 - 1;
B  = random.randrange(0,M)
def code(x): return ord(x) - ord('a') + 1
class HashedString:
    def __init__(self,s) -> None:
        n = len(s)
        self.ppow =  [1]
        self.hashes = [0]
        for i in range(n): self.ppow.append((self.ppow[-1]*B)%M)
        for i in range(n): self.hashes.append(((self.hashes[-1]*B)%M + code(s[i]))%M)
    def get_hash(self,i,j):
        return (self.hashes[j+1]-(self.hashes[i]*self.ppow[j-i+1])%M )%M
    
            
s = "aa"
t = HashedString(s)
hs = HashedString(s+s)
print(hs.get_hash(1,2)==t.get_hash(0,len(s)-1))