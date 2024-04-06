import sys


# input
t = int(sys.stdin.readline())
def solve():
    x = int(input())
    if(x==1):
        print(-1)
    elif(x==2):
        print(1,1,1)
    else: 
        n = x//2;
        if(n<10**6):
            if(x%2==0): print(2,n-1,2)
            else: print(2,n,1)
        else:
            x1 = x//(10**(len(str(x))//2))
            if(x%x1): print(x1,x//x1,x%x1)
            else: print(x1,(x//x1)-1,x1)
# input processing
for _ in range(t):
    solve()