#include <iostream>
#include <climits>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unordered_map>
#include <cstdio>
#include <cstring>
#include <numeric>
using namespace std;
 
#define ll long long
#define all(cont) cont.begin(), cont.end()
#define frEach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fr(i, a, b) for (ll i=a ; i<=b ; i++)
#define rfr(i, a, b) for (ll i=a ; i>=b ; i--)
#define pb push_back
#define INF (int)1e9+1
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
typedef vector<ll> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
// const int N = 2e5+7;
// ll ar[N];
// ll seg_tree[4*N];
// ll lazy[4*N];

// // array to store inverse of 1 to N
// ll factorialNumInverse[N + 1];
 
// // array to precompute inverse of 1! to N!
// ll naturalNumInverse[N + 1];
 
// // array to store factorial of first N numbers
// ll fact[N + 1];
 
// // Function to precompute inverse of numbers
// void InverseOfNumber(ll p)
// {
//     naturalNumInverse[0] = naturalNumInverse[1] = 1;
//     for (int i = 2; i <= N; i++)
//         naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
// }
// // Function to precompute inverse of factorials
// void InverseOfFactorial(ll p)
// {
//     factorialNumInverse[0] = factorialNumInverse[1] = 1;
 
//     // precompute inverse of natural numbers
//     for (int i = 2; i <= N; i++)
//         factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
// }
 
// // Function to calculate factorial of 1 to N
// void factorial(ll p)
// {
//     fact[0] = 1;
 
//     // precompute factorials
//     for (int i = 1; i <= N; i++) {
//         fact[i] = (fact[i - 1] * i) % p;
//     }
// }
 
// // Function to return nCr % p in O(1) time
// ll Binomial(ll N, ll R, ll p)
// {
//     // n C r = n!*inverse(r!)*inverse((n-r)!)
//     ll ans = ((fact[N] * factorialNumInverse[R])
//               % p * factorialNumInverse[N - R])
//              % p;
//     return ans;
// }

// void pushdown(ll pos, ll beg, ll end){
//     if(lazy[pos]>0){
//         seg_tree[pos] += (end-beg+1)*(lazy[pos]);
//         if(beg!=end){
//             lazy[2*pos+1] += lazy[pos];
//             lazy[2*pos+2] += lazy[pos];
//         }
//         lazy[pos]=0;
//     }
// }

// void lazy_update(ll beg, ll end, ll l, ll r, ll val, ll pos){
//     pushdown(pos,beg,end);
//     if(beg>=l && end<=r){
//         lazy[pos]+=val;
//         pushdown(pos,beg,end);
//         return;
//     }
//     if(beg>r || end<l) return;
//     int mid = beg+(end-beg)/2;
//     lazy_update(beg,mid,l,r,val,2*pos+1);
//     lazy_update(mid+1,end,l,r,val,2*pos+2);
//     seg_tree[pos] = seg_tree[2*pos+1]+seg_tree[2*pos+2];
// }

// void build_segment_tree(ll beg, ll end, ll pos){
//     if(beg==end){
//         seg_tree[pos] = ar[beg];
//         // lazy[pos]=0;
//         return;
//     }
//     ll mid = beg+(end-beg)/2;
//     build_segment_tree(beg,mid,2*pos+1);
//     build_segment_tree(mid+1,end,2*pos+2);
//     seg_tree[pos] = max(seg_tree[2*pos+1],seg_tree[2*pos+2]);
//     // lazy[pos]=0;
// }

// void update(ll beg, ll end, ll idx, ll val, ll pos){
//     if(beg==end){
//         seg_tree[pos] = val;
//         return;
//     }

//     int mid = beg+(end-beg)/2;
//     if(idx<=mid){
//         update(beg,mid,idx,val,2*pos+1);
//     }
//     else{
//         update(mid+1,end,idx,val,2*pos+2);
//     }
//     seg_tree[pos] = max(seg_tree[2*pos+1],seg_tree[2*pos+2]);
// }

// ll query(ll beg, ll end, ll l, ll r, ll pos){
//     // pushdown(pos,beg,end);
//     if(l>r) return 0;
//     if(beg>=l && end<=r) return seg_tree[pos];
//     else if(beg>r || end<l) return 0;
//     ll mid = beg+(end-beg)/2;
//     return max(query(beg,mid,l,r,2*pos+1),query(mid+1,end,l,r,2*pos+2));
// }

