import math
t = int(input())
for i in range(t):
    n = int(input())
    if n%2==1: print(-1)
    else: print(1,n//2)