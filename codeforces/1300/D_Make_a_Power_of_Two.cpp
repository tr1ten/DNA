#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math") 
 
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
#define put(x) cout<<x<<endl;
#define put2(x,y) cout<<x<<" "<<y<<endl;
#define put3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define timed(x) {auto start = chrono::steady_clock::now(); x; auto end = chrono::steady_clock::now(); auto diff = end - start; cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;}

const LL MOD = 1e9+7;
const LL INF = 1e10+5;
const LL P2LIM = (LL)2e18;

int solve(string s, string t)
{
	int tp = 0;
	int sp = 0;
	int taken = 0;

	while (sp < s.length() && tp < t.length())
	{
		if(s[sp] == t[tp])
		{
			taken++;
			tp++;
		}
		sp++;
	}

	return (int)s.length() - taken + (int)t.length() - taken;
}

vector<string> ts;
// driver code
int main()
{
    for (LL p2 = 1; p2 <= P2LIM; p2 *= 2) ts.push_back(to_string(p2));

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const int MX = 100;
    int T ;
    cin>>T;
    while(T--){
        string s;
        cin >> s;
        int res = 1000;
        trav(tar,ts){
            // WA  not working for last test case :()
            mk_mat(dp,s.size()+1,tar.size()+1,1000);
            FOR(i,0,tar.size()) dp[s.size()][i] = tar.size()-i; // we can just add chars to right
            FOR(i,0,s.size()) dp[i][tar.size()] = s.size()-i; // we can remove chars from right
            dp[s.size()][tar.size()] = 0;
            ROF(i,0,s.size()){
                ROF(j,0,tar.size()){
                    if(s[i]==tar[j]) dp[i][j] = dp[i+1][j+1]; // no op
                    else dp[i][j] = dp[i+1][j]+1; // remove 
                }
            }
            // int j =0,i=0;
            // int taken = 0; // just be greedy and find tar as subseq in s
            // while(i<s.length() && j<tar.length()){
            //     if(s[i]==tar[j]){
            //         taken++;
            //         j++;
            //     }
            //     i++;
            // }
            res = min(res,dp[0][0] );
            // put3("res for k=",k,dp[0][0]);

        }
        put(res);
    }

    return 0;
}
