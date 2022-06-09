#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> decimal2bin(int n)
{
    int q = n;
    int r;
    vector<int> bin;
    while (q > 0)
    {
        r = q % 2;
        q = q / 2;
        bin.push_back(r);
    }
    return bin;
}
int minFlips(int a, int b, int c)
{
    auto bina = decimal2bin(a);
    auto binb = decimal2bin(b);
    auto binc = decimal2bin(c);
    int na = bina.size();
    int nb = binb.size();
    int nc = binc.size();
    int maxL = max(na > nb ? na : nb, nc);
    for (int i = na - 1; i < maxL; i++)
    {
        bina.push_back(0);
    }
    for (int i = nb - 1; i < maxL; i++)
    {
        binb.push_back(0);
    }
    for (int i = nc - 1; i < maxL; i++)
    {
        binc.push_back(0);
    }
    int flipCount = 0;
    for (int i = 0; i < maxL; i++)
    {
        if ((bina[i] | binb[i]) != binc[i])
        {
            if ((!bina[i] | binb[i]) == binc[i] | (bina[i] | !binb[i]) == binc[i])
            {
                flipCount += 1;
            }
            else
            {
                flipCount += 2;
            }
        }
    }
    return flipCount;
}
int main()
{
    cout << minFlips(8,3,5);
    return 0;
}
