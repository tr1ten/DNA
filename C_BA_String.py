import sys


# input
t = int(sys.stdin.readline())
# solve here
def solve():
    n,k,x = map(int,input().split())
    s = input()
    a = []
    b = []
    i = 0
    while i<n:
        if s[i]=='a': 
            cs = ""
            while i<len(s) and s[i]=='a': 
                cs +='a'
                i+=1
            b.append(cs)
            continue
        else:
            len = 0
            while i<len(s) and s[i]=='*':
                len +=1;
                i+=1
            a.append(len*k)
    b.append("")
    suff = [1]
    for i in range(len(a)-1,-1,-1):
        suff.append(suff[-1]*a[i])
    ans = ""
    for i in range(len(a)):
        j = 0
        while suff[i+1]<=x:
            j +=1
            ans += 'b'
            x -=suff[i+1]
        ans += b[i]
        
            
# input processing
for _ in range(t):
    solve()