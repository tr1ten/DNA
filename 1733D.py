def solve(s1,s2,x,y):
    s = ""
    for xx,yy in zip(s1,s2):
        s += str(int(xx)^int(yy))
    d = s.count('1')
    if d % 2:
        return (-1)

    if d == 2:
        l = next((i for i in range(len(s)) if s[i]=='1'), None)
        r = next((i for i in range(len(s)-1, -1, -1) if s[i]=='1'), None)
        if l is None or r is None:
            return (0)
        elif l + 1 == r:
            return (min(x, 2 * y))
        else: return (min((r - l) * x, y))

    if not d or x >= y:
        return (d // 2 * y)

    dp0 = [float('inf')]*(len(s1)+3)  
    dp1 = [float('inf')]*(len(s2)+3)  
    
    if(s[0]=='0'): dp0[0] = 0
    else: dp1[1] = 0
    for i in range(1,len(s)):
        tdp0 = [float('inf')]*(len(s1)+3)  
        tdp1 = [float('inf')]*(len(s2)+3)  
        for j in range(i+2):
            if s[i]=='0':
                tdp0[j] = min(dp0[j],dp1[j])
                tdp1[j] = min(
                    dp0[j-2] + x, # try 0,0 -> 1,1
                    dp1[j-2] + y,
                    dp1[j] + x, # try 1,0 -> 0,1
                    dp0[j] + y
                )
            else:
                tdp1[j] = min(
                    dp0[j-1],
                    dp1[j-1])
                tdp0[j] = min(
                    dp1[j+1]+x,
                    dp0[j+1]+y,
                    dp0[j-1] + x,
                    dp1[j-1] + y
                )
        dp0  =tdp0
        dp1 = tdp1

                
    return -1 if dp0[0]==float('inf') else dp0[0]

import sys


# input
t = int(sys.stdin.readline())
# input processing
for _ in range(t):
    s,x,y = input().split(" ");
    s1 = input()
    s2 = input()
    print(solve(s1,s2,int(x),int(y)))