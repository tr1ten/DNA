#include <iostream>
#include <vector>
#include <string>
using namespace std;
// freaking brilliant!
int hIndex2(vector<int> citations)
{
    int N = citations.size();
    int ans = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        ans += (N - i - 1) < citations[i] ? 1 : 0;
    }
    return ans;
}
int main()
{

    return 0;   
}
