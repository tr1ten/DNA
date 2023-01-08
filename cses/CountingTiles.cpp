#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
// shi! need brackets around bit shift
int MOD = pow(10,9) + 7;

vector<vector<int>> mem;
bool valid(int state,int prev,int n){
    if((state&prev)>0) return false;
    int i = 0;
    while(i<n){
        if((state&(1<<i))==0){
            if((prev&(1<<i))==0 && i+1<n && (state&(1<<(i+1)))==0 && (prev&(1<<(i+1)))==0) i+=1;
            else {
                if((prev&(1<<i))==0) return false;
            }
        }
        i+=1;
    }
    return true;
}

int count(int k,int prev,int n,int m){
    if(k==m) return 1;
    if(mem[k][prev]!=-1) return mem[k][prev];
    int ways = 0;
    for (int pos = 0; pos < 1<<n; pos++)
    {   
        if((k==m-1 && pos>0) || !valid(pos,prev,n)) continue;
        // std::cout << pos << " "  << prev  << " " << k << " "<< valid(pos,prev,n) << std::endl;
        ways= (ways+count(k+1,pos,n,m))%MOD;
    }
    mem[k][prev] = ways;
    return ways;
    
}
int countTiles(int n,int m){
    return count(0,0,n,m);
}

int main()
{
    int n,m;
    cin>>n>>m;
    mem.resize(m,vector<int>(1<<n,-1));
    cout << countTiles(n,m);
    return 0;
}

