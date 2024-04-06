#include<bits/stdc++.h>
using namespace std;
string s;
string t;
const int N = 20;
int mem[N][2][2][2][10][10];
// can save answer here 
int r;
unsigned long long ans;
// index, upper flag,lower flag, non zero prefix
// rest are states
int dp(int i,bool f,bool f2,int ze,int mn,int mx) {
	if(i==t.size()) {
        
		return mx-mn; 
	}
	if(mem[i][f][f2][ze][mn][mx]!=-1) {
		return mem[i][f][f2][ze][mn][mx];
	}
	int l=s[i]-'0',r = t[i]-'0';
	if(f) r=9;
	if(f2) l=0;
	int res = 10;
	for(int d=l;d<r+1;d++) {
		bool nf = f;
		bool nf2 = f2;
		bool nze = ze | (d>0);
		if(d>l) nf2 = true;
		if(d<r) nf = true;
		res = min(res,dp(i+1,nf,nf2,nze,!nze ? mn : min(mn,d),!nze ? mx : max(mx,d)) );
	}
	return mem[i][f][f2][ze][mn][mx]=res;
}