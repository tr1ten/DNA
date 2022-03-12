#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> mIntervals;
    vector<int> ap1;
    vector<int> ap2;
    int n = intervals.size();
    for (int i = 0; i < n; i++)
    {
        ap1.push_back(intervals[i][0]);
        ap2.push_back(intervals[i][1]);
    }
    sort(ap1.begin(), ap1.end());
    sort(ap2.begin(), ap2.end());

    int p1 = 0, p2 = 0;
    int i = 1;
    while (p1 < n && p2 < n)
    {
        if (p1 + i < n && ap1[p1 + i] <= ap2[p2])
        {
            p2++;
            i++;
        }
        else
        {
            mIntervals.push_back({ap1[p1], ap2[p2]});
            p1 += i;
            p2++;
            i = 1;
        }
    }
    return mIntervals;
}
int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    merge(intervals);
    return 0;
}
