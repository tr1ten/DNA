#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

template <typename T = int>
std::vector<T> ReadArray(int size = 0, std::istream &in_stream = std::cin);
using namespace std;
const int MX = 125;
long long sizes[MX];
void pre()
{
    sizes[0] = 0;
    for (int i = 1; i < MX; i++)
    {
        sizes[i] = sizes[i - 1] + (i * (i + 1)) / 2;
    }
}
const int N = 300000 + 2;
int dp[MX][N];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // std::freopen("balls.in", "r", stdin);
    // std::freopen("balls.out", "w", stdout);
    pre();
    dp[0][0] = 0;
    for(int s=1;s<N;s++) {dp[0][s] = 10000;}
    for (int i = 1; i < MX; i++)
    {
        for (int s = 0; s < N; s++)
        {
            if(s>=sizes[i]) dp[i][s] = min(dp[i-1][s],dp[i][s-sizes[i]] + 1);
            else dp[i][s] = dp[i-1][s];
        }
    }
    const auto testcases = ReadArray();
    for(auto m:testcases){
        cout << dp[MX-1][m] << endl;
    }
    return 0;
}

template <typename T>
std::vector<T> ReadArray(int size, std::istream &in_stream)
{
    if (!size)
    {
        in_stream >> size;
    }
    std::vector<T> array(size);
    for (auto &element : array)
    {
        in_stream >> element;
    }
    return array;
}
