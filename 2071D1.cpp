#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {cin >> a[i];}
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (a[mid] > a[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    cout << left << endl;

    return 0;
}