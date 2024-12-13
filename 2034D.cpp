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
    int n;
    cin >>n;
    vi a(n);
    tkv(a,n);
    int z0 = count(all(a),0);
    int z1 = count(all(a),1);
    int z2 = n-z0-z1;
    vi b[3][3];
    rep(i,0,z0){
        b[0][a[i]].push_back(i);
    }
    rep(i,z0,z0+z1){
        b[1][a[i]].push_back(i);
    }
    rep(i,z0+z1,n){
        b[2][a[i]].push_back(i);
    }
    vector<pi> res;
    while(b[1][2].size() || b[1][0].size()){
        if(b[1][2].size()) {
            if(b[2][1].size()){
                res.push_back({b[1][2].back(),b[2][1].back()});
                b[1][2].pop_back();
                b[2][1].pop_back();
            }
            else if(b[0][1].size()){
                int i = b[0][1].back();
                int j = b[1][2].back();
                int k = b[2][0].back();
                res.push_back({i,k});
                res.push_back({k,j});
                b[1][2].pop_back();
                b[0][1].pop_back();
                b[2][0].pop_back();
            }
            else assert(0);
        }
        else if(b[1][0].size()) {
            if(b[0][1].size()){
                res.push_back({b[1][0].back(),b[0][1].back()});
                b[1][0].pop_back();
                b[0][1].pop_back();
            }
            else if(b[0][2].size()){
                int i = b[0][2].back();
                int j = b[1][0].back();
                int k = b[2][1].back();
                res.push_back({i,k});
                res.push_back({i,j});
                b[1][0].pop_back();
                b[0][2].pop_back();
                b[2][1].pop_back();
            }
            else assert(0);
        }
    }
    if(b[0][2].size()){
        int i1 = z0;
        int i2 = b[0][2].back();
        b[0][2].pop_back();
        res.push_back({i2,i1});
        i1 = i2;
        while ( b[2][0].size())
        {
            int i0 = b[2][0].back();
            b[2][0].pop_back();
            res.push_back({i1,i0});
            i1 = i0;
            if(b[0][2].size()){
                int i2 = b[0][2].back();
                b[0][2].pop_back();
                res.push_back({i1,i2});
                i1 = i2;
            }
        }
        res.push_back({i1,z0});
    }
    assert(res.size()<=n);
    put(res.size());
    for(auto &x:res){
        swap(a[x.first],a[x.second]);
        cout << x.first+1 << " "<< x.second+1<< endl;
    }
    rep(i,1,n){
        assert(a[i]>=a[i-1]);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    cin>>T;
    while(T--) testcase();

    return 0;
}
