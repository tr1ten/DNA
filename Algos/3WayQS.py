import random
from functools import cache
import sys
@cache
def str_less(a,b): # string comp
    return len(a)<len(b) or (len(a)==len(b) and a<b)
# not working please fix somebody
@cache
def int_less(a,b): return a<b
def partition(A,l,r,less=str_less):
    m = random.randint(l,r)
    A[m],A[l] = A[l],A[m]
    lt = l  # We initiate lt to be the part that is less than the pivot
    i = l   # We scan the array from left to right
    gt = r  # The part that is greater than the pivot
    pivot = A[l]    # The pivot, chosen to be the first element of the array, that why we'll randomize the first elements position
                    # in the quick_sort function.
    while i <= gt:      # Starting from the first element.
        if A[i] < pivot:
            A[lt], A[i] = A[i], A[lt]
            lt += 1
            i += 1
        elif A[i] > pivot:
            A[i], A[gt] = A[gt], A[i]
            gt -= 1
        else:
            i += 1
            
    return lt, gt

def quick(A,i,j,k,**kwargs):
    if i==j: return A[i]
    lo,hi = partition(A,i,j,**kwargs)
    if lo+1<=k<=hi: return A[lo]
    if hi<k:
        return quick(A,hi,j,k,**kwargs)
    else:
        return quick(A,i,lo-1,k,**kwargs)
def main():
    # print(sorted(a))
    a = ["3","6","7","10"]
    for k in range(len(a)): print(quick(a,0,len(a)-1,k+1))
main()
        