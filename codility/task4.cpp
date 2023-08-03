#include <bits/stdc++.h>

using namespace std;


int solution(const vector<int> &h, int x, int y) {
    multiset<int> s(h.begin(), h.end());
    if (x > y) {
        swap(x, y);
    }
    vector<bool> dp(x + 1);
    dp[0] = true;
    int r = 0, m = 0, sum = 0;
    for (int v : s) {
        sum += v;
        if (v > y || sum > x + y) {
            break;
        }
        if (v <= x) {
            for (int i = x; i >= v; --i) {
                if (dp[i - v]) {
                    dp[i] = true;
                    m = max(m, i);
                }
            }
        }
        if (sum - m > y) {
            break;
        } 
        ++r;
    }
    return r;
}
    
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i:v) cin >> i;
    int x,y;
    cin >> x >> y;
    cout << solution(v,x,y) << endl;
}