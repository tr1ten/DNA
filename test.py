def isP(x):
    return len(str(x))%2==0 and str(x)==str(x)[::-1]
cnt = 1
for i in range(10**5):
    if isP(i):
        print(cnt,i)
        cnt +=1 