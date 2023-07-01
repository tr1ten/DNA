import sys
from functools import lru_cache
from collections import Counter
import string
def solve(a,b):
    if(len(a)!=len(b)):
        return "".join(sorted(a,reverse=1))
    cnt = Counter(a)
    @lru_cache(None)
    def dp(pos,digits,f):
        if pos==len(b):
            return ""
        lmt = 9
        if(not f): lmt = int(b[pos])
        res = ""
        digits = list(digits)
        for d in range(0,lmt + 1):
            if(pos==0 and d==0): continue
            if digits[d]:
                temp = digits[::]
                temp[d] -=1
                nf = f
                if not f and d<int(b[pos]): nf = True
                res = max(str(d) + dp(pos+1,tuple(temp),nf),res,key=lambda x:(len(x),x))
        return res
    return dp(0,tuple([cnt[i] for i in string.digits]), False)
a = input()
b = input()
print(solve(a,b))