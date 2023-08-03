def solve(A,B):
    i,j=0,0
    ans = 0
    sm1,sm2 = 0,0
    while i<len(A) or j<len(B):
        if sm1<sm2: 
            if i==len(A): break
            sm1+=A[i]
            i +=1
        else:
            if j==len(B): break
            sm2+=B[j]
            j +=1
        if sm1==sm2:
            sm1,sm2 = 0,0
            ans +=1
            i+=1
            j +=1
    return ans if ans>0 else -1
print(solve([1,3,2,4],[4,2,4]))
    
    

