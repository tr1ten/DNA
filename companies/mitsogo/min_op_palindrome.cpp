#include <bits/stdc++.h>

using namespace std;


vector<int> solution(const string &s, const vector<vector<int>> &p) {
    const int n = s.length();
    vector<int> v(n + 1), r;
    for (int i = 1; i <= n; ++i) {
        v[i] = v[i - 1] ^ (1 << (s[i - 1] - 'a'));
    }
    for (const auto & c : p) {
        int m = 0;
        for (int x = v[c[1]] ^ v[c[0] - 1]; x; x &= x - 1, ++m)
        ;
        r.push_back(m >> 1);
    }
    return r;
}
  
void print(const vector<int> &v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    print(solution("abcccdef", {{1,4}, {3, 8}}));

    return 0;
}