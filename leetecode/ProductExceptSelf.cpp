#include <iostream>
#include <vector>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) 
{
    int n=nums.size();
    vector<int> prefix(n,1);
    vector<int> postfix(n,1);
    int prod=nums[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prod;
        prod *=nums[i];
    }
    prod=nums[n-1];
    for (int i = n-2; i >=0; i--)
    {
        postfix[i] = prod;
        prod *=nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        nums[i] = prefix[i]*postfix[i];
    }
    return nums;
    
}
int main()
{
    vector<int> a={1,2,3,4};
    cout<<productExceptSelf(a)[1];
    return 0;
}
