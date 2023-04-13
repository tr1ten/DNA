import math as mt
MAXN = 10**5 + 5

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
x = 12
print("prime factorization for", x, ": ",
								end = "")
import math
def factors2(x):
    ret = set()
    if(x==1): return ret
    for i in range(2,int(math.sqrt(x))+1):
        if((x%i)==0):
            ret.add(i)
            while(x%i==0): x //=i
    if(x>1): ret.add(x)
    return ret
# calling getFactorization function
p = factors2(x)
print([factors2(x) for x in [20,24,1000,1] ])