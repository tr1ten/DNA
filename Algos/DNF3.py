# dutch national flag 3
# The problem was posed with three colours, here `0', `1' and `2'. The array is divided into four sections:
# a[1..Lo-1] zeroes (red)
# a[Lo..Mid-] ones (white)
# a[Mid..Hi] unknown
# a[Hi+1..N] twos (blue)

# invarient 0...lo-1 all zeros, lo...mid-1 all 1 and mid to hi all 2
# O(n)
def dnf(A):
    hi = len(A)-1
    lo = 0
    mid = 0
    while(mid<hi):
        if A[mid]==0:
            while lo<len(A)-1 and A[lo]==0: lo +=1 
            A[lo],A[mid] = A[mid],A[lo]  
        elif A[mid]==2:
            while hi>0 and A[hi]==2: hi -=1 
            A[hi],A[mid] = A[mid],A[hi]  
        else: mid +=1

A = [1,0,1,0,2,1,0,2]
dnf(A)
print(A)