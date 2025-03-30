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
char a='L',b='I',c='T';
void testcase(){
    string s;
    int n;
    cin >> n;
    cin >> s;
    map<char,int> cnt;
    rep(i,0,n){
        cnt[s[i]]++;
    }
    if(!cnt[a] + !cnt[b] + !cnt[c]>=2){
        put(-1);
        return;
    }
    if(cnt[a]==cnt[b] && cnt[b]==cnt[c]){
        put(0);
        return;
    }
    vector<char> cc={a,b,c};
    sort(all(cc),[&](char i,char j){
        return cnt[i] < cnt[j];
    });
    vi ops;
    rep(x,0,1){
        char rp = cc[x];

        char o1,o2;
        if(x==0) {o1 = cc[1],o2=cc[2];}
        else {o1=cc[0],o2=cc[2];}

        int req = max(cnt[o1],cnt[o2])-cnt[rp];
        if(req==0) continue;
        int dx = -1;
        rep(i,0,s.size()-1){
            if(s[i]!=s[i+1]){
                dx=  i;
                if(s[i]!=rp){
                    s = s.substr(0,i+1) + rp + s.substr(i+1);
                    dx = i+1;
                    cnt[rp]++;
                    ops.push_back(i+1);
                }
                break;
            }
        }
        string cur;
        vector<char> places = {o1,o2};
        int st =0;
        if(s[dx+1]==o1) st=1; 
        while (cnt[rp] < max(cnt[o1],cnt[o2]))
        {
            cur.push_back(rp);
            ops.push_back(dx+2);
            ops.push_back(dx+3);
            cnt[rp]++;
                cur.push_back(places[st]);
                cnt[places[st]]++;
                st^=1;
        }
        reverse(all(cur));
        s = s.substr(0,dx+1) + cur + s.substr(dx+1);
        cout << dx << " " << rp << " " << req <<" "<< s << " " << cur << endl;
    }
    put(s.size());
    put(s);
    put(ops.size());
    pvc(ops);

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
