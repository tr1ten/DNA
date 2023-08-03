# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
from functools import lru_cache
def solution(H, X, Y):
    # Implement your solution here
    mem = dict()
    def dp(idx,x,y):
        if idx==len(H): return 0
        if (idx,x,y) in mem: return mem[ (idx,x,y) ]
        res = dp(idx+1,x,y)
        if x>=H[idx]: res =max(res,dp(idx+1,x-H[idx],y)+1)
        if y>=H[idx]: res= max(res,dp(idx+1,x,y-H[idx]) +1)
        mem[(idx,x,y)] = res
        return res
    dp(0,X,Y)
    return dp(0,X,Y)

n = int(input())
A = list(map(int,input().split()));
X  = int(input())
Y = int(input())
print(solution(A,X,Y))