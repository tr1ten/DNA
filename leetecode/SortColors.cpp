#include <iostream>
#include <vector>
#include <string>
using namespace std;
void sortColors(vector<int>& nums) {
    int arr[3]={0,0,0};
    for (auto i:nums)
    {
        arr[i]++;
    }
    int j=0;
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < arr[i]; k++)
        {
            nums[j] = i;
            j++;
        }        
    }
}
int main()
{
    
    return 0;
}
