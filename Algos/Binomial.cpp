
typedef long long ll;
const ll MOD = 1e9+7;
const int N = 1e6+5;
ll facts[N+1];
ll invs[N+1];
ll fast_pow(ll x,ll n,ll m){
    x = x%m;
    ll res = 1;
    while (n>0)
    {
        if(n%2==1) res = (res*x)%m; 
        x = x*x%m;
        n /=2;
    }
    return res;
}
void factorials(){
    facts[0] = 1;
    for(int i=1;i<=N;i++) facts[i] = facts[i-1]*i%MOD;
}


void inverses(){
    invs[N] = fast_pow(facts[N],MOD-2,MOD);
    for(int i=N-1;i>=0;i--) invs[i] = invs[i+1]*(i+1)%MOD;
}

ll ncr(int n,int r){
    return (((facts[n]*invs[n-r])%MOD)*invs[r])%MOD;
}

void preprocess(){
    factorials();
    inverses();
}

int main(int argc, char const *argv[])
{
    preprocess();
    // std::cout << ncr(5,2) ; // 10
    return 0;
}

