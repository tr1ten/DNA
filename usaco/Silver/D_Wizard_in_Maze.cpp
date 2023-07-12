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

struct el
{
    int p;
    int y;
    int x;
    // bool operator<(el &b){
    //     return this->p < b.p;
    // }
};

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--){
        int h,w,cw,ch,dw,dh;
        cin >> h >> w;
        cin >> ch >> cw;
        cin >> dh >> dw;
        ch--;cw--;dh--;dw--;
        bool mat[h][w];
        rep(i,0,h){
            string row;
            cin >> row;
            rep(j,0,w){
                mat[i][j] = row[j]=='.';
            }
        }
        auto less = [&](const el &a,const el &b){
            return a.p > b.p;
        };
        priority_queue<el,vector<el>,decltype(less)> pq(less);
        mk_mat(dist,h,w,INF);
        pq.push({0,ch,cw});
        dist[ch][cw] =0;
        bool f =0;
        int dk[6] = {-2,-1,0,1,2};
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            if(p.p > dist[p.y][p.x]) continue;
            if(p.x==dw && p.y==dh) {
                put(p.p);
                f = 1;
                break;
            }
            rep(i,0,5){
                rep(j,0,5){
                    int ex = !((dk[i]==0 && abs(dk[j])<=1 )|| (dk[j]==0 && abs(dk[i])<=1));
                    int y = p.y+dk[i],x = p.x+dk[j];
                    if(y<0 || x<0 || y>=h || x>=w || !mat[y][x]) continue;
                    if(dist[y][x] > p.p+ex){
                        dist[y][x] = p.p + ex;
                        pq.push({p.p+ex,y,x});
                    }
                }
            }
        }
            if(!f) put(-1)
        
    }

    return 0;
}
