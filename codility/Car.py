def solve(A,x,y):
    """
    Obs: we utilize x as much as we can, greedily take lowest weight first
    sum excedding x will be fullfilled by y
    """
    A.sort()
    if x>y: x,y=y,x
    dp = [False]*(x+1) # space optimized- dp[index][sum] - can we completely utilize sum at index
    dp[0] = True 
    sm,mx_x,res = 0,0,0
    for v in A:
        sm += v
        if v > max(x,y) or sm>(x+y):
            break
        if v<=x:
            for i in range(x,v-1,-1):
                if dp[i-v]:
                    dp[i] = True 
                    mx_x = max(i,mx_x)
        if sm-mx_x>y: break
        res+=1
    return res 

n = int(input())
A = list(map(int,input().split()));
X  = int(input())
Y = int(input())
print(solve(A,X,Y))