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
typedef long long LL; 
typedef vector<LL> VI;
typedef vector<VI> VII;
typedef pair<LL,LL> PI;
typedef vector<PI> VPI;
typedef unordered_map<LL,LL> MII;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,a) FOR(i,0,a)
#define rep(N) FOR(i,0,N)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,arr) for (auto& a: (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name,sz,value) VI name(sz,value)
#define mk_mat(name,n,m,value) vector<vector<int>> name(n, vector<int>(m, value))
#define contains(x) find(x) != string::npos
#define take_vec(vec,sz) FOR(i,0,sz) cin>>vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a,b) a<b
#define vec_sum(vec) accumulate(vec.begin(), vec.end(), 0L);
#define vec_max(vec) *max_element(vec.begin(), vec.end());
#define vec_min(vec) *min_element(vec.begin(), vec.end());
#define put_vec(vec) trav(x,vec) cout<<x<<" "; cout<<endl;
#define put(x) cout<<(x)<<endl;
#define put2(x,y) cout<<(x)<<" "<<(y)<<endl;
#define put3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl;
#define take(x) cin >> x;
#define take2(x,y) cin >> x >> y;
#define take3(x,y,z) cin >> x >> y >> z;

#define timed(x) {auto start = chrono::steady_clock::now(); x; auto end = chrono::steady_clock::now(); auto diff = end - start; cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;}

const LL MOD = 1e9+7;
const LL INF = 1e10+5;

string add(string a,string b){
    int c = 0;
    reverse(all(a));
    reverse(all(b));
    string res;
    FOR(i,0,max(a.size(),b.size())){
        int sm= c + (i< a.size() ? (a[i]-'0') : 0) + (i<b.size() ? (b[i]-'0') : 0);
        res += to_string(sm%10);
        c = sm/10;
    }
    if(c) res=  res +  to_string(c);
    reverse(all(res));
    return res;
}

string sub(string a,string b){ // a>=b
    int br = 0;
    reverse(all(a));
    reverse(all(b));
    string res;
    FOR(i,0,a.size()){
        int cur = a[i]-'0' - br;
        br = 0;
        int other = i<b.size() ? b[i]-'0' : 0;
        if(cur<other) {cur+=10;br=1;}
        int sm= cur-other;
        res += to_string(sm%10);
    }
    while(res.size() && res.back()=='0') res.pop_back();
    reverse(all(res));
    return res;
}
bool lt(string &a,string &b){
    if(a.size()<b.size()) return true;
    if(a.size()>b.size()) return false;
    FOR(i,0,a.size()){
        if(a[i]>b[i]) return false;
    }
    return true;
}
string div(string a){
    int i = 0;
    string b = "2";
    string res;
    int c=0;
    while(i<a.size()){
        string cur = "";
        do{
            if(cur.size()>0 && res.size()) res.push_back('0');
            cur += a[i++];
        }
        while( i<a.size() && (atoi(cur.c_str())+c*10)<2);
        int sm = c*10 + atoi(cur.c_str());
        res += to_string(sm/2);
        c = sm%2;
    }
    return res;
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=10;
    // cin>>T;
    while(T--){
        string a,b;
        cin >> a;
        cin >> b;
        string sum = add(a,b);
        string y = div(sum);
        put(y);
        put(sub(y,b));

    }

    return 0;
}
