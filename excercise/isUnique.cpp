#include <string>

using namespace std;
bool isUnique(string a)
{
    // bit vector 32 bit assumed lowercase
    int checker = 0;
    for (auto i:a)
    {
        int val = i - 'a';
        if((checker & (1<<val)) > 0 )
        {
            return false;
        }
        checker = checker | (1<<val);
        
    }
    return true;
    
    
}