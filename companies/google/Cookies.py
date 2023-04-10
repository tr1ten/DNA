import sys
import heapq

# input
t = int(sys.stdin.readline())
# solve here
def solve(H,E,k):
    res = []
    A = [(h,i) for i,h in enumerate(H)]
    A.sort()
    h = []
    j = 0
    while(1):
        while(j<len(H) and A[j][0]<=k):
            heapq.heappush(h,-E[A[j][1]])
            j +=1
        if h:
            res.append(k+-heapq.heappop(h))
            k = res[-1]
        else: break
    return res


# input processing
for _ in range(t):
    n =input()
    H = list(map(int,input().split()))
    E = list(map(int,input().split()))
    k = int(input())
    res = solve(H,E,k)
    print(len(res))
    print(" ".join(map(str,res)))