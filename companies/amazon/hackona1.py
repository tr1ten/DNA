def solve(A,n):
    mx1=-1
    mx2=-1
    for x in A:
        digits = []
        for k in x:
            if k in "0123456789":
                digits.append(k)
        v = 0
        if digits:
            v = int("".join(digits))
        else: v = len(x)
        if v>mx1:
            mx2 = mx1
            mx1 = v
        elif v>mx2: mx2 = v
    return mx1*mx2
        

n = int((input()).split()[0])
A = input().split()[:n]
print(solve(A,n))