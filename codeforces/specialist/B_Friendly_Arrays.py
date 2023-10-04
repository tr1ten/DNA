MX = 32;
    
import sys
        

# input
t = int(sys.stdin.readline())
# solve here
def solve(A,B):
    cnt = [0]*(MX+1)
    for x in A:
        for i in range(MX+1):
            if(x&(1<<i)): cnt[i]+=1
    
    mx = 0
    for i in range(MX,-1,-1):
        if len(A)%2==1:
            if cnt[i]%2==1: mx =mx | (1<<i)
            else:
                for x in B:
                    if x&(1<<i):
                        mx |= 1<<i
                        break
        else:
            if cnt[i]%2==1: mx = mx|(1<<i) 
    
    mn = 0
    for i in range(MX,-1,-1):
        if len(A)%2==0:
            if cnt[i]%2==1: 
                for x in B:
                    if x&(1<<i):
                        break
                else:
                    mn |= 1<<i
        else:
            if cnt[i]%2==1: mn = mn|(1<<i) 
    
    print(mn,mx)    
# input processing
for _ in range(t):
    n,m = map(int,input().split())
    A= list(map(int,input().split()))
    B= list(map(int,input().split()))
    solve(A,B)