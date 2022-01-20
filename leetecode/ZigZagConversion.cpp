#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string convert(string s, int numRows)
{
    string abc;

    if (numRows < 2 || s.length() <= numRows)
    {
        return s;
    }
    for (int i = 0; i < numRows; i++)
    {
        int ev = (numRows - 1 - i) * 2;
        int odd = i * 2;
        int index = i;
        int counter = 0;
        while (index < s.length())
        {
            abc.append(s.substr(index, 1));
            if ((counter % 2 != 0 && odd != 0) || ev == 0)
            {
                index += odd;
            }
            else
            {
                index += ev;
            }
            counter++;
        }
    }
    return abc;
}
int main()
{
    string s = "PAYPALISHIRING";
    std::cout << convert(s, 2) << std::endl;
    return 0;
}
// PAHNAPLSIIGYIR
// PINALSIGYAHRPI