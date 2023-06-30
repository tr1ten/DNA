import random
from functools import cache
import sys
@cache
def str_less(a,b): # string comp
    return len(a)<len(b) or (len(a)==len(b) and a<b)
@cache
def int_less(a,b): return a<b
def partition(A,i,j,less=str_less):
    r = random.randint(i,j)
    A[r],A[j] = A[j],A[r]
    p = i-1;
    for k in range(i,j):
        if less(A[k],A[j]):
            p +=1
            A[k],A[p] = A[p],A[k]
    p +=1
    A[j],A[p] = A[p],A[j]
    return p
def quick(A,i,j,k,**kwargs):
    if i==j: return A[i]
    p = partition(A,i,j,**kwargs)
    if p+1==k: return A[p]
    if p+1<k:
        return quick(A,p+1,j,k,**kwargs)
    else:
        return quick(A,i,p-1,k,**kwargs)
def main():
    a = [0]*1000000;
    # print(sorted(a))
    print(quick(a,0,len(a)-1,10+1,less=int_less))
main()
        