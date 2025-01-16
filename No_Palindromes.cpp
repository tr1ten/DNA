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
    string s;
    cin >> s;
    vi cnt(26);
    rep(i,0,n){
        cnt[s[i]-'a']++;
    }
    string res;
    char E = 'z'+1;
    res.push_back(E);
    rep(i,0,26){
            if(cnt[i]==0) continue;
        rep(j,0,26){
            if(i==j) continue;
            if(cnt[j]==0) continue;
            int fi=cnt[i]%2 ? n : 0,fj=cnt[j]%2 ? n : 0;
            if(fi && fj){
                put(0);
                return;
            }
            pi mnc = {26,0};
            int last = 0;
            int mni=n+1,mxi=0,mnj=n+1,mxj=0;
            per(k,0,n){
                if(!fj){
                    if(j==s[k]-'a'){
                        fj = k+1;
                    }
                }  
                else if(!fi){
                    if(i==s[k]-'a'){
                        fi = k+1;
                    }
                }
                if(s[k]-'a'==i && fi!=k+1){
                    mni = min(k+1,mni);
                    mxi = max(k+1,mxi);
                }
                if(s[k]-'a'==j && fj!=k+1){
                    mnj = min(k+1,mnj);
                    mxj = max(k+1,mxj);
                }
                
                if(fi && fj){
                    last=k;
                    break;
                }
            }
            if(fi && fj){
                string cur;
                if(cnt[j]%2==0) cur.push_back('a'+j);
                if(cnt[i]%2==0) cur.push_back('a'+i);
                vi took(26);
                int a1 = 0,a2=0;
                per(k,0,last){
                    if(s[k]-'a'!=i){
                        if(took[i]%2){
                            if(mxi) {
                                a1=1;
                                took[i]+=1;
                            }
                            else {
                                cur.pop_back();
                                took[i] -=1;
                            }
                        }
                    }
                    if(s[k]-'a'!=j){
                        if(took[j]%2){
                            if(mxj) {
                                a2 = 1;
                                took[j]+=1;
                            }
                            else {
                                cur.pop_back();
                                took[j] -=1;
                            }
                        }
                    }
                    if(cur.back()>=s[k]) {
                        cur.push_back(s[k]);
                        took[s[k]-'a']++;
                    }
                }
                if(took[i]%2){
                    if(mxi) {
                        a1=1;
                        took[i]+=1;
                    }
                    else {
                        cur.pop_back();
                        took[i] -=1;
                    }
                }
                if(took[j]%2){
                    if(mxj) {
                        a2 = 1;
                        took[j]+=1;
                    }
                    else {
                        cur.pop_back();
                        took[j] -=1;
                    }
                }
                assert(took[i]%2==0 && took[j]%2==0);
                string s1;
                if(a1 && a2){
                    string sa,sb;
                    if(mni<mxj){
                        sa.push_back('a'+j);
                        sa.push_back('a'+ i);
                    }
                    if(mnj < mxi){
                        sa.push_back('a'+ i);
                        sa.push_back('a'+j);
                    }
                    if(sa>=sb) s1 = sa;
                    else s1 = sb;
                }
                else if(a1){
                    s1.push_back('a'+ i);
                }
                else if(a2){
                    s1.push_back('a'+j);
                }
                cur = s1 + cur;
                reverse(all(cur));
                res=  min(cur,res);
            }
        }
    }
    if(res[0]==E) put(-1)
    else {
        rep(i,0,res.size()){
            cnt[res[i]-'a']--;
        }
        int oc =0;
        rep(i,0,26){
            oc += cnt[i]%2;
        }
        // assert(oc>=2);
        put(res.size());
        put(res);
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
