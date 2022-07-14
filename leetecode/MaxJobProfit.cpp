#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int dp[50002];
int rec(vector<vector<int>> &kmap, int j)
{
    if (j >= kmap.size())
    {
        return 0;
    }
    if (dp[j] != -1)
    {
        return dp[j];
    }
    int i = j;
    while (i < kmap.size() && kmap[i][0] < kmap[j][1])
    {
        i++;
    }
    return dp[j] = max(kmap[j][2]+rec(kmap, i), rec(kmap, j + 1));
}
static bool cmp(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}
int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    int n = startTime.size();
    memset(dp, -1, sizeof(dp));
    vector<vector<int>> arr(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        arr[i][0] = startTime[i]; // start time
        arr[i][1] = endTime[i];   // endtime
        arr[i][2] = profit[i];    // profit
    }

    sort(arr.begin(), arr.end(), cmp);
    return rec(arr, 0);
}
int main()
{
    vector<int> startTime = {6, 15, 7, 11, 1, 3, 16, 2};
    vector<int> endTime = {19, 18, 19, 16, 10, 8, 19, 8};
    vector<int> profit = {2, 9, 1, 19, 5, 7, 3, 19};
    cout << jobScheduling(startTime, endTime, profit);
    return 0;
}
// [6,15,7,11,1,3,16,2]
// [19,18,19,16,10,8,19,8]
// [2,9,1,19,5,7,3,19]
