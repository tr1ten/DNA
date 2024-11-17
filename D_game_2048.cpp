#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const ll MOD = 998244353;
const int N = 4 * (1e6) + 2;
const int B = 18;

int dp[N], vals[B];

void testcase() {
    int n;
    cin >> n;
    cout << dp[n] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    int p = 2;
    for (int i = 2; i < B; i++) {
        p *= 2;
        vals[i] = (i - 1) * p;
    }

    dp[0] = 1;

    for (int i = 2; i < B; i++) {
        int val = vals[i];
        for (int j = val; j < N; j++) {
            dp[j] += dp[j - val];
            if (dp[j] >= MOD) dp[j] -= MOD;
        }
    }

    while (T--) testcase();

    return 0;
}
