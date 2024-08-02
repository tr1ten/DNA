from sortedcontainers import SortedList
def solve(l,e,k):
    n = len(l)
    j = 0
    score = 0
    ans = []
    ns = SortedList()
    aded = [False]*n
    inc = 0
    for i in range(n):
        if i and j>=i:
            inc += l[i-1]
             
        while j<n and k>=l[j]:
            k -= l[j]
            j +=1
            if k>=e[j]:
                score += 1
                aded[j] = True
            else:
                ns.add((e[j]-k,j))
                
        ans.append(score)
    return ans
        
        
l = list(map(int,input().split()))
e = list(map(int,input().split()))
k = int(input())
print(solve(l,e,k)) 