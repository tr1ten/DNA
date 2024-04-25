p = 4
def nb(n, b):
    if n == 0:
        return [0]
    digits = []
    while n:
        digits.append(int(n % b))
        n //= b
    while len(digits)<p:
        digits.append(0)
    return "".join(map(str,digits[::-1]))

n = 9
# [8, 11, 11, 8, 11, 11, 8, 11, 11] [7, 9, 8, 4, 6, 5, 1, 3, 2]
# c = 0
# for i in range(1,2*100):
#     s = nb(i,3)
#     c += '2' in s
#     print(i," =>",s," = ",c)
    
# print(c)

def br(cur,left):
    if len(cur)==n:
        ls = []
        for i in range(1,n+1):
            ls.append(i+cur[i-1])
        if len(set(ls))==2:
            print(ls,cur )
        return 
    for j in left:
        if "2" in nb(len(cur)+1+j,3):
            nl = left[:]
            nl.remove(j)
            br(cur+[j],nl)
br([],[i+1 for i in range(n)])
# # print(nb(n+1,3))
for n in range(4,1000):
    a =  "2" in nb(n,3)
    # if a:
    #     if not ("2" in nb(2*n,3)):
    #         print(n)
    #         break
    assert("2" in nb(n+1,3) or a or ("2" in nb(n-1,3)  and "2" in nb(n+2,3) ));