#include<bits/stdc++.h>
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all(v) v.begin(),v.end()
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD=1e9+7;      // Hardcoded, directly change from here for functions!
 
 
 
void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================
// ========================================MATH UTIL BEGINS==============================================
//==================================== compute higher powers with mod ===================================
uint power(int x, int y, int p =  MOD)
{
    unsigned long long res = 1;
 
    x = x % p;
    while (y > 0)
    {
 
        if (y & 1)
            res = (res * x) % p;
 
        y = y >> 1;
        x = (x * x) % p;
    }
    return res%p;
}
 
// =============================================================================================================
 
uint modInverse(int n, int p=MOD)       // using fermats little thm. [p needs to be prime which is mostly the case as mod value generally is 1e9+7]
{
    return power(n, p - 2, p);
}
// can also derive this using extended euclidean... however this has a much simpler code....
 
vector<int> fac;
// =========================================Used to calculate nCr of higher values ===================================
uint nCr(int n, int r, int p=MOD)     // faster calculation.. 
{
    if (n < r)
        return 0;
 
    if (r == 0)
        return 1;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
// ==================================== MATH UTIL ENDS=======================================================//
 
int ans;
int dfs(int node, vvi& g,int n,int k,int p=-1){
    int chc=0;
    int bad=0;
    for(auto& ch:g[node]){
        if(ch==p)   continue;
        int v=dfs(ch,g,n,k,node);
        chc+=v;
        if(v>=k){
            bad+=nCr(v,k);      // all at 1 place. 
            bad%=MOD;
        }
    }
    int par=n-chc-1;
    if(par>=k) bad+=nCr(par,k);     // all k in parent. 
    bad%=MOD;
    int tot=nCr(n,k);
    int good=(tot%MOD-bad%MOD+MOD)%MOD;
    ans+=good;
    ans%=MOD;
    chc+=1;                                 // self
    return chc;
 
}
void solve(){
    ans=0;
    fac.assign(200005,0);
    fac[0] = 1;
    for (int i = 1; i <= 2e5+4; i++)
        fac[i] = (fac[i - 1] * i) % MOD;
    int n=1,k=0;
    cin>>n>>k;
    int e=n-1;
    vector<vector<int>> g(n+1);
    vector<int> indeg(n+1,0);
    for(int i=1;i<=e;i++){
      int u,v; cin>>u>>v;
      g[u].push_back(v);
      g[v].push_back(u);
         indeg[u]++;
         indeg[v]++;
    }
    int leaf=-1;
    for(int i=1;i<=n;i++){
        if(indeg[i]==1){        // leaf
            leaf=i;
            break;
        }
    }
    if(k!=2){
        cout<<"1\n";
        return;
    }
    dfs(leaf,g,n,k,-1);
    int res=(ans*modInverse(nCr(n,k)));
    // cout<<ans<<'\n';
    // cout<<modInverse(ncr(n,k))<<"\n";
    res%=MOD;
    cout<<res<<"\n";
    
}
// driver code
int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}
