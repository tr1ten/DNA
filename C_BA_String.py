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
    M = 1e19
    while i<n:
        if s[i]=='a': 
            i +=1
            continue
        else:
            ck = 0
            while i<len(s) and s[i]=='*':
                ck +=1;
                i+=1
            a.append(min(M,ck*k))
    b.append("")
    suff = [1]
    for i in range(len(a)-1,-1,-1):
        suff.append(suff[-1]*(a[i]+1))
    suff = suff[::-1]
    js = []
    # print(suff,a)
    for i in range(len(a)):
        j = 0
        cur = ""
        while suff[i+1]<x:
            j +=1 
            cur += 'b'
            x -=(suff[i+1])
        assert(j<=a[i])
        js.append(cur)
        # print(ans,x,suff[i+1])
    
    ans = ""
    j = 0
    i =0
    while i<n:
        if s[i]=='a':
            ans += 'a' 
            i +=1
            continue
        else:
            while i<len(s) and s[i]=='*':
                i+=1
            ans+=js[j]
            j +=1
            a.append(ck*k)
    print(ans)        
            
# input processing
for _ in range(t):
    solve()