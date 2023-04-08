from itertools import zip_longest
def f(l,r):
    res = 0
    for i in range(l+1,r+1):
        for x,y in zip_longest(str(i)[::-1],str(i-1)[::-1],fillvalue="$"):
            if(x!=y): res+=1 
    return res
def f2(r):
    s = str(r)
    res = 0
    d = [1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111]
    for i in range(len(s)):
        res += int(s[i])*(d[len(s)-i-1])
    return res
        
while(1):
    l,r = map(int,input().split())
    print(f(l,r),f2(r)-f2(l))