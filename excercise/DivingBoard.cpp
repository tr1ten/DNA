#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
void printAllLengths(int k,int cL,int l1,int l2,unordered_set<int> &hset)
{
    if(k<=0)
    {
        if(!hset.count(cL))
        {

        cout << cL << endl;
        hset.insert(cL);
        }
        return;
    }
    printAllLengths(k-1,cL+l1,l1,l2,hset);
    printAllLengths(k-1,cL+l2,l1,l2,hset);


}
int main()
{
    unordered_set<int> hset;
    printAllLengths(4,0,2,3,hset);
    return 0;
}
