from functools import cache
for _ in range(1):
    W,V,mxw,mxv=list(map(int,input().split())),list(map(int,input().split())),int(input()),int(input())
    @cache
    def dp(idx,w,v): # max number of products with total weight w and v, upto idx
        if idx<0 or idx>=len(W): return 0
        if W[idx]>w or V[idx]>v: return dp(idx-1,w,v)
        return max(dp(idx-1,w,v),dp(idx-1,w-W[idx],v-V[idx]) + 1)
    print(dp(len(W)-1,mxw,mxv))
    