M = 10**9 + 7;
B  = 9973
def code(x): return ord(x) - ord('a') + 1
class HashedString:
    def __init__(self,s) -> None:
        n = len(s)
        self.ppow =  [1]
        self.hashes = [0]
        for i in range(n): self.ppow.append((self.ppow[-1]*B)%M)
        for i in range(n): self.hashes.append((self.hashes[-1]*B + code(s[i]))%M)
    def get_hash(self,i,j):
        return (self.hashes[j+1]-self.hashes[i]*self.ppow[j-i+1])%M
    

def countDistinctSubstrings(s):
    res = 0
    hs = HashedString(s)
    for k in range(1,len(s)+1):
        st = set()
        for i in range(len(s)-k+1):
            j = i+k-1
            st.add(hs.get_hash(i,j))
        res +=len(st)
    return res+1
