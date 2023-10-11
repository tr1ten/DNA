#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define mk_mat(name,n,m,value) vii name(n, vi(m, value))


typedef long long ll; 
typedef vector<ll> vi;
typedef vector<vi> vii;

const ll MOD = 1e9+7;
vii mul(vii m1,vii m2){
    ll n=m1.size(),m=m1[0].size(),x=m2[0].size();
    mk_mat(res,n,x,0);
    rep(i,0,n){
        rep(j,0,x){
            rep(k,0,m){
                res[i][j] = (res[i][j] + (m1[i][k]*m2[k][j])%MOD)%MOD;   
            }
        }
    }
    return res;
}
vii fast_pow(vii a,ll b){

    if(b==0) {
        mk_mat(res,a.size(),a[0].size(),0);
        rep(i,0,a.size()) res[i][i] = 1;
        return res;
    }
    if(b==1) return a;
    if(b%2==0){
        return fast_pow(mul(a,a),b/2);
    }
    else{
        return mul(a,fast_pow(mul(a,a),b/2));
    }
}


ll fib(ll n,ll a,ll b,vii &P){
    n -=2;
    auto Pn = fast_pow(P,n);
    vii S0 =  {
    {b},{a}
    };
    return mul(Pn,S0)[0][0];
}
int main(int argc, char const *argv[])
{
    int a,b,c,d,N;
    cin >> a >> b >>c >> d >> N;
    vii P = {
        {a,b},
        {1,0}
    };
    cout << fib(N,c,d,P);
    return 0;
}
