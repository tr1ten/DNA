#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int sieve[N+1];
// find prime <sqrt(MAX)
// O(LlogL)
void preprocess(){
    sieve[0] = 1;
    sieve[1] = 1;
    for(int x=2;x<=N;x++){
        if(sieve[x]!=0) continue; 
        sieve[x] = x;
        for(int u=x*x;u<=N;u +=x){
            sieve[u] = x;
        }
    }
}

vector<int> factors(int x){
    vector<int> res;
    while(x>1){
        int f = sieve[x];
        if(x%f==0) res.push_back(f);
        while(x%f==0) x/=f;
    }
    return res;
}
// divisors
const int K = 9000;
vector<vector<int>> divs(N+1);
// find prime <sqrt(MAX)
// O(LlogL)
// void preprocess(){
//     for(int x=2;x<=N;x++){
//         for(int u=x;u<=N;u +=x){
//             divs[u].push_back(x);   
//         }
//     }
// }

int main(int argc, char const *argv[])
{
    preprocess();
    
    // standard divisors
    // for(int j=1;j*j<=a[i];j++)
	// 	{		
	// 		if(a[i]%j==0)
	// 		{
	// 			cur.push_back(j);
	// 			if(j != a[i]/j)
	// 				cur.push_back(a[i]/j);
	// 		}
	// 	}
    // while(1){
    //     int x;
    //     cin >> x;
    //     auto fac = divs[x];
    //     for(auto f:fac) cout << f << " ";
    //     cout << endl;
    // }
    return 0;
}
