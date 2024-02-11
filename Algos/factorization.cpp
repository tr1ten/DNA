#include <bits/stdc++.h>
typedef short u16;
typedef long long u64;

using namespace std;
// show sqrt n simple method
// can find prime factorization of number in sqrt(n)/logn if we have all primes precall

int factors(int x){
    int res  = 0;
    if(x==1) return res;
    for(int i=2;i<sqrt(x)+1;i++){
        while (x%i==0)
        {
            res++;
            x /=i;
        }
        
    }
    if(x>1) res++;
    return res;
}
// fast method 
const int N = (1 << 2);

struct Precalc {
    u16 primes[4]; // # of primes under N=2^16

    constexpr Precalc() : primes{} {
        bool marked[N] = {};
        int n_primes = 0;

        for (int i = 2; i < N; i++) {
            if (!marked[i]) {
                primes[n_primes++] = i;
                for (int j = 2 * i; j < N; j += i)
                    marked[j] = true;
            }
        }
    }
};

constexpr Precalc P{};

u64 find_factor(u64 n) {
    for (u16 p : P.primes)
        if (n % p == 0)
            return p;
    return 1;
}
// can make it even more fast by not calling find factor again ang again
int factorize(int n) {
    
    if(n==1) return 0;
    int res = 0;
    int d;
    do {
        d = find_factor(n);
        res++;
        n /= d;
    } while (d != 1 && n>1);
    return res;
}
int main(int argc, char const *argv[])
{
    long long pp=1;
    for(auto x:P.primes){
        pp *=x;
        cout << pp << "\n";
    }
    return 0;
}
