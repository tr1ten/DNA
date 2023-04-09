#include <bits/stdc++.h>

using namespace std;



class Solution {
    // BIT code
    int lowbit(int i) {
        return i & (-i);
    }
    
    void update(vector<int> &v, int i) {
        for (; i < v.size(); i += lowbit(i)) {
            ++v[i];
        }
    }
    
    int count(const vector<int> &v, int i) {
        int r = 0;
        for (; i; i -= lowbit(i)) {
            r += v[i];
        }
        return r;
    }
    
public:
    long long countFancy(vector<vector<int>>& pairs, int k1, int k2) {
        const int n = pairs.size();
        // sort by pairs[.][0]
        sort(pairs.begin(), pairs.end());
        vector<int> tree(k2 + 2);
        long long r = 0;
        for (int i = n - 1, j = 0; i >= 0; --i) {
            for (; j < n && pairs[j][0] + pairs[i][0] <= k1; ++j) {
                // Add the number pairs[j][1] + 1, Note BIT's keys are positive integers,
                // So we have to plus 1 here.
                if (pairs[j][1] <= k2) {
                    update(tree, pairs[j][1] + 1);
                }
            }
            
            // Count how many values are in [0, k2 - pairs[i][1]]. Again, since we allow 0,
            // we have to plus 1 here.
            if (pairs[i][1] <= k2) {
                r += count(tree, k2 - pairs[i][1] + 1);
                if (pairs[i][0] + pairs[i][0] <= k1 && pairs[i][1] + pairs[i][1] <= k2) {
                    --r;
                }
            }
            
        }
        r /= 2;
        return r;
    }
};
int main(int argc, char const *argv[])
{
    int n,k1,k2;
    cin >> n >> k1 >> k2;
    vector<vector<int>> vpp;
    while(n-->0){
        vector<int> vp(2);
        cin >> vp[0] >> vp[1];
        vpp.push_back(vp);
    }
    cout << Solution().countFancy(vpp,k1,k2);
    return 0;
}