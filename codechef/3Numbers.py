from collections import Counter
import bisect
from itertools import accumulate, combinations, permutations

T = int(input())
for _ in range(T):
    A,B,C = map(int,input().split())
    s = [A,B,C]
    s.sort()
    cost = 0
    if(s[0]!=s[1] and s[1]!=s[2]): # three number diff, cost of make two of them eq
        if((s[-1]-s[-2])%2==1 or (s[1]-s[0])%2==1): 
            print(-1)
            continue
        else:
            cost = (s[-1]-s[-2])//2 # cost of making two equal
            s[0],s[1],s[2] = s[0]+cost,s[1]+cost,s[2]-cost
    if(s[0]==s[1] or s[1]==s[2]): # two number eq
        if((s[-1]-s[0])%2): 
            print(-1)
            continue
        else:
            if(s[0]==s[1]): cost +=((s[-1]-s[-2])//2)
            else: cost += s[1]-s[0]
    print(cost)
    