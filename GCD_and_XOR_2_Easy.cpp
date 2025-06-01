#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;

// Fast‐exponentiation (not actually used below, but kept for reference)
// long long fast_pow(long long a, long long b, long long m) {
//     a %= m;
//     long long res = 1;
//     while (b > 0) {
//         if (b & 1) res = (res * a) % m;
//         a = (a * a) % m;
//         b >>= 1;
//     }
//     return res;
// }

// Extended Euclidean to compute (x,y) with a·x + b·y = gcd(a,b)
long long binpow(long long a, long long b, long long m) {
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1)
            res = (__int128)res * a % m;
        a = (__int128)a * a % m;
        b >>= 1;
    }
    return res;
}
static pair<long long, pair<long long,long long>> extGCD(long long a, long long b) {
    if (b == 0) return {1, {0, a}};
    auto r = extGCD(b, a % b);
    long long x1 = r.first;
    long long y1 = r.second.first;
    long long d  = r.second.second;
    long long x = y1;
    long long y = x1 - (a / b) * y1;
    return {x, {y, d}};
}

// Return modular‐inverse of (a mod m), or –1 if it does not exist.
static long long modInv(long long a, long long m) {
    auto r = extGCD(a, m);
    long long x = r.first;
    long long d = r.second.second;
    if (d != 1) return -1;
    x %= m;
    if (x < 0) x += m;
    return x;
}

/*
  Count how many integers K satisfy:
      r1·K ≡ r2  (mod g),
  with 0 ≤ K ≤ T   (and if start==1 we also require K ≥ 1).
  
  In other words, we want all K in [start..T] such that
      (r1·K - r2) is a multiple of g.
  
  Let d = gcd(r1, g).  A solution exists only if d | r2.  Then
    r1' = r1/d,  r2' = r2/d,  g' = g/d
    => (r1'·K ≡ r2'  (mod g')).
  Since r1' and g' are coprime, find inv = (r1')⁻¹ mod g', and one particular solution is
        K0 = (inv·r2') mod g'.
  Then the general solution is K = K0 + k·g',  for integer k.  We need
        start ≤ K0 + k·g' ≤ T,
    so
        k ≥ ceil((start - K0)/g'),   k ≤ floor((T - K0)/g'),
    and we count how many integers k lie in that range.
*/
static long long countSolutions(long long r1, long long r2, long long g, long long e, int start=0) {
    long long d = std::gcd(r1, g);
    if (r2 % d != 0) return 0;
    r1 /= d;
    r2 /= d;
    long long gprime = g / d;

    long long inv = modInv(r1, gprime);
    if (inv < 0) return 0;

    long long K0 = (inv * r2) % gprime;
    if (K0 < 0) K0 += gprime;

    // We want K = K0 + k·gprime.  Impose start ≤ K ≤ T
    // => start ≤ K0 + k·gprime ≤ T
    // => k ≥ ceil((start - K0)/gprime),  k ≤ floor((T - K0)/gprime).
    if(e<=63){
        long long T = (1LL<<e)-1;
        long long k_max = (long long)floor(((long double)T - K0) / (long double)gprime);
        long long cnt = k_max - start + 1;
        if (cnt < 0) cnt = 0;
        return cnt;
    }
    K0 %=MOD;
    long long ginv = modInv(gprime,MOD);
    long long T= (binpow(2,e,MOD)-1)%MOD;
    long long kmax=  ((T-K0) - (T-K0)%gprime)*ginv%MOD;
    return (kmax - start+1+MOD)%MOD;
    

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        long long N, D;
        cin >> N >> D;

        // If D requires more than N bits, no solution is possible:
        int M = 63 - __builtin_clzll((unsigned long long)D); 
        // M = floor(log2(D)), so D fits in M+1 bits.
        M = M + 1;
        if (M > N) {
            cout << 0 << "\n";
            continue;
        }


        long long r1 = ((1LL << M) % D);                // r1 = 2^M mod D
        long long ans = 0;

        long long limit = (1LL << M);
        for (long long X_low = 0; X_low < limit; X_low++) {
            if ((X_low ^ D) != (X_low + D)) continue;

            long long r2 = (D - (X_low % D)) % D;
            int start = (X_low == 0 ? 1 : 0);

            ans += countSolutions(r1, r2, D, N-M, start);
            if (ans >= MOD) ans %= MOD;
        }

        cout << (ans % MOD) << "\n";
    }

    return 0;
}