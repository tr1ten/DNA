def fast_pow(a, b, m):
    if b == 0:
        return 1
    if b == 1:
        return a % m
    if b % 2 == 0:
        return fast_pow(a * a % m, b // 2, m)
    else:
        return a * fast_pow(a * a % m, b // 2, m) % m

def fact(n,m):
    if n == 0:
        return 1
    return n * fact(n-1,m) % m

def gcd(a,b):
    if b == 0:
        return a
    return gcd(b, a % b)

    


MOD = (10**9) + 9
P = 31
def rabin(s):
    n = len(s);
    pp = [1]*n
    pinv = [1]
    for i in range(1,n): 
        pp[i] = (pp[i-1]*P)%MOD
        pinv.append(fast_pow(pp[i],MOD-2,MOD));
    hash = [0]*(n+1) # 1 index hash
    for i in range(n): hash[i+1] = (hash[i] + ((ord(s[i])-ord('a')+1)*pp[i])%MOD )%MOD
    return hash,pp,pinv

def sub_hash(i,j,hash,pinv):
    return ((hash[j+1]-hash[i])*pinv[i])%MOD
