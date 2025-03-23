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
    vi a(n);
    tkv(a,n);
    int cz = count(all(a),0);
    if(cz==0){
        put(1);
        cout << 1 << " " << n << endl;
        return;
    }
    else if(cz==n || (a[0]==0 && a[n-1]==0)){
        cout << 3 <<endl;
        cout << 1 << " " << 2 << endl;
        cout << 2 << " " << n-1  << endl; 
        cout << 1 << " " << 2 << endl; 
    }
    else {
        int i = find(all(a),0) - a.begin();
        int j = n-1;
        cout << 2<< endl;
        while (a[j]!=0)
        {
            j--;
        }
        if(j-i+1==1){
            if(i>0) i--;
            else j++;
        }
        cout << i+1 << " " << j+1 << endl;
        cout << 1 << " " << n-(j-i) << endl;

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
