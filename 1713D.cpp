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
int ask(int a,int b){
    cout << "? " << a+1 << " " << b+1 << endl;
    cout.flush();
    int p;
    cin >> p;
    return p;
}
void tell(int x){
    cout << "! " << x+1  << endl;
    cout.flush();
}
void testcase(){
    int n;
    cin >> n;
    vector<int> cons;
    rep(i,0,1<<n){
        cons.push_back(i);
    }
    while (cons.size()>=4)
    {
        vi ncons;
        for(int i=0;i<cons.size();i+=4){
            int s = ask(cons[i],cons[i+2]);
            if(s==2){
                int s2 = ask(cons[i+1],cons[i+2]);
                if(s2==1) ncons.push_back(cons[i+1]);
                else if(s2==2) ncons.push_back(cons[i+2]);
            }
            else if(s==1){
                int s2 = ask(cons[i],cons[i+3]);
                if(s2==1) ncons.push_back(cons[i]);
                else if(s2==2) ncons.push_back(cons[i+3]);
            }
            else {
                int s2 = ask(cons[i+1],cons[i+3]);
                if(s2==1) ncons.push_back(cons[i+1]);
                else if(s2==2) ncons.push_back(cons[i+3]);
            }
        }
        cons = ncons;
    }
    if(cons.size()==2){
        int s = ask(cons[0],cons[1]);
        if(s==1) cons.pop_back();
        else cons.erase(cons.begin());
    }
    assert(cons.size()==1);
    tell(cons[0]);
    
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
