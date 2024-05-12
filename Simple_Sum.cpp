#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int mx =10000000;
	vector<int> minD(mx+tisic,0);
	for(int i =2; i <= mx; i++) if(minD[i] == 0)
		for(int j =1; j <= mx/i; j++) minD[i*j] =i;
	int T;
	scanf(" %d",&T);
	for(int t =0; t < T; t++) {
		int N;
		long long ans =1;
		scanf(" %d",&N);
		while(N > 1) {
			int p =minD[N], ppw =1;
			while(N%p == 0) {
				ppw *=p;
				N /=p;}
			ans *=1LL*ppw*ppw-(1LL*ppw*ppw-1)/(p+1);}
		printf("%lld\n",ans);}
	return 0;}

// look at my code
// my code is amazing
