#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end());
        map<int, int> past;
        past[0] = 0;
        int res = 0;
        for (auto vec : events)
        {
            auto it = past.lower_bound(vec[0]);
            auto p = *prev(it);
            res = max(vec[2] + p.second, res);
            auto en = past.upper_bound(vec[1]) ;
            if ((*prev(en)).second < vec[2]) past[vec[1]] = vec[2];
            while(en!=past.end() && (*en).second<=vec[2]){ 
                auto nxt = next(en);
                past.erase(en);
                en = nxt;
            }
        }
        return res;
    }
};