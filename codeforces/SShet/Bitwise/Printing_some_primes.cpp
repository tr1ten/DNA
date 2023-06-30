#include <bits/stdc++.h>

using namespace std;
const int N = 1e8;
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
    for(int i=2;i<=N;i++){
        if(sieve[i]==0) {
            cnt ++;
            // if(cnt%100==1) printf("%d\n",i);
        }
    }
    cout << cnt << endl;
    return 0;
}
