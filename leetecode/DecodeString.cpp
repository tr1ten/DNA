#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include <unordered_map>
using namespace std;
int findEnding(string s, int start)
{
    vector<int> stack;
    stack.push_back(1);
    int j = start + 1;
    while (!stack.empty())
    {
        if (s.at(j) == '[')
        {
            stack.push_back(1);
        }
        else if (s.at(j) == ']')
        {
            stack.pop_back();
        }
        j++;
    }
    return j - 1;
}
string rec(string s, int m, unordered_map<string, string> &hashmap)
{

    string ns;
    int j = 0;
    if (hashmap.count(s))
    {
        ns = hashmap[s];
    }
    else
    {
        while (j < s.size())
        {
            if (isdigit(s.at(j)))
            {
                int startD = j;
                int endD = j;
                while (isdigit(s.at(endD + 1)))
                {
                    endD++;
                }
                int x = stoi(s.substr(startD, endD - startD + 1));
                int o = endD + 1;
                int c = findEnding(s, o);
                ns += rec(s.substr(o + 1, c - o - 1), x, hashmap);
                j = c;
            }
            else
            {
                ns.push_back(s.at(j));
            }
            j++;
        }
        hashmap[s] = ns;
    }
    string out = ns;
    for (int i = 0; i < m - 1; i++)
    {
        out += ns;
    }
    return out;
}
string decodeString(string s)
{
    unordered_map<string, string> hashmap;
    return rec(s, 1, hashmap);
}
int main()
{
    cout << decodeString("100[leetcode]") << endl;
    return 0;
}
