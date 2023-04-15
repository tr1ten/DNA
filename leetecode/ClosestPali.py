class Solution:
    def nearestPalindromic(self, n: str) -> str:
        if(len(n)==1): return str(int(n)-1)
        def build(x): return x[:(len(x)+1)//2] + x[:len(x)//2][::-1]
        cands = [build(n),str(10**(len(n)-1)-1),str(10**(len(n)-1)+1),str(10**(len(n))-1),str(10**(len(n))+1),build(str(int(n)-(10**((len(n))//2 )))),build(str(int(n)+(10**((len(n))//2 ))))]
        vals = [(abs(int(n)-int(x)),int(x)) for x in cands if x!=n]
        return str(min(vals)[1])