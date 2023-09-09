def fullJustify(wordslen , maxWidth):
    i = 0
    res = 0
    while i<len(wordslen):
        left= maxWidth - wordslen[i]
        k = 1
        while i+k<len(wordslen) and (wordslen[i+k])<left:
            left -= (wordslen[i+k]+1)
            k +=1
        res+=1
        i = i+k
    return res


def solve(A,m):
    lo,hi = max(A),10**18
    ans = -1
    while lo<=hi:
        mid = (lo+hi)//2
        if(fullJustify(A,mid) <= m):
            hi = mid-1
            ans = mid
        else:
            lo = mid+1
    return ans
n,m = map(int,input().split())
A = list(map(int,input().split()))
print(solve(A,m))