#include <iostream>
#include <vector>
#include <string>
using namespace std;

void urlify(string &a)
{
    int p1=a.size()-1;
    int p2=a.size()-2;
    while (p2>=0)
    {
        int ap2 = a[p2];
        if(a[p2+1]==32 && ap2!=32)
        {
            while (a[p2]!=32 && p2>=0)
            {
                a[p1] = a[p2];
                a[p2] = 32;
                p2--;
                p1--;
            }
            if(a[p2]==32)
            {
                a[p1] = '0';
                a[p1-1] = '2';
                a[p1-2] = '%';
                p1 = p1-3;
            }
            
        }
        else{
            p2--;
        }
    }
    
}
int main()
{
    string s = "Mr John Smith    ";
    urlify(s);
    cout << s;
    return 0;
}
