from sortedcontainers import SortedList
def fancy(pairs,k1,k2):
    n =len(pairs)
    A = [(pairs[i][0],pairs[i][1],i) for i in range(n)]
    A.sort();
    sc= SortedList()
    j = 0
    res = 0
    for i in range(n-1,-1,-1):
        while(j<n and A[j][0]+A[i][0]<=k1):
            sc.add((A[j][1]))
            j +=1
        ind = sc.bisect_right((k2-A[i][1]))
        res +=ind
    for i in range(n):
        if(2*pairs[i][0]<=k1 and pairs[i][1]*2<=k2): res-=1 # remove i,i pairs
    return res//2  # (i,j) and (j,i) are same so need to remove one of them
n,k1,k2 =  map(int,input().split())
pairs = []
for i in range(n):
    pairs.append(list(map(int,input().split())))
print(fancy(pairs,k1,k2))
