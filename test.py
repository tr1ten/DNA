k,a,b=map(int,input().split())
r = 0
r = a<=0 and 0<=b;
if(a<0 and b<0):
    a = -a;
    b = -b;
    a,b = b,a

left = 0;
if(a<0 and b>=0): left = abs(a)//k;
else: left = -((a-1)//k);
cnt = 0;
ans = b//k + left + r;
print(ans);