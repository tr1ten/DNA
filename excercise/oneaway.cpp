#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isOneAway(const string original,const string test)
{
    int n1 = original.size();
    int n2 = test.size();
    if(abs(n2-n1)>1)
    {
        return false;
    }
    if(n2==n1)
    {
        int c=0;
        for (int i = 0; i < n1 && c < 2; i++)
        {
            if(original[i]!=test[i])
            {
                c++;
            }

        }
        if(c>1)
        {
            return false;
        }
        return true;
        
    }
    else 
    {
        int smaller = n1<n2 ? n1 : n2;
        string higher = n1>n2 ? original : test;
        string lower = n1<n2 ? original : test;
        int ph = 0;
        int pl = 0;
        int c= 0;
        while (pl<smaller)
        {
            if(higher[ph]!=lower[pl])
            {
                c++;
                ph++;
            }
            else{
                pl++;
                ph++;
            }
        }
        if(c>1)
        {
            return false;

        }
        return true;
        

    }
    
}
int main()
{
    cout << isOneAway("pale","bake");
    return 0;
}
