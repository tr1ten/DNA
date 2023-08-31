import sys

input = sys.stdin.readline;
# input
t = int(input())
# solve here
def solve(A,k):
    n = len(A)
    k = k%(n+1)
    if k==0: return A
    x=0;
    st = set(A)
    while x in st: x+=1;
    A.append(x)
    return  A[-(k):] + A[:-(k+1)]
# input processing
for _ in range(t):
    n,k = map(int,input().split())
    A = list(map(int,input().split()))
    print(*solve(A,k))