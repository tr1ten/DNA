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
    vi a(n),b(n);
    tkv(a,n);
    tkv(b,n);
    map<int,int> op;
    int same = -1;
    rep(i,0,n){
        if(a[i]==b[i]){
            if(n%2==0 || same!=-1){
                put(-1);
                return;
            }
            same = i;
        }
        else {
            if(op.count(a[i]) && op[a[i]] != b[i]){
                put(-1);
                return;
            }
            op[a[i]] = b[i];
            op[b[i]] = a[i];
        }
    }
    vi des(n);
    vector<pi> ops;
    if(n%2 && same==-1){
        put(-1);
        return;
    }
    if(same!=-1 && same!=n/2)  {
        swap(a[n/2],a[same]);
        swap(b[n/2],b[same]);
        ops.push_back({n/2,same});
    }
    int j = 0;
    map<int,int> mi;
    int k = 0;
    per(i,(n+1)/2,n){
        if(mi.count(a[i])){
            while (mi.count(a[k]))
            {
                k++;
            }
            swap(a[k],a[i]);
            swap(b[k],b[i]);
            ops.push_back({k,i});
        }
        mi[a[i]] =mi[b[i]]= j++;
    }
    // pvc(a);pvc(b);
    int i = 0;
    int start = ops.size();
    vi done(n,0);
    while(i<n/2){
        if(done[i]){
            i++;
            continue;;
        }
        int ni = mi[b[i]];
        int cur = i;
        vi pp;
        done[i] = 1;
        pp.push_back(i);
        while (!done[ni])
        {
            done[cur] =1;
            cur = ni;
            pp.push_back(cur);
            ni = mi[b[cur]];
            assert(pp.size()<=n);
        }
        per(j,0,pp.size()-1){
            ops.push_back({pp[j],pp[j+1]});
        }
        i++;
    }
    rep(k,start,ops.size()){
        swap(a[ops[k].first],a[ops[k].second]);
        swap(b[ops[k].first],b[ops[k].second]);
    }
    reverse(all(b));
    assert(a==b);
    assert(ops.size()<=n);
    put(ops.size());
    // pvc(a);pvc(b);
    
    rep(i,0,ops.size()){
        cout << min(ops[i].first,ops[i].second)+1 <<" " <<  max(ops[i].first,ops[i].second)+1 << endl;
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


// 1 2 3
// 2 3 1