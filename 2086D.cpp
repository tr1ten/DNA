#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for (int i = (a); i < (b); i++)
typedef vector<int> vi;
const int MOD = 998244353;



int solve(int i,int cur, int x, vi &a,vector<vector<int>> &dp) {
    if(cur>x) return 0;
    if(i==a.size()) return cur==x;
    if(dp[i][cur]!=-1) return dp[i][cur];
    int ans = solve(i+1,cur,x,a,dp);
    if(cur+a[i]<=x){
        ans += solve(i+1,cur+a[i],x,a,dp);
        ans %=MOD;
    }
    return dp[i][cur]=ans;
}

const int N = 3*(1e5) + 5;
long long fact[N];
long long inv[N];
long long finv[N];

void pre() {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i-1]*i)%MOD;
    }
    inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    finv[0] = finv[1] = 1;
    for (int i = 2; i <= N; i++) {
        finv[i] = (inv[i]*finv[i-1])%MOD;
    }
}

long long nCk(int n,int k) {
    return (((fact[n]*finv[k])%MOD)*finv[n-k])%MOD;
}


void testcase() {
    int S = 0;
    int n = 26;
    vi c(n);
    vi a;
    rep(i, 0, n) cin >> c[i];
    
    rep(i, 0, n) {
        if (c[i]) {
            a.push_back(c[i]);
        }
    }
    
    rep(i, 0, a.size()) {
        S += a[i];
    }
    int target = S / 2;
    vector<vector<int>> dp(a.size(),vector<int>(target+1,-1));
    int cnt = solve(0,0,target,a,dp);
    int ans = cnt;
    ans = (ans * fact[target] % MOD * fact[S-target]%MOD) % MOD;
    int den = 1;
    rep(i, 0, a.size()) {
        den = (den * finv[a[i]]) % MOD;
    }
    ans = (ans * den) % MOD;
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    pre();
    int T = 1;
    cin >> T;
    while (T--) testcase();
    return 0;
}
