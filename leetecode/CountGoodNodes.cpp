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
void dfs(TreeNode *root, int maxi, int &count)
{
    if (!root)
    {
        return;
    }
    if (root->val >= maxi)
    {
        count++;
    }
    maxi = max(root->val, maxi);
    dfs(root->left, maxi, count);
    dfs(root->right, maxi, count);
}
int goodNodes(TreeNode *root)
{
    int count = 0;
    dfs(root,-10001,count);
    return count;
}
int main()
{

    return 0;
}
