import sys

import math as mt
MAXN = 10**6 + 5

spf = [i for i in range(MAXN)]
def sieve():
	spf[1] = 1

	for i in range(4, MAXN, 2):
		spf[i] = 2

	for i in range(3, mt.ceil(mt.sqrt(MAXN))):
		if (spf[i] == i):
			
			for j in range(i * i, MAXN, i):
				
				if (spf[j] == j):
					spf[j] = i
def factors(x):
	ret = set()
	while (x != 1):
		ret.add(spf[x])
		x = x // spf[x]

	return ret
sieve()
from collections import defaultdict,Counter
# input
t = int(sys.stdin.readline())
# input procsessing
for _ in range(t):
    n = int(input())
    A = list(map(int,input().split()))
    A.sort(reverse=True)
    cnt = Counter()
    fact = defaultdict(list)
    for x in A:
        cnt[x] +=1
        for f in factors(x):
            fact[f].append(x)
    for x in fact: fact[x].sort(reverse=True)
    q = int(input())
    B  = (map(int,input().split()))
    for x in B:
        mn = float('inf')
        for f in factors(x):
            while(fact[f] and cnt[fact[f][-1]]==0 ): fact[f].pop();
            if(fact[f]): 
                mn = min(mn,fact[f][-1])
        if(mn!=float('inf')):
            print(mn,end=" ")
            cnt[mn] -=1;
        else:
            while(A and cnt[A[-1]]==0): A.pop()
            print(A[-1],end=" ")
            cnt[A[-1]]-=1
            A.pop();
    print()
    
            
            
            
    