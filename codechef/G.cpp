// Problem: Good Sequence
// Contest: CodeChef - START72
// URL: https://www.codechef.com/problems/GSEQ
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
// do not use unordered map use mll
#define rep(i,a,b) for (int i = (a); i < (b); i++)
typedef long long ll; 
#define pvc(vec) trav(x,vec) cout<<x<<" "; cout<<endl;
#define put(x) cout<<(x)<<endl;
#define per(i,a,b) for (int i = (b)-1; i >= (a); i--)

typedef pair<ll,ll> pi;
const int N = 1e5 + 5;
int dp[2*N + 10];
int dp2[N] ;
int a[N];
int b[N];
void testcase(){
	int n;
	cin >> n;
	int c1 = 0;
	int c0 = 0;
	a[0] = 0;
	dp[N-1] = 0;
	dp[N] = 0;
	rep(i,0,n) {
		int x;
		cin >> x;
		c1 += x;
		c0 += !x;
		a[i+1] = c1-c0;
		dp[a[i+1] + N] = 0;
		dp[a[i+1] + N - 1] = 0;
	}
	
	pi ans={-1,-1};
	rep(i,0,n+1) {
		dp[a[i]+N] = max(dp[N+a[i]-1]+1,dp[N+a[i]]);
		dp2[i] = dp[N+a[i]];
		ans = max((pi){dp[N+a[i]],i},ans);
 	}
 	int cur = a[ans.second];
 	int val = ans.first;
 	per(i,0,n+1) {
 		if(a[i]==cur && dp2[i]==val) {
 			cur--;
 			val--;
 			b[val] = i+1;
 		}
 	}
 	put(ans.first);
	rep(i,0,ans.first) {
		cout << b[i] << " ";
	}
	cout << endl;
}
// driver code
int main()
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
