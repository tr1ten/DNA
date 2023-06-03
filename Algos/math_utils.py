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

    


MOD = (10**9) + 7
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

MOD = (10**9) + 7
P = 31
MAXN = 10**5+ 3;
pp = [1]
def code(x):  # return unsigned int representation of key
    return ord(x)-ord('a') + 1 
def powers():
    for i in range(len(pp),MAXN):
        pp.append((pp[-1]*P)%MOD)
def hash(s): # hash using a0*P^(k-1) + a1*P^(k-2) ...
    n = len(s)
    h = 0
    for i in range(n):
        h = (h + (code(s[i]))*pp[n-i-1])%MOD
    return h
def rolling_hash(old_hash,k,prev,next):
    return (((old_hash + MOD-(code(prev))*(pp[k-1]))*P)%MOD + code(next))%MOD
powers()
# N
# substring search nlogn
def substr(s,p):
    tar = hash(p)
    k = len(p)
    old = hash(s[:k])
    if old==tar: return 0
    for i in range(k,len(s)):
        old = rolling_hash(old,k,s[i-k],s[i])
        if old==tar: return i-k+1
    return -1
print(substr("01234","234"));