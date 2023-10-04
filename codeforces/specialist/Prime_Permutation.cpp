#include<bits/stdc++.h>

using namespace std;

#define ll long long 

map<ll,ll>m;

void SieveOfEratosthenes(int n)

{

    // Create a boolean array "prime[0..n]" and initialize

    // all entries it as true. A value in prime[i] will

    // finally be false if i is Not a prime, else true.

    bool prime[n + 1];

    memset(prime, true, sizeof(prime));

  

    for (int p = 2; p * p <= n; p++) {

        // If prime[p] is not changed, then it is a prime

        if (prime[p] == true) {

            // Update all multiples of p greater than or

            // equal to the square of it numbers which are

            // multiple of p and are less than p^2 are

            // already been marked.

            for (int i = p * p; i <= n; i += p)

                prime[i] = false;

        }

    }

  ll ct=0;

    // Print all prime numbers

    for (int p = 2; p <= n; p++)

        if (prime[p])

          m[p]=1;

}

void solve(){

SieveOfEratosthenes(1e5+50);

ll n;

cin>>n;

vector<ll>ans(n+1,0);

if(n==2 or n==3){cout<<-1<<endl;return;}

for(int i=1;i<=n;i++)

{

    if(ans[i]==0){

        if(i+2<=n){

        ans[i]=i+2;

        ans[i+2]=i;}

        else{ans[i]=i;}

    }

}

if(n%2==0 and (n/2)%2==0){

    // for(int i=1;i<=n;i++){cout<<i<<" ";}cout<<endl;

        for(int i=1;i<=n;i++){

        cout<<ans[i]<<" ";

    }

    cout<<endl;return;

}

else if(n%2==0 and (n/2)%2==1){

    swap(ans[n-1],ans[n]);

    swap(ans[n-1],ans[n-2]);

    swap(ans[n-3],ans[n]);

    // for(int i=1;i<=n;i++){cout<<i<<" ";}cout<<endl;

    for(int i=1;i<=n;i++){

        cout<<ans[i]<<" ";

    }

    cout<<endl;return;

}

else if(n%2==1 and (n/2)%2==0){

   swap(ans[n],ans[n-2]);

   swap(ans[n-1],ans[n]);

//  for(int i=1;i<=n;i++){cout<<i<<" ";}cout<<endl;

        for(int i=1;i<=n;i++){

        cout<<ans[i]<<" ";

    }

    cout<<endl;return;

}

else if(n%2==1 and (n/2)%2==1){

    swap(ans[n-1],ans[n-4]);

    // for(int i=1;i<=n;i++){cout<<i<<" ";}cout<<endl;

        for(int i=1;i<=n;i++){

        cout<<ans[i]<<" ";

    }

    cout<<endl;return;

}

}

int32_t main() {

ios::sync_with_stdio(0);

cin.tie(0);

int t; cin>>t;

while(t--){

solve();

}

return 0;

}