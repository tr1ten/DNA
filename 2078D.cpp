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
    cin >> n;
    vector<pair<char,int>> l1(n),l2(n);
    rep(i,0,n){
        cin >> l1[i].first >> l1[i].second;
        cin >> l2[i].first >> l2[i].second;
    }
    int l=1,r=1;
    rep(i,0,n){
        int inc = 0;
        if(l1[i].first=='+') inc+=l1[i].second;
        else inc += (l1[i].second-1)*l;
        if(l2[i].first=='+') inc+=l2[i].second;
        else inc += (l2[i].second-1)*r;
        int j = i+1;
        while (j<n && ( ((l1[j].first=='+') && (l2[j].first=='+')) || (((l1[j].first!='+') && (l2[j].first!='+') && l1[j].second==l2[j].second)) ))
        {
            j++;
        }
        if(j<n){
            if((l1[j].first=='+' || (l2[j].first!='+' && l2[j].second>l1[j].second))) r+=inc;
            else l+=inc;
        }
        else l+=inc;
        // cout  << l << " " << r << endl;
    }
    put(l+r);
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
