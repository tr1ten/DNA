def code(x): return ord(x) - ord('a') + 1
import random
M = 2**61 - 1
B = random.randrange(1,M)
t = int(input())
for i in range(t):
    s = input()
    l=0
    r = len(s)-1
    res = 0
    while l<=r:
        sz = 0
        pref = 0
        suff = 0
        p = 1
        while l+sz<=r-sz:
            pref = (pref + code(s[l+sz])*p)%M
            suff = (suff*B%M + code(s[r-sz]))%M        
            p = (p*B)%M
            sz +=1
            if suff==pref: break
        # print(l,r,pref,suff,sz)
        if l+sz>r-sz and (l==r or pref!=suff): res+=1 # annoying middle case, either overlapping or not matched or single element
        else: res+=2
        l +=sz
        r -=sz
        
    print(res) 