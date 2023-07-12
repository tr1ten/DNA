#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<typename T> 
using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// useful defs
typedef long long ll; 
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef unordered_map<ll,ll> mll;
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define per(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define trav(a,arr) for (auto& a: (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name,sz,value) vi name(sz,value)
#define mk_mat(name,n,m,value) vector<vi> name(n, vi(m, value))
#define contains(x) find(x) != string::npos
#define tkv(vec,sz) rep(i,0,sz) cin>>vec[i]
#define srv(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a,b) a<b
#define vsum(vec) accumulate(vec.begin(), vec.end(), 0L);
#define vmax(vec) *max_element(vec.begin(), vec.end());
#define vmin(vec) *min_element(vec.begin(), vec.end());
#define pvc(vec) trav(x,vec) cout<<x<<" "; cout<<endl;
#define put(x) cout<<(x)<<endl;
#define put2(x,y) cout<<(x)<<" "<<(y)<<endl;
#define put3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl;
#define mod(x) (x + MOD)%MOD
// debugging
#define timed(x) {auto start = chrono::steady_clock::now(); x; auto end = chrono::steady_clock::now(); auto diff = end - start; cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;}
void __print(auto x) {cerr << x;}
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; __print(x); cerr << endl;
#else
#define debug(x)
#endif
const ll MOD = 1e9+7;
const ll INF = 1e10+5;

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("split.in", "r", stdin);
    // freopen("split.out", "w", stdout);
    int T=1;
    // cin>>T;
    while(T--){
        int n;
        cin >> n;
        multiset<pi> xy;
        multiset<pi> yx;
        ll mxx=-INF,mxy=-INF,mnx=INF,mny=INF;
        rep(i,0,n){
            ll x,y;
            cin >> x >> y;
            mxx = max(mxx,x);
            mxy = max(mxy,y);
            mnx = min(mnx,x);
            mny = min(mny,y);
            xy.insert(mp(x,y));
            yx.insert(mp(y,x));
        }
        ll original = (mxx-mnx)*(mxy-mny);
        ll mns = INF;
        mxx=-INF,mxy=-INF,mnx=INF,mny=INF;
        auto rtv = xy.rbegin();
        vi suff(0);
        while(rtv!=xy.rend()){
            ll x=(*rtv).first,y=(*rtv).second;
            mxx = max(mxx,x);
            mxy = max(mxy,y);
            mnx = min(mnx,x);
            mny = min(mny,y); 
            suff.push_back((mxx-mnx)*(mxy-mny));
            rtv++;
        }
        auto it = xy.begin();
        mxx=-INF,mxy=-INF,mnx=INF,mny=INF;
        suff.pop_back();
        while (it!=--xy.end())
        {
            ll x=(*it).first,y=(*it).second;
            mxx = max(mxx,x);
            mxy = max(mxy,y);
            mnx = min(mnx,x);
            mny = min(mny,y); 
            ll area = ((mxx-mnx)*(mxy-mny));
            // debug(area);
            // debug(suff.back());
            mns = min(area+suff.back(),mns);
            suff.pop_back();
            it++;
        }
        mxx=-INF,mxy=-INF,mnx=INF,mny=INF;
        rtv = yx.rbegin();
        suff.clear();
        suff.push_back(0);
        while(rtv!=yx.rend()){
            ll x=(*rtv).first,y=(*rtv).second;
            mxx = max(mxx,x);
            mxy = max(mxy,y);
            mnx = min(mnx,x);
            mny = min(mny,y); 
            suff.push_back((mxx-mnx)*(mxy-mny));
            rtv++;
        }
        it = yx.begin();
        mxx=-INF,mxy=-INF,mnx=INF,mny=INF;
        suff.pop_back();
        while (it!=--yx.end())
        {
            ll x=(*it).first,y=(*it).second;
            mxx = max(mxx,x);
            mxy = max(mxy,y);
            mnx = min(mnx,x);
            mny = min(mny,y); 
            ll area = ((mxx-mnx)*(mxy-mny));
            // debug(area);
            // debug(suff.back());
            mns = min(area+suff.back(),mns);
            suff.pop_back();
            it++;
        }
        put(original-mns);
    }

    return 0;
}
