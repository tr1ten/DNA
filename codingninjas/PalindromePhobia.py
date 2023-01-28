def largestString(n: int, s: str) -> int:
    last = 0
    res = 0
    for mid in range(n-1):
        # first check for 5 length pali
        l=mid
        r=mid
        pali = False
        while(l>=0 and r<n and s[l]==s[r]):
            if(r-l+1==5): 
                pali = True
                break
            l -=1
            r +=1
        if(pali):
            res = max(res,mid-last+2)
            last = mid-1
            continue
        l=mid
        r=mid+1
        while(l>=0 and r<n and s[l]==s[r]):
            if(r-l+1==6): 
                pali = True
                break
            l -=1
            r +=1
        if(pali):
            res = max(res,mid-last+3)
            last = mid-1
            continue
    return max(res,n-last)
        


