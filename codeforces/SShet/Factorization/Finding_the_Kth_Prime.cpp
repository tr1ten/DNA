#include <bits/stdc++.h>

using namespace std;
const int N = 90000000;
bool sieve[N+1];
// find prime <sqrt(MAX)
// O(LlogL)
void preprocess(){
    sieve[0] = 1;
    sieve[1] = 1;
    for(int x=2;x*x<=N;x++){
        if(sieve[x]!=0) continue; 
        for(int u=x*x;u<=N;u +=x){
            sieve[u] = 1;
        }
    }
}
int main(){
    preprocess();
    long long cnt = 0;
    int t;
    cin >> t;
    vector<pair<int,int>> prs(t);

    for(int i=0;i<t;i++){
        int q;
        cin >> q;
        prs[i] = (make_pair(q,i));
    }
    sort(prs.begin(),prs.end());
    long long res[t];
    int qi = 0;
    for(int i=2;i<=N;i++){
        if(sieve[i]==0) {
            cnt ++;
            while(qi<t && prs[qi].first==cnt){
                res[prs[qi++].second] = i;
            }
        }
    }
    for(auto x:res){
        printf("%d\n",x);
    }
    return 0;
}
