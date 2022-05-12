#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> rec(vector<int> &arr, int n)
{
    vector<int> odd;
    vector<int> even;
    for (auto el : arr)
    {
        int od = el * 2 - 1;
        int ev = el * 2;
        if (ev <= n)
        {
            odd.push_back(od);
            even.push_back(ev);
        }
        else
        {
            if (od <= n)
            {
                odd.push_back(od);
            }
        }
    }
    for (auto e : even)
    {
        if (e <= n)
        {
            odd.push_back(e);
        }
        else
        {
            return odd;
        }
    }
    
    return odd.size()==n ? odd : rec(odd, n);
}
vector<int> beautifulArray(int n)
{
    vector<int> a = {1};
    return rec(a, n);
}
int main()
{
    beautifulArray(5);
    return 0;
}
