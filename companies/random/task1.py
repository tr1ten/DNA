import string
def solve(A,n):
    res=  0
    for x in A:
        for c in string.ascii_lowercase:
            if n*c in x and (n+1)*c not in x:
                res+=1
                break
    return res

A = input().split()
n = int(input())
print(solve(A,n))