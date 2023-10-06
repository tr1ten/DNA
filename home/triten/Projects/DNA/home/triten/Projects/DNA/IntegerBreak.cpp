#include <bits/stdc++.h>

using namespace std;


const int N = 50;
int dp[N+5][2];
class Solution {
public:
    int integerBreak(int n) {
        int ans = 0;
        for(int i=2;i<=n;i++){
            int c = n/i;
            int c2 = n%i;
            ans = max( (int) pow(c,i-c2)*(int)pow(c+1,c2) , ans);
            
        }
        return ans;
    }
};