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
    int x,y;
    cin >> x >> y;
    string t="01";
    int n = s.size();
    int twice = 2;
    int best_ans = INF;
    while(twice--) {
            vi pref(n+1),suff(n+1);
        int total_ones = count(all(s),t[1]);
        int ones_suff = total_ones;
        rep(i,0,n){
            ones_suff -=s[i]==t[1];
            if(s[i]=='?'){
                pref[i+1] = pref[i] + ones_suff*x + (total_ones-ones_suff)*y;
            }
            else pref[i+1] = pref[i];
        }
        int total_zeros = count(all(s),t[0]);
        int zeros_suff = total_zeros;
        per(i,0,n){
            zeros_suff -=s[i]==t[0];
            if(s[i]=='?'){
                suff[i] = suff[i+1] + zeros_suff*x + (total_zeros-zeros_suff)*y;
            }
            else suff[i] = suff[i+1];
        }
        int total_marks = count(all(s),'?');
        int marks_suff = total_marks;
        int ans=INF;
        int ones= 0;
        int base = 0;
        int zeros = 0;
        rep(i,0,n){
            if(s[i]==t[0]){
                base += ones*y;
                zeros++;
            }
            else if(s[i]==t[1]) {
                base += zeros*x;
                ones++;
            }
        }
        rep(i,0,n+1){
            int cur = base + pref[i] + suff[i] + marks_suff*(total_marks-marks_suff )*x;
            // cout << "cur:" << cur<< " " << marks_suff << " " << suff[i] << "   " << pref[i] << " " << i << endl;
            ans = min(ans,cur);
            if(i<n){
                marks_suff -=s[i]=='?';
            }
        }
        swap(t[0],t[1]);
        swap(x,y);
        best_ans = min(ans,best_ans);
    }
    put(best_ans);
    

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
