import sys

MAX = 10**5+1
def sieves():
    primes = [True]*MAX
    for i in range(2,MAX):
        if(not primes[i]): continue
        for j in range(i*i,MAX,i):
            primes[j] = False
    only_primes = [i for i in range(2,MAX) if(primes[i])]
    return only_primes  
    

# input
t = int(sys.stdin.readline())
PRIMES = sieves()

# solve here
def solve(L,R):
    if(L==1): L+=1
    range_primes = [True]*(R-L+1)
    for p in PRIMES:
        if(p*p>R): break 
        base_val = (L//p)*p
        if(base_val<L): base_val += p
        for j in range(base_val,R+1,p):
            range_primes[j-L] = False 
        if(base_val==p): range_primes[base_val-L] = True
    only_prime = [i+L for i in range(0,R-L+1) if range_primes[i]]
    return only_prime

# input processing
for _ in range(t):
    L,R = (map(int, sys.stdin.readline().split()))
    output = solve(L,R)
    sys.stdout.writelines("\n".join([str(x) for x in output]))
    print()