import sys

import math
# input
t = int(sys.stdin.readline())
# solve here
def solve(n):
    ans = int(math.floor((1+math.sqrt(1+8*n))/2));
    return int(n - (ans*(ans-3))//2 )
# input processing
for _ in range(t):
    n  =int(input())
    print(solve(n))