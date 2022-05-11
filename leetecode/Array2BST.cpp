#include <iostream>
#include <vector>
#include <string>
using namespace std;
// O(2^n)
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int n =nums.size();
    switch (n)
    {
    case 0:
    return nullptr;
    case 1:
        return new TreeNode(nums[0]);
    
    default:
        int mid = n/2;
        auto leftarr = vector<int>(nums.begin(), nums.begin()+mid);
        auto rightarr = vector<int>(nums.begin()+mid+1, nums.end());
        return new TreeNode(nums[mid],sortedArrayToBST(leftarr),sortedArrayToBST(rightarr));
    }
}
int main()
{

    return 0;
}
