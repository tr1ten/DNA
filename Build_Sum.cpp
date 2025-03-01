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
    int x1,x2,x3;
    cin >> x1 >> x2 >> x3;
    if(x1+x2==x3){
        put(0);
        return;

    }
    int tar1 = 0,tar2=0,tar3=0;
    int c = 0;
    int mask = 1<<30;
    per(j,0,31){
        int a = ((x1)&mask)>0,b= ((x2)&mask)>0;
        int op = ((x3)&mask)>0;
        if((a+b)%2==0){
            if(a==0){
                if(op==0){
                    tar1 |=c*mask;    
                    c=0;
                }
                else {
                    tar1 |=c*mask;
                    c=1;
                }
            }
            else {
                if(op==0){
                    tar1 |=(c^1)*mask;    
                    c=0;
                }
                else {
                    tar1 |=(c^1)*mask;
                    c=1;
                }
            }
        }
        else {
            if(!a && b){
                if(op==0){
                    tar3 |=(c^1)*mask;
                    tar2 |= c*mask;
                    c=1;
                }
                else {
                    tar2 |= c*mask;
                    c=0;
                }
            }
            else {
                if(op==0){
                    tar3 |=(c)*mask;
                    tar2 |=(c^1)*mask;
                    c=1;
                }
                else {
                    tar3|=c<<j;
                    c=0;
                }
            }
        }
        mask >>=1;
    }
    if(c){
        put(-1);
        return;
    }
    
    // Remove assertion for performance
    assert((x1^tar1^tar2)+(x2^tar1^tar3)==(x3^tar2^tar3));
    
    if(((tar1>0) + (tar2>0) + (tar3>0))==1 && tar1){
        cout << 1 << endl;
        // cout << 1 <<" " << 2 << " " << tar1 << endl;
        return;
    }
    if(((tar1>0) + (tar2>0) + (tar3>0))==1 && tar2){
        cout << 1 << endl;
        // cout << 1 <<" " << 3 << " " << tar2 << endl;
        return;
    }
    if(((tar1>0) + (tar2>0) + (tar3>0))==1 && tar3){
        cout << 1 << endl;
        // cout << 2 <<" " << 3 << " " << tar3 << endl;
        return;
    }
    cout << tar1 << " " << tar2 << " " << tar3 << endl;
    tar1 = tar1^tar2;
    tar3 = tar3^tar2;
    tar2=0;
    assert((x1^tar1^tar2)+(x2^tar1^tar3)==(x3^tar2^tar3));
    cout << 2 << endl;
    // cout << 1 <<" " << 2 << " " << tar1 << endl;
    // cout << 2 <<" " << 3 << " " << tar3 << endl;
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