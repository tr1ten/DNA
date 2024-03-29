#include <bits/stdc++.h>
using namespace std;
// Fenwick Tree
// Time Complexity: O(logn) for both update and query
const int MOD = 1e9 + 7;
void update(int BIT[], int x, int val, int N)
{
    ++x;
    while (x <= N)
    {
        BIT[x] += val;
        BIT[x] %= MOD;
        x += (x & -x);
    }
}
long long query(int BIT[], int x)
{
    ++x;
    long long res = 0;
    while (x > 0)
    {
        res += BIT[x];
        res %= MOD;
        x -= (x & -x);
    }
    return res;
}
long long range(int bit[], int a, int b) { return (query(bit, b) - query(bit, a - 1) + MOD) % MOD; }


int main(int argc, char const *argv[])
{

    map<int, int> cnt;
    int n = 10;
    // space compression (If large range of y)
    // for (int i = 0; i < n; i++)
    // {
    //     cnt[y]++;
    // }
    // unordered_map<int, int> yid;
    // int id = 0;
    // for (auto y : cnt)
    // {
    //     yid[y.first] = id++;
    // }
    // usage
    int bit[n + 1];
    memset(bit, 0, sizeof(bit));
    update(bit, 0, 1, n);
    update(bit, 1, 2, n);
    update(bit, 2, 3, n);
    cout << range(bit, 0, 2) << endl;
    return 0;
}

#include <vector>

class BIT {
private:
    std::vector<int> nums;
public:
    BIT(int n) {
        nums.resize(n+1);
    }
    void update(int i, int val) {
        i += 1;
        while (i < nums.size()) {
            nums[i] += val;
            i += (i & (-i));
        }
    }
    int sum(int i) {
        int r = 0;
        // i += 1, not needed here since we need sum of rank less than i rank[0...i-1]
        while (i > 0) {
            r += nums[i];
            i -= (i & (-i));
        }
        return r;
    }
};



// int lsb(int x){
//     return x&(-x);
// }
// void add(int bit[],int i,int x,int n){
//     ++i;
//     while (i<=n)
//     {
//         bit[i] +=x;
//         i += lsb(i);
//     }
    
// }
// int query(int bit[],int i){
//     i++;
//     int res=0;
//     while (i>0)
//     {
//         res += bit[i];
//         i -=lsb(i);
//     }
//     return res;
// }
