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
    
t = 1
for i in range(t):
    n = input()
    h = input()
    if len(h)<len(n):
        print(0)
        break
    i = 0
    perms = set()
    cnt = Counter()
    req = Counter(n)
    hs = HashedString(h)
    for j in range(len(h)):
        cnt[h[j]]+=1
        while i<=j and cnt[h[j]]>req[h[j]]:
            cnt[h[i]]-=1
            i +=1
        if j-i+1==len(n):
            perms.add(hs.get_hash(i,j))
    print(len(perms))