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
    string s;
    cin >> s;
    int n = s.size();
    int j = 0;
    while (j<=n-j-1 && s[j]==s[n-j-1])
    {
        j++;
    }
    if(j>=n-j-1){
        put(0);
        return;
    }
    int p= j;
    int lo=j,hi=n-j-1;
    int ans=INF;
    while (lo<=hi)
    {
        int mid = (lo+hi)/2;
        vector<int> cnt(26);
        rep(i,j,mid+1){
            cnt[s[i]-'a']++;
        }
        int ok = 1;
        rep(i,max(n-mid,mid+1),n-j){
            if(cnt[s[i]-'a']==0){
                ok = 0;
                break;
            }
            cnt[s[i]-'a']--;
        }
        // pvc(cnt);
        int i = mid+1;
        while (i<n-i-1)
        {
            if(s[i]!=s[n-i-1]){
                ok = 0;
                break;
            }
            i++;
        }
        if(ok){
            ans = min(ans,mid-j+1);
            hi = mid-1;
        }
        else {
            lo = mid+1;
        }
    }
    reverse(all(s));
    lo=j,hi=n-j-1;
    while (lo<=hi)
    {
        int mid = (lo+hi)/2;
        vector<int> cnt(26);
        rep(i,j,mid+1){
            cnt[s[i]-'a']++;
        }
        int ok = 1;
        rep(i,max(n-mid,mid+1),n-j){
            if(cnt[s[i]-'a']==0){
                ok = 0;
                break;
            }
            cnt[s[i]-'a']--;
        }
        // pvc(cnt);
        int i = mid+1;
        while (i<n-i-1)
        {
            if(s[i]!=s[n-i-1]){
                ok = 0;
                break;
            }
            i++;
        }
        if(ok){
            ans = min(ans,mid-j+1);
            hi = mid-1;
        }
        else {
            lo = mid+1;
        }
    }
    put(ans);
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
