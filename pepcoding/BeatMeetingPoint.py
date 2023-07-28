n,m = map(int,input().split())
ones = []
ys = []
xs = []
for i in range(n):
    s = input().split()
    for j in range(len(s)):
        x = s[j]
        if x=='1':
            ys.append(i)
            xs.append(j)
            ones.append((i,j))
xs.sort()
ys.sort()
xm,ym = xs[len(xs)//2],ys[len(ys)//2]
# print(xm,ym,xs,ys)
res = 0
for y,x in ones:
    res +=  abs(x-xm) + abs(y-ym)
print(res);