// int diameter_of_tree(int n, vector<vector<int>>& tree) {
//     vector<int> leaves;
//     vector<int> degree(n);
//     for(int i=0;i<n;i++){
//         degree[i] = tree[i].size();
//         if(degree[i]==1 || degree[i]==0){
//             leaves.push_back(i);
//             degree[i] = 0;
//         }
//     }
//     int diameter = 0;
//     int cnt = leaves.size();
//     while(cnt<n){
//         vector<int> new_leaves;
//         for(int i=0;i<leaves.size();i++){
//             for(int j=0;j<tree[leaves[i]].size();j++){
//                 degree[tree[leaves[i]][j]]--;
//                 if(degree[tree[leaves[i]][j]]==1) {
//                     new_leaves.push_back(tree[leaves[i]][j]);
//                     degree[tree[leaves[i]][j]]= 0;
//                 }
//             }
//         }
//         leaves = new_leaves;
//         cnt += leaves.size();
//         diameter += 2;
//     }
//     if(leaves.size()==2) diameter++;
//     return diameter;
// }

// vector<int> centre_of_tree(int n,vector<vector<int>>& tree){
//     vector<int> leaves;
//     vector<int> degree(n);
//     for(int i=0;i<n;i++){
//         degree[i] = tree[i].size();
//         if(degree[i]==1 || degree[i]==0){
//             leaves.push_back(i);
//             degree[i] = 0;
//         }
//     }
//     int diameter = 0;
//     int cnt = leaves.size();
//     while(cnt<n){
//         vector<int> new_leaves;
//         for(int i=0;i<leaves.size();i++){
//             for(int j=0;j<tree[leaves[i]].size();j++){
//                 degree[tree[leaves[i]][j]]--;
//                 if(degree[tree[leaves[i]][j]]==1) {
//                     new_leaves.push_back(tree[leaves[i]][j]);
//                     degree[tree[leaves[i]][j]]= 0;
//                 }
//             }
//         }
//         leaves = new_leaves;
//         cnt += leaves.size();
//         diameter += 2;
//     }
//     return leaves;
// }

// vector<ll> dijkstra_algo(ll N, vector<vector<pair<ll,ll>>>& graph, ll src){
//     priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;
//     vector<ll> dist(N, LLONG_MAX);
//     pq.push(make_pair(0, src));
//     dist[src] = 0;
//     vector<ll> visited(N,0);
//     while (!pq.empty()) {
//         ll u = pq.top().second;
//         pq.pop();
//         if(visited[u]) continue;
//         visited[u]=1;
//         for (pair<ll,ll> neighbour:graph[u]) {
//             ll v = neighbour.first;
//             ll weight = neighbour.second;
//             if (dist[v] > dist[u] + weight) {
//                 dist[v] = dist[u] + weight;
//                 pq.push(make_pair(dist[v], v));
//             }
//         }
//     }
//     return dist;
// }

// void floyd_algo(ll n, vector<vector<ll>>& dist) {
//     for(ll i=0;i<n;i++){
//         for(ll j=0;j<n;j++){
//             for(ll k=0;k<n;k++){
//                 if(dist[j][i]!=LLONG_MAX && dist[i][k]!=LLONG_MAX && dist[j][k]>dist[j][i]+dist[i][k]){
//                     dist[j][k] = dist[j][i]+dist[i][k];
//                 }
//             }
//         }
//     }
// }

// vector<bool> primes(1e6+1,true);
// void sieve(){
//     primes[0] = false;
//     primes[1] = false;
//     for(ll i=2;i<=1e6;i++){
//         if(primes[i]){
//             for(ll j=i*i;j<=1e6;j+=i){
//                 primes[j] = false;
//             }
//         }
//     }
// }

// ll modularExponentiation(ll a, ll b, ll m){
//     if(b==0) return 1;

//     ll p = modularExponentiation(a,b/2,m)%m;
//     p = (p*p) % m;
//     return b%2 ? (a * p) % m : p;
// }

// void heightOfTree(vector<vector<int>>& tree, int idx, vector<int>& h, int p=-1){
//     for(int child:tree[idx]){
//         if(child==p) continue;
//         heightOfTree(tree,child,h,idx);
//         h[idx] = max(h[idx],1+h[child]);
//     }
// }
 
// void dfs2(vector<vector<int>>& tree, int idx, vector<int>& h, vector<int>& ans, int distUp, int p=-1){
//     ans[idx] = max(h[idx],distUp);
//     int maxi=0, sec_maxi=0;
//     for(int child:tree[idx]){
//         if(child==p) continue;
//         if(maxi<1+h[child]){
//             sec_maxi = maxi;
//             maxi = 1+h[child];
//         }
//         else if(sec_maxi < 1+h[child]){
//             sec_maxi = 1+h[child];
//         }
//     }
//     for(int child:tree[idx]){
//         if(child==p) continue;
//         if(h[child]+1==maxi){
//             dfs2(tree,child,h,ans,max(distUp,sec_maxi)+1,idx);
//         }
//         else{
//             dfs2(tree,child,h,ans,max(distUp,maxi)+1,idx);
//         }
//     }
// }
 
