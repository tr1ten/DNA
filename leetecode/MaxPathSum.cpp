#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 0: if path split
// 1: if not
vector<int> rec(TreeNode *root)
{
    if (!root)
    {
        return {-1001, -1001};
    }
    auto left = rec(root->left);
    auto right = rec(root->right);
    int ps = max(max(max(max(left[0], right[0]), left[1] + right[1] + root->val),root->val),max(left[1], right[1]));
    int nps = max(max(left[1], right[1]) + root->val,root->val);
    return {ps, nps};
}

int maxPathSum(TreeNode *root)
{
    auto res = rec(root);
    return max(res[0], res[1]);
}

int main()
{

    return 0;
}
