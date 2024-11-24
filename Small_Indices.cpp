#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<int> C;
        C.push_back(min(a[0], b[0]));
        if (n > 1) {
            C.push_back(min(a[1], b[1]));
        } else {
            C.push_back(0);
        }

        set<int> possible_sums;
        possible_sums.insert(C[0] + C[1]);
        int num_small_indices = 0;

        for (int i = 2; i < n; i++) {
            vector<int> choices = {a[i], b[i]};
            vector<bool> can_be_small(2, false);

            for (int idx = 0; idx < 2; idx++) {
                int val = choices[idx];
                // Check if val <= any sum in possible_sums
                for (int s : possible_sums) {
                    if (s >= val) {
                        can_be_small[idx] = true;
                        break;
                    }
                }
            }

            int C_i;
            if (can_be_small[0] && !can_be_small[1]) {
                C_i = choices[0];
                num_small_indices++;
            } else if (!can_be_small[0] && can_be_small[1]) {
                C_i = choices[1];
                num_small_indices++;
            } else if (can_be_small[0] && can_be_small[1]) {
                C_i = min(choices[0], choices[1]);
                num_small_indices++;
            } else {
                C_i = min(choices[0], choices[1]);
            }

            C.push_back(C_i);

            // Update possible sums with new sums involving C_i and previous C_j
            for (int k = 0; k < i; k++) {
                possible_sums.insert(C[k] + C_i);
            }
        }

        cout << num_small_indices << endl;
    }

    return 0;
}
