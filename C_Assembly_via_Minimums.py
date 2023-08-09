import sys


# input
t = int(sys.stdin.readline())
# solve here
def solve():
    n = int(input())
    A = sorted(list(map(int,input().split())))
    i = 0
    k = n-1
    ans = []
    while i<len(A):
        ans.append(A[i])
        i += k   
        k -=1
    ans.append(10**9)
    for x in ans: print(x,end=" ")
    print()
# input processing
for _ in range(t):
    solve()