// vector<int> max_distance_from_all_nodes(int n, vector<vector<int>>& tree){
//     vector<int> ans(n);
//     vector<int> h(n);
//     heightOfTree(tree, 0, h);
//     dfs2(tree, 0, h, ans, 0);
//     return ans;
// }

ll gcd(ll a, ll b) 
{ 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
} 
  
ll lcm(ll a, ll b) 
{ 
    return (a / gcd(a, b)) * b; 
}

// ll help(vector<ll>& a, vector<ll>& b, ll idx, ll rem_glasses, ll capacity_collected, ll ans, ll total, vector<vector<vector<ll>>>& dp) {
//     ll n = a.size();
//     if(idx==n) return ans+min((2*total-ans)/2,capacity_collected);
//     if(dp[idx][rem_glasses][capacity_collected]!=-1) return dp[idx][rem_glasses][capacity_collected];

//     ll output = help(a,b,idx+1,rem_glasses,capacity_collected,ans,total,dp);
//     if(rem_glasses>0) {
//         output = max(output,help(a,b,idx+1,rem_glasses-1,capacity_collected+2*(a[idx]-b[idx]),ans+2*b[idx], total,dp));
//     }
//     return dp[idx][rem_glasses][capacity_collected] = output;
// }

void solve() {
    // ll n;
    // cin >> n;
    // vector<ll> a(n);
    // vector<ll> b(n);
    // fr(i,0,n-1) cin >> a[i] >> b[i];
    // ll total = accumulate(b.begin(),b.end(),0);
    // vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(n+1,vector<ll>(200*n,-1)));
    // fr(i,1,n) {
    //     cout << help(a,b,0,i,0,0,total,dp)*1.0/2 << " ";
    // }
    // cout << endl;
    
    ll n;
    cin >> n;
    vector<ll> a(n);
    fr(i,0,n-1) cin >> a[i];
    vector<ll> temp;
    fr(i,0,n-1) temp.pb(a[i]);
    sort(temp.begin(),temp.end());
    unordered_map<ll,ll> mp;
    unordered_map<ll,ll> mp2;
    fr(i,0,n-1) {
        if(!mp.count(temp[i])) mp[temp[i]] = i;
        mp2[temp[i]] = i;
    }
    ll val = 0;
    priority_queue<ll,vector<ll>,greater<ll>> p;
    priority_queue<ll> p2;
    vector<ll> ff(n);
    vector<ll> gg(n);
    fr(i,0,n-1) {
        if(a[i]==temp[i]) ff[i]=1;
        if(i!=0 && ff[i]==1) ff[i] += ff[i-1];
    }
    rfr(i,n-1,0) {
        if(a[i]==temp[i]) gg[i]=1;
        if(i!=n-1 && ff[i]==1) gg[i] += gg[i+1];
    }
    ll ans = n*n;
    fr(i,0,n-1) {
        p.push(mp[a[i]]);
        mp[a[i]]++;
        while(!p.empty() && p.top()==val) {
            p.pop();
            val++;
        }
        // cout << i << " " << val << " " << (i+1)*(i+1) + (n-val)*(n-val) << endl;
        ll uu = n-val;
        if(val==i+1 && i!=n-1) uu-=gg[i+1];
        ans = min(ans,(i+1)*(i+1) + (uu)*(uu));
    }
    val = n-1;
    rfr(i,n-1,0) {
        p2.push(mp2[a[i]]);
        mp2[a[i]]--;
        while(!p2.empty() && p2.top()==val) {
            p2.pop();
            val--;
        }
        // cout << i << " " << val << " " << val*val + (n-i)*(n-i) << endl;
        ll uu = val+1;
        if(val==i-1 && i!=0) uu-=ff[i-1];
        ans = min(ans,(uu)*(uu) + (n-i)*(n-i));
    }
    cout << ans << endl;
}
 
int main(){
    // ifstream in("in.txt");
    // streambuf *cinbuf = std::cin.rdbuf();
    // cin.rdbuf(in.rdbuf());
    
    // ofstream out("out.txt");
    // streambuf *coutbuf = std::cout.rdbuf();
    // cout.rdbuf(out.rdbuf());
    // sieve();
    int t=1;
    // cin >> t; 
    // InverseOfNumber(MOD);
    // InverseOfFactorial(MOD);
    // factorial(MOD);
    while(t--){
        solve();
    }
    return 0;
}
 