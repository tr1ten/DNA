#include <iostream>
#include <string>
using namespace std;
// naive way
// bool isPalidrome(string s)
// {
//     string reverseS;
//     for (int i = s.size() - 1; i >= 0; i--)
//     {
//         reverseS.push_back(s[i]);
//     }
//     return s == reverseS;
// }
// string longestPalindrome(string s)
// {
//     int n = s.size();
//     string longestString = s.substr(0, 1);
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             string substring = s.substr(i, j - i + 1);
//             if (isPalidrome(substring) && substring.size() > longestString.size())
//             {
//                 longestString = substring;
//             }
//         }
//     }
//     return longestString;
// }

// leetcode way
string longestPalindrome(string s)
{
    string palString;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        // odd
        int leftIndex = i;
        int rightIndex = i;
        while (leftIndex >= 0 && rightIndex < n)
        {
            if (s[leftIndex] != s[rightIndex])
            {

                break;
            }
            leftIndex--;
            rightIndex++;
        }
        leftIndex++;
        rightIndex--;

        if ((rightIndex - leftIndex + 1) > palString.size())
        {
            palString = s.substr(leftIndex, (rightIndex - leftIndex + 1));
        }
        // even
        leftIndex = i;
        rightIndex = i+1;
        while (leftIndex >= 0 && rightIndex < n)
        {
            if (s[leftIndex] != s[rightIndex])
            {

                break;
            }
            leftIndex--;
            rightIndex++;
        }
        leftIndex++;
        rightIndex--;

        if ((rightIndex - leftIndex + 1) > palString.size())
        {
            palString = s.substr(leftIndex, (rightIndex - leftIndex + 1));
        }

    }
    return palString;
}
int main()
{
    string s;
    getline(cin, s);
    cout << longestPalindrome(s) << endl;
    return 0;
}
