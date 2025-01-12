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
string to_s(int x){
    if(x<0) return "0"+to_string(x);
    return to_string(x);
}
string f(int x){
    if(x%10==0){
        string res = f(1)+"+"+f(x-1);
        return res;
    }
    return to_s(x) + ("+")+ to_s(x) +"-" "0";
} 
string fr(int x){
    string s = f(x);
    reverse(all(s));
    return s;
} 
int half(int x) {
    return x<0 ? (x-1)/2 : x/2;
}
void testcase(){
    int a,b;
    cin >> a >> b;
    string ans;
    if(abs(a%2)==abs(b%2)){
        if(a%2) ans = "1+";
        // cout << a << " " << half(a) << endl;
        ans += f(half(a))+"+"+fr(half(b));
    }
    else {
        // cout << a << " " << b << "  " << a%2 << " " << b%2 << endl;
        if(a%2){
            ans = f( half(a-1) ) +"+" + fr(half(b+10)) + "+99-98"; 
        }
        else {
            ans = f(half(a+10)) +"+" + fr(half(b-1)) + "+89-99";
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
    while(T--) testcase();

    return 0;
}
