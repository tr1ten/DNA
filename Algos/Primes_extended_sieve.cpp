#include <bits/stdc++.h>

using namespace std;
const int L = 1e5 + 5;
int sieve[L+1];
// find prime <sqrt(MAX)
// O(LlogL)
void preprocess(){
    sieve[0] = 1;
    sieve[1] = 1;
    for(int x=2;x*x<=L;x++){
        if(sieve[x]!=0) continue; 
        for(int u=2*x;u<=L;u +=x){
            sieve[u] = x;
        }
    }
}
const int N = 1e5 + 5; // max difference between l,r
int off_sieve[N];
// primes in range [l,r]
void rangePrime(long long l,long long r){
    memset(off_sieve,0,sizeof off_sieve);
    if(l==1) off_sieve[0] = 1;
    for(int x=2;x*x<=(r);x++){
        if(sieve[x]!=0) continue; 
        long long base = x*x; // start check from value near to l
        if(base<l) base = ((long long)ceil(l*1.0/x)*x);
        for(long long u=base;u<=r;u +=x){
            off_sieve[u-l] = x;
        }
    }
}
int main(){
    preprocess();
    int t;
    cin >> t;
    while(t--){
        long long l,r;
        cin >> l >> r;
        rangePrime(l,r);
        for(long long x=l;x<=r;x++){
            if(off_sieve[x-l]==0) cout << (x) << endl;
        }
        cout << endl;
    }
    return 0;
}
