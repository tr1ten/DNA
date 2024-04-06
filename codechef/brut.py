from itertools import permutations
def f(n):
    res = []
    for x in permutations(range(1,n+1)):
        s= 0
        st = set()
        for k in x:
            s +=k;
            if(s%n in st): break
            else: st.add(s%n)
        if(len(st)==n): res.append(x)
        if(res): break
    return res
for i in range(1,12):
    print(len(f(i)))