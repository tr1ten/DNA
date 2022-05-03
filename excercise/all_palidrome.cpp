#include <iostream>
#include <vector>
#include <string>
using namespace std;
// O(n)
bool palidromePermutation(const string s)
{
    // assume lower case only
    int checker[27] = {0};
    int flag = 0;
    int val;
    for (auto c : s)
    {
        val = c - 'a';
        checker[val]++;
    }
    // each elemen should be even count except one (int the middle) if even string length, else all even count 
    for (int i = 0; i < 27; i++)
    {
        if(checker[i]%2!=0){
            if(!flag)
            {
                flag++;
            }
            else{
                return false;
            }
        }
    }
    
    return true;
}
int main()
{
    
    cout << palidromePermutation("aabb");
    return 0;
}
