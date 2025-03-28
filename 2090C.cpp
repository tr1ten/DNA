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
pi getc(int x,int y,int k){
    return {3*x+1+(k==2 || k==3),3*y+1+(k==1 || k==3)};

}
pi get(int x,int y){
    if(y==0){
        return {0,x+y+1};
    }
    return {x+1,y-1};
}
int getd(int x,int y,int k){
    auto nxt = getc(x,y,0);
    if(k==0) return nxt.first + nxt.second;
    return nxt.first+nxt.second+(k==1 || k==2 ? 1 : 4);
}
void testcase(){
    int n;
    cin >> n;
    int ci = 0,cj = 0;
    map<tuple<int,int>,int> cnt;
    priority_queue<vi,vector<vi>,greater<vi>> pq;
    rep(i,0,n) {
        int x;
        cin >> x;   
        while (pq.size() && cnt[{pq.top()[3],pq.top()[4]}]==0 && pq.top()[3]+pq.top()[4]<(ci + cj))
        {
            pq.pop();
        }
        if(pq.size()==0) x=0;
        pi ans;
        
        if(x==0){
            ans = getc(ci,cj,0);
            cnt[{ci,cj}]+=1;
            auto nxt = getc(ci,cj,1);
            pq.push({getd(ci,cj,1),nxt.first,nxt.second,ci,cj});
            auto pa = get(ci,cj);
            ci = pa.first,cj =pa.second;
            nxt = getc(ci,cj,0);
            pq.push({getd(ci,cj,0),nxt.first,nxt.second,ci,cj});

        }
        else {
            
            auto cs =pq.top();
            pq.pop();
            ans.first = cs[1],ans.second = cs[2];
            if(cs[3]==ci && cs[4]==cj){
                auto pa = get(ci,cj);
                ci = pa.first,cj =pa.second; 
                auto nxt = getc(ci,cj,0);
                pq.push({getd(ci,cj,0),nxt.first,nxt.second,ci,cj});
            }
            int val = ++cnt[{cs[3],cs[4]}];
            if(val<4){
                auto nxt = getc(cs[3],cs[4],val);
                pq.push({getd(cs[3],cs[4],val),nxt.first,nxt.second,cs[3],cs[4]});
            }
            
        }
        cout << ans.first << " " << ans.second << endl;

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
