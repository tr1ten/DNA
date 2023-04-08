from sortedcontainers import SortedList
def fancy(pairs,k1,k2):
    n =len(pairs)
    A = [(pairs[i][0],pairs[i][1],i) for i in range(n)]
    A.sort();
    sc= SortedList()
    j = 0
    i = 0
    res = 0
    for i in range(n):
        while(j<i and A[j][0]+A[i][0]<=k1):
            sc.add((A[j][1],A[j][2]))
            j +=1
        ind = sc.bisect_right((k2-A[i][1],A[i][2]))
        res +=ind
        
    return res
n,k1,k2 =  map(int,input().split())
pairs = []
for i in range(n):
    pairs.append(list(map(int,input().split())))
print(fancy(pairs,k1,k2))
