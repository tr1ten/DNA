import sys


# input
t = int(sys.stdin.readline())
# solve here
def solve():
    x,y = map(int,input().split())
    if(x**4 + 4*y**2 == 4*(x**2)*(y)): print("YES")
    else: print("NO")
    
# input processing
for _ in range(t):
    solve()