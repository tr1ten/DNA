#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    auto getStart = [&intervals](int i)
    {
        return intervals[i][0];
    };
    auto getEnd = [&intervals](int i)
    {
        return intervals[i][1];
    };
    if(newInterval[1]>=getEnd(intervals.size()-1) && newInterval[0] <= getStart(0))
    {
        return {newInterval};
    }
    int i = 0;
    bool found = false;
    while (i < intervals.size() && getStart(i) < newInterval[0])
    {
        if (newInterval[0] <=getEnd(i))
        {
            found = true;
            break;
        }
        i++;
    }
    auto tempIntervals = intervals;
    if (found)
    {
        tempIntervals[i][1] = newInterval[1] > tempIntervals[i][1] ? newInterval[1] : tempIntervals[i][1];
    }
    else
    {
        int index = i;
        tempIntervals.insert(tempIntervals.begin() + index, newInterval);
    }
    // merging if required
    auto mergeThem = [&tempIntervals](int l, int r)
    {
        vector<int> nInterval = {tempIntervals[l][0], max(tempIntervals[l][1], tempIntervals[r][1])};
        int times = r - l + 1;
        while (times > 0)
        {
            tempIntervals.erase(tempIntervals.begin() + l);
            times--;
        }
        tempIntervals.insert(tempIntervals.begin() + l, nInterval);
    };
    auto temptemp = tempIntervals;
    i = 0;
    while (i < (temptemp.size() - 1))
    {
        int j = i + 1;
        while (j<temptemp.size() && temptemp[i][1] >= temptemp[j][0])
        {
            j++;
        }
        j -= 1;
        if (j > i)
        {
            mergeThem(i, j);
            break;
        }
        i++;
    }
    return tempIntervals;
}

int main()
{
    vector<vector<int>> intervals = {{1,5},{6,8}};
    vector<int> newInterval = {5,6};
    insert(intervals, newInterval);
    return 0;
}
