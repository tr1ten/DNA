#include<bits/stdc++.h>
using namespace std;

int dp[1001][501][501];

int recur(vector<int> &v, int i, int x, int y){
        if(i==v.size())return 0;
        if(dp[i][x][y]!=-1)return dp[i][x][y];
        int ans=0;
        ans = recur(v, i+1, x, y);
        if(v[i]<=x)ans = max(ans, 1+recur(v, i+1, x-v[i], y));
        if(v[i]<=y)ans = max(ans, 1+recur(v, i+1, x, y-v[i]));
        return dp[i][x][y]=ans;
}

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> v(n);
        for(int i=0;i<n;i++)cin >> v[i];
        memset(dp, -1, sizeof(dp));
        cout << recur(v, 0, x, y) << endl;
        return 0;
}