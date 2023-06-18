def r2n(x):
    d = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
    res = 0
    for i in range(len(x)):
        if i+1<len(x) and d[x[i+1]]>d[x[i]]: res -=d[x[i]]
        else: res += d[x[i]]
    return res
print(r2n("XL"))

def cmp(x):
    s,n = x.split()
    return (s,r2n(n))
def solve(A):
    return sorted(A,key=cmp)