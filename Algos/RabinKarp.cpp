#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
bool checkSub(const string &s, const string &pat, int ind)
{
    int n = pat.size();
    for (int i = 0; i < n; i++)
    {
        if (s.at(ind + i) != pat.at(i))
        {
            return false;
        }
    }
    return true;
}
int rabinkarpSearch(const string &s, const string &pat)
{
    int n = pat.size();
    int m = s.size();
    int q = 13;
    int d = 10;
    int t = 0;
    int pt = 0;
    for (int i = 0; i < n; i++)
    {
        int v = s.at(i) - 'a' + 1;
        int v2 = pat.at(i) - 'a' + 1;
        t += v * pow(d, n - i - 1);
        pt += v2 * pow(d, n - 1 - i);
    }
    t = t % q;
    pt = pt % q;
    if (t == pt && checkSub(s, pat, 0))
    {
        return 0;
    }
    int h = 1;

    for (int i = 0; i < (n - 1); i++)
        h = (h * d) % q;
    for (int i = 1; i <= (m - n); i++)
    {
        t = ((d * (t - (s[i - 1] - 'a' + 1) * h) + (s[i + n - 1] - 'a' + 1))) % q;
        t = t<0? t+q : t;
        if (t == pt && checkSub(s, pat, i))
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    string s = "dlojuxgftvpqpsknfgkejydsxgcgyroavsefjrejytcgflrnnxxsxowqbteycujnrbaokjibq";
    string pat = "fjrejytcgflrnnxxsxowqbteycujnr";
    cout << rabinkarpSearch(s, pat);
    return 0;
}
