def solve(x,y):
    res =""
    if(len(x)>len(y)): x,y = y,x
    x = "0"*(len(y)-len(x)) + x
    for i,j in zip(x,y):
        res += str(int(i)+int(j))
    return res
print(solve('11','9'))
print(solve('99','99'))
