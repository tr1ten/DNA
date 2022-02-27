#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int hIndex(vector<int>& citations) {

    int N = citations.size();
    // if(N==1 && citations[0]==0){
    //     return 0;
    // }
    int high = citations.size()-1;
    int low = 0;
    int mid;
    while (high>=low)
    {
        mid = (high+low)/2;
        if(citations[mid]==(N-mid))
        {
            return citations[mid];
        }
        else if(citations[mid]<(N-mid))
        {
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return (N-high-1);
}
int main()
{
    vector<int> arr = {0};
    cout << hIndex(arr) << endl;
    return 0;
}
