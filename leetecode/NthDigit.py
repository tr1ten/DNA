def findNthDigit(n: int) -> int:
    base = 1
    i = 1
    while(True):
        temp = base+9*(10**(i-1))*(i)   
        if(temp>n):
            break
        base = temp
        i +=1
    i -=1
    off = (n-base)//(i+1)
    md = (n-base)%(i+1)
    res = (10**i)+off
    return int(str(res)[md])


import sys


# input
t = int(sys.stdin.readline())
# solve here
# input processing
for _ in range(t):
    n = int(input())
    print(findNthDigit(n))