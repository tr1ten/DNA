import math as mt

MAXN = 100001

spf = [0 for i in range(MAXN)]

def sieve():
	spf[1] = [i for i in range(MAXN)]

	for i in range(4, MAXN, 2):
		spf[i] = 2

	for i in range(3, mt.ceil(mt.sqrt(MAXN))):
		if (spf[i] == i):
			
			for j in range(i * i, MAXN, i):
				
				if (spf[j] == j):
					spf[j] = i

def getFactorization(x):
	ret = list()
	while (x != 1):
		ret.append(spf[x])
		x = x // spf[x]

	return ret

# Driver code

# precalculating Smallest Prime Factor
sieve()
x = 11
print("prime factorization for", x, ": ",
								end = "")

# calling getFactorization function
p = getFactorization(x)

for i in range(len(p)):
	print(p[i], end = " ")
