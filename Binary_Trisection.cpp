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
bool solve(int s_01,int s_10,int s_1,int s_010,int s_0){
    int odd = s_1 + s_010 + s_0;
    int mx = max({s_1,s_0,s_010});
    int mn = min({s_1,s_0,s_010});
    if(mn >= 1)return 1;
    int even = s_01 + s_10;
    if(odd == 0){
        int fin = s_10*2 + s_01*1;
        fin %= 3;
        if(fin)return 0;
        return 1;
    }
    else{
        if(even >= 2)return 1;
        if(odd == mx){
            int fin = odd&1;
            if(s_0)fin = 0;
            if(even){
                if(fin)return 1;
                return 0;
            }
            else{
                if(fin)return 0;
                return 1;
            }
        }
        if(odd-mx >= 2)return 1;
        if(!(odd&1)){
            if(even)return 1; 
            else return 0;
        }
        if(s_0 <= 1)return 1;
        else{
            if(even)return 1; 
            else return 0;
        }
    }
}
 
void testcase(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vi pref(n+1),p2(n+1);
    p2[0] =1;
    rep(i,0,n){
        pref[i+1] = (pref[i]*2%3 + (s[i]-'0'))%3;
        p2[i+1] = p2[i]*2%3;
    }

    int cnt[2][3]={0};
    rep(i,0,q){
        int l,r;
        cin >> l >> r;
        l--;r--;
        int rem = (pref[r+1]-pref[l]*p2[r-l+1]%3+3)%3;
        cnt[(r-l+1)%2][rem]++;
        put(solve(cnt[0][1],cnt[0][2],cnt[1][1],cnt[1][2],cnt[1][0]) ? "YES" : "NO")

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
