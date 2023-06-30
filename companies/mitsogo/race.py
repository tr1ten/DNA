A = list(map(int,input().split()))
B = list(map(int,input().split()))
C = list(map(int,input().split()))
D = list(map(int,input().split()))
check = dict(zip(C,D))
from functools import cache
@cache
def dp(d,h): # h=0,d=0,1,2..
    if d>=len(A): # if race finished
        return 0
    if d in check and check[d]>h: return 0 # if violated constraint of checkpoint
    return max(dp(d+1,h) + A[d],dp(d+1,h+B[d])) # either pick point or increase ht
print(dp(0,0))