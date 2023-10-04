#include <bits/stdc++.h>
    #include <math.h>
 
    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    # define M_PI  3.14159265358979323846
 
 
    const int M=1e9+7;
    long long mod(long long x){
        return ((x%M + M)%M);
    }
    long long add(long long a, long long b){
        return mod(mod(a)+mod(b));
    }
    long long mul(long long a, long long b){
        return mod(mod(a)*mod(b));
    }
 
    vector<ll>val;
    vector<vector<ll>>adj;
    ll n;
    
    ll dfs(ll u, ll p){
        ll ans=1;
        for(auto v : adj[u]){
            if(v!=p){
                ll nt=dfs(v,u);
                val.push_back(nt*(n-nt));
                ans+=nt;
            }
        }
        return ans;
    }
 
    void solve(){
        cin>>n;
        val.clear();
        adj=vector<vector<ll>>(n);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0LL,-1LL);
        sort(val.begin(),val.end(),greater<ll>());
        int m;
        cin>>m;
        vector<ll>fact(m);
        for(int i=0;i<m;i++)
            cin>>fact[i];
        for(int i=m;i<n-1;i++)
            fact.push_back(1LL);
        sort(fact.begin(),fact.end(),greater<ll>());
        ll ans=0;
        if((ll)fact.size()==n-1){
            for(int i=0;i<n-1;i++){
                ans=add(ans,(ll)(mul(fact[i],val[i])));
            }
        }
        else{
            ll z=fact.size()-(n-1);
            int x=0;
            for(ll i=0;i<(ll)fact.size();i++){
                if(i<(z))
                    fact[i+1]=mul(fact[i],fact[i+1]);
                else
                    ans=add(ans,(ll)(mul(fact[i],val[x++])));
            }
        }
        cout<<ans<<"\n";
    }
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout<<fixed;
        cout<<setprecision(10);
//        freopen("timber_input.txt", "r", stdin);
//        freopen("timber_output.txt", "w", stdout);
        int t=1;
        cin>>t;
        for(int i=1;i<=t;i++){
//            cout<<"Case #"<<i<<": ";
            solve();
        }
        return 0;
    }