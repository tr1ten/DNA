#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m; cin>>n>>m;
	vector<int> A(n);
	for(int& i: A) cin>>i;
	vector<int> have(n+1);
	for(int i = n-1; i >= n-m; i--){
		have[A[i]]++;
	}
	// we just need first subarray mex than check in following subarrays if we can made it smaller
	int mex = n;
	for(int i= 0; i <= n; i++){
		if(!have[i]){
			mex = i;
			break;
		}
	}
	for(int i = n-m-1; i >= 0; i--){
		have[A[i+m]]--;
		have[A[i]]++;
		if(!have[A[i+m]]) mex = min(mex,A[i+m]);
		
	}
	cout<<mex;
}