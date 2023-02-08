from os import *
from sys import *
from collections import *
from math import *

def maxSumSubmatrix(mar,n,m):
    res = float('-inf')
    # check for each possible column pairs c1...cn, c2...cn,...
    for c1 in range(m):
        pref = [0]*n
        for c2 in range(c1,m):
            for r in range(n):
                pref[r] += mar[r][c2]
            sm = 0 # regular kadane algo
            mx = float('-inf')
            for x in pref: 
                sm = max(sm+x,x)
                mx = max(mx,sm)
            res = max(mx,res)            
    return res
