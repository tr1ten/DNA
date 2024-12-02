#include <iostream>
#include <algorithm> // For std::min

using namespace std;

void solve() {
    long long x, m;
    cin >> x >> m;

    long long count = 0;
    for (long long y = 1; y <= min(m, 2 * x); ++y) {
        if (x == y) continue;
        long long xor_val = x ^ y;
        if (xor_val == 0) continue;

        if ((x % xor_val == 0) || (y % xor_val == 0)) {
            ++count;
        }
    }

    cout << count << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}