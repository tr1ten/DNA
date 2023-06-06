#include <bits/stdc++.h>

using namespace std;

int lowbit(int x) {
    return x & (-x);
}

void update(vector<int> &v, int x, int y) {
    for (; x < v.size(); v[x] += y, x += lowbit(x))
    ;
}

int count(const vector<int> &v, int x) {
int r;
    for (; x; r += v[x], x -= lowbit(x))
    ;
    return r;
}

int solution(const vector<int> &h, const vector<int> &w, int k) {
    const int n = h.size();
    vector<int> ind(n);
    for (int i = 0; i < n; ++i) {
        ind[i] = i;
    }
    sort(ind.begin(), ind.end(), [&](const int x, const int y) {
        return h[x] < h[y];
    });
    int left = 0, right = max(h[ind.back()] - h[ind[0]], *max_element(w.begin(), w.end()) - *min_element(w.begin(), w.end()));
    while (left <= right) {
        const int mid = (left + right) >> 1;
        
        map<int, int> v;
        for (int y : w) {
            ++v[y];
            ++v[y + mid];
            ++v[y - mid - 1];
        }
        // Now change all the w, (w + mid), (w - mid - 1) into a small range.
        int m = 0;
        for (auto& p : v) {
            p.second = ++m;
        }
        vector<int> bit(m + 1);
        bool mark = false;
        for (int i = 0, s = 0, e = 0; !mark && i < n; ++i) {
            for (; s < n && h[ind[s]] < h[ind[i]] - mid; ++s) {
                update(bit, v[w[ind[s]]], -1);
            }
            for (; e < n && h[ind[e]] <= h[ind[i]] + mid; ++e) {
                update(bit, v[w[ind[e]]], 1);
            }
            // How many |w[.] - w[ind[i]]| <= mid?
            if (count(bit, v[w[ind[i]] + mid]) - count(bit, v[w[ind[i]] - mid - 1]) >= k) {
                mark = true;
            }
        }
        if (mark) {
            right = mid - 1;
        } else {
            left = mid + 1;
        } 
    }
    return right + 1;
}

int main() {
    cout << solution({1, 20, 3}, {2, 3, 40}, 2) << endl;
    cout << solution({1, 20, 3, 4}, {2, 3, 40, 10}, 2) << endl;
    cout << solution({1, 4}, {2, 10}, 2) << endl;
    return 0;
}