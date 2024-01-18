def solve(lo,hi,k):
    MX = 25
    res =0 
    for a in range(lo,hi+1):
        b = 0
        # try to find b such that it maximizes a^b and b<=hi 
        for j in range(MX-1,-1,-1):
            mask = 1<<j;
            req=  (a^mask)&mask;
            if (req|b)>hi or req<
            
            
        if b>=lo and a^b<=k:
            res = max(res,a^b)
    return  res

print(solve(3,5,6))