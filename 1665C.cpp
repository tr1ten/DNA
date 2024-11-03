#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

const int N = 200100;
int classroom[N];

bool is_valid(int t, vi &vec) {
    int operations = 0;
    for (int i = 0; i < vec.size(); ++i) {
        operations++;
        vec[i] -= (t - i);
    }
    if (operations > t) return false;

    for (int value : vec) {
        int adjusted = max(0, value);
        operations += adjusted;
    }
    return operations <= t;
}

int main() {
    int n,m;
    cin >> n >> m;
    fill(classroom, classroom + m + 1, 0);

    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        classroom[x]++;
    }

    vi vec = {1}; // for initial infection spread 
    for (int i = 1; i <= n; ++i) {
        if (classroom[i]) vec.push_back(classroom[i]);
    }

    sort(vec.rbegin(), vec.rend());

    int left = 1, right = n, result = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (is_valid(mid, vec)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << result << endl;
}