def solve(n):
    c = []
    while n>1:    
        t = int((-1+(1+24*n)**(1/2))//6)  
        c.append(t)
        n -= ((3*(t**2)+t)//2)
    return len(c)
    
print(solve(14))