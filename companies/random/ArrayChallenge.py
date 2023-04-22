def ArrayChallenge(A):
    if(not A): return "-1"
    sm = sum(A)
    A.sort()
    if(sm%2): return "-1";
    tar = sm//2;
    set1 = -1
    def f(idx,mask):
        nonlocal set1
        if(idx==len(A)):
            sm = 0
            for i in range(len(A)):
                if(mask&(1<<i)): 
                    sm +=A[i]
            if(sm==tar):
                set1 = mask
            return sm==tar
        if(not f(idx+1,mask)):
            return f(idx+1,mask | (1<<idx))
        return True
    if not f(0,0): return "-1"
    st1 = []
    st2 = []
    for i in range(len(A)):
        if(set1 & (1<<i)): st1.append(A[i])
        else: st2.append(A[i])
    res =""
    if(st1[0]<st2[0]):
        res += ",".join(map(str,st1))  +","
        res += ",".join(map(str,st2))
    else:
        res += ",".join(map(str,st2)) +","
        res += ",".join(map(str,st1))
    print(st1,st2,res)
    
    return res
                
print(ArrayChallenge([16,22,35,8,20,1,21,11]))