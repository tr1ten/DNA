def nb(n, b):
    if n == 0:
        return [0]
    digits = []
    while n:
        digits.append(int(n % b))
        n //= b
    return "".join(map(str,digits[::-1]))

t = int(input())
while(t):
    t -= 1
    n = int(input())
    if n==3:
        print("1 3 2")
        continue
    start = n
    for s in range(n+1,0,-1):
        if "2" in nb(s,3):
            c = 1
            f = 1
            res = []
            for i in range(s-1,0,-1):
                res.append(i)
                f = f & ("2" in nb(c+i,3))
                c +=1
            for i in range(n,s-1,-1):
                res.append(i)
                f = f &( "2" in nb(c+i,3))
                c +=1
            if f:
                # assert(c==n)
                print(" ".join(map(str,res)))
                break