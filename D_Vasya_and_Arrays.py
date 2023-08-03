def solve(A,B):
    i,j=0,0
    ans = 0
    sm1,sm2 = A[0],B[0]
    while i<len(A) or j<len(B):
        # print(i,j,sm1,sm2)
        if sm1<sm2: 
            i +=1
            if i==len(A): break
            sm1+=A[i]
        if sm1>sm2:
            j +=1
            if j==len(B): break
            sm2+=B[j]
        if sm1==sm2:
            ans +=1
            i+=1
            j +=1
            if i==len(A) or j==len(B): break
            sm1,sm2 =A[i],B[j]
    return ans if sm1==sm2 and i==len(A) and j==len(B) else -1

n = int(input())
A = list(map(int,input().split()))
m = int(input())
B = list(map(int,input().split()))
print(solve(A,B))