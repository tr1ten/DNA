    #include <bits/stdc++.h>
    using namespace std;
    #define ss second
    #define ff first
    #define int long long
    #define rep(i,a,b) for (int i = (a); i < (b); i++)
    #define per(i,a,b) for (int i = (b)-1; i >= (a); i--)
    #define tkv(vec,sz) rep(i,0,sz) cin>>vec[i]
    #define srv(vec) sort(vec.begin(), vec.end())
    #define all(x) x.begin(), x.end()
    #define pvc(vec) for(auto x:vec) cout<<x<<" "; cout<<endl;
    #define put(x) cout << (x)<< endl;
    typedef vector<int> vi;
    typedef vector<vi> vii;
    typedef pair<int,int> pi;
    inline int ctz(int x) { return __builtin_ctzll(x);}
    inline int pc(int x) {return  __builtin_popcount(x);} 
    inline int hset(int x) {return __lg(x);}
    /*
        NOT use unordered map use map
        NOT use seg tree use fenwick tree
        THINK before you code
    */

    const int MOD = 1e9+7; // change me for god sake look at problem mod
    const int INF = 1e16+5;

    void testcase(){
        int n,m;
        cin >> n >> m;
        vector<string> mat(n);
        rep(i,0,n){
            cin >> mat[i];
        }
        vector<int> fs(n),ls(n,m+1);
        vii dp(n,vi(2));
        int last = n-1;
        per(i,0,n){
            rep(j,0,m+2){
                if(mat[i][j]=='1' ) {
                    if(fs[i]==0) fs[i] = j;
                    ls[i] = j;    
                }

            }
            if(i==n-1){
                dp[i][0] = ls[i];
                dp[i][1] = INF;
            }
            else {
                last = i;
                dp[i][0] = min(dp[i+1][0] + (ls[i+1]), dp[i+1][1]+fs[i+1])+1+ls[i];
                dp[i][1] = min(dp[i+1][0] + (m+1-ls[i+1]), dp[i+1][1]+m+1-fs[i+1])+1+m+1-fs[i];
            }
        }   
        put(min(dp[last][0],dp[last][1]));

    }
    int32_t main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        // freopen("input.in","r",stdin);
        // freopen("output.out","w",stdout);      
        int T=1;
        while(T--) testcase();

        return 0;
    }
