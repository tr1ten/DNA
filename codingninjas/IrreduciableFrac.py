import math
def convertToIrreducible(integerPart, fractionalPart):
	i = int(integerPart)
	n = len(fractionalPart)
	f = int(fractionalPart)
	A = i*(10**n)+f
	B=10**n
	k=math.gcd(A,B)
	while k>1:
		A=A//k
		B=B//k
		k=math.gcd(A,B)
	return A,B