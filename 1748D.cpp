#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
void tc(){
    ll a,b,d,k=0,inverse_of_2,total_inverse=1;
    cin>>a>>b>>d;
    a|=b;
    if(a%d==0){
        cout<<a<<'\n';
        return;
    }
    while(a%2==0 && d%2==0)
        a/=2,d/=2,k++;
    inverse_of_2=(d+1)/2;
    if(a%2==1 && d%2==0){
        cout<<"-1\n";
        return;
    }

    for(ll i=0;i<30-k;i++)
        total_inverse=total_inverse*inverse_of_2%d;

    cout<<((total_inverse<<(30-k))-1)*(1ll<<k)<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    ll t; cin>>t; while(t--)
        tc();
}