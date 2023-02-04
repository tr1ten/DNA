#include <bits/stdc++.h>
using namespace std;
// useful defs
typedef vector<int> VI;
typedef vector<VI> VII;
typedef long long LL;
typedef pair<int, int> PI;
#define PB push_back
class CountIntervals
{
public:
    set<PI> ivals;
    LL res;
    CountIntervals()
    {
        res = 0;
    }

    void add(int left, int right)
    {
        PI p = {left, right};
        if (ivals.size())
        {
            auto iter = ivals.lower_bound(p);

            if (iter != ivals.begin() && (*prev(iter)).second >= p.first)
            {
                iter--;
            }
            cout << "lower  " << (*iter).first << " " << (*iter).second << endl;
            if (iter != ivals.end())
                p.first = min((*iter).first, p.first);
            while (iter != ivals.end() && (*iter).first <= p.second)
            {
                p.second = max((*iter).second, p.second);
                res -= ((*iter).second + (*iter).first + 1);
                cout << "removing  " << (*iter).first << " " << (*iter).second << endl;
                ivals.erase(iter);
            }
        }
        res += (p.second - p.first + 1);
        cout << "res " << res << " " << p.first << " " << p.second << endl;
        ivals.insert(p);
    }

    int count()
    {
        return res;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */