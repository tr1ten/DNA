#include <bits/stdc++.h>
using namespace std;
class FenwickTree {
public:
    FenwickTree(vector<long long> nums) {
        tree = vector<long long>(nums.size()+1);
    }

    void update(int i, int diff) {
        i += 1;
        while (i < tree.size()) {
            tree[i] += diff;
            i += i & (-i);
        }
    }

    long long _rangeSum(int i) {
        i += 1;
        long long sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= i & (-i);
        }
        return sum;
    }

    long long rangeSum(int i, int j) {
        return _rangeSum(j) - _rangeSum(i-1);
    }

    vector<long long> tree;
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<long long> nums(m);
    for (int x = 0; x < m; x++) {
        cin >> nums[x];
    }
    FenwickTree ft(nums);
    for (int x = 0; x < m; x++) {
        ft.update(x, nums[x]);
    }
    for (int i = 0; i < n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            ft.update(b-1, c-nums[b-1]);
            nums[b-1] = c;
        } else {
            cout << ft.rangeSum(b-1, c-1) << endl;
        }
    }
    return 0;
}