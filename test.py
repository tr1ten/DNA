x,y = map(int,input().split())
def rev(s):
    return int(bin(s)[2:][::-1],2)
def check(s):
    b = bin(s)[2:]
    t = bin(y)[2:]
    try:
        i = t.index(b)-1
        j = i+len(b)
        # print(b,t,i);
        while i>=0:
            if t[i]!='1':
                return False
            i-=1
        while j<len(t):
            if t[j]!='1':
                return False
            j +=1
        return True        
    except:
        return False
    


f = 0
if x==y or check(2*x+1) or check(rev(2*x+1)):
    f=1
while x%2==0:
    x //=2
if check(x) or check(rev(x)):
    f=1
if not f:
    print("NO")
else: print("YES") 

a = list(map(int,input().split()))
arr = []
i = 0
while i<n*m:
    arr.append(a[i:i+m])
    i +=m
