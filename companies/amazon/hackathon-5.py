def solve(A):
    last =A[0]
    cur = 0
    ans = 1
    for i in range(1,len(A)):
        if cur<last:
            cur +=A[i]
        else: 
            last = cur
            cur = 0
            ans +=1
        print(last,cur)
    return ans
    

n = int(input())
A = list(map(int,input().split()))
print(solve(A))