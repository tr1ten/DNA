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
    
s = input()
t = input()
c0 = s.count('0')
c1 = len(s) - c0
ts = HashedString(t)
res = 0
for lr0 in range(1,len(t)//c0):
    if (len(t)-lr0*c0)%c1!=0:continue
    lr1 = (len(t)-lr0*c0)//c1
    szs = [lr0,lr1]
    hashes = [0,0]
    r = 0
    for i in range(len(s)):
        x = int(s[i])
        if hashes[x]==0:
            hashes[x] = ts.get_hash(r,r+szs[x]-1)
        if hashes[x]!=ts.get_hash(r,r+szs[x]-1) or hashes[x]==hashes[x^1]: 
            res-=1
            break
        r += szs[x]
    res +=1
print(res)