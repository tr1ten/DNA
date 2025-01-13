#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int N = 1005;
int dp[N][N];
int solve(string s,string t){
    dp[0][0]=1;
    int n =  s.size(),m=t.size();
    for(int i=0;i<=n;i++) dp[i][0] = 1;
    for(int i=0;i<=m;i++) dp[0][i] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            if(s[i-1]==t[j-1]){
                dp[i][j] +=dp[i-1][j-1];
            }
        }
    }
    return dp[n][m]-1;
}
int main()
{
    string s = "ajblqcpdz";
    string t = "aefcnbtdi";
    cout << solve(s,t) << endl;
    return 0;
}
