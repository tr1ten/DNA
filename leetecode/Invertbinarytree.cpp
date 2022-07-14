#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void rec(TreeNode* root)
{
    if(!root)
    {
        return;
    }
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = root->left;
    rec(root->left);
    rec(root->right);
}
TreeNode* invertTree(TreeNode* root) {
    rec(root);
    return root;
}
int main()
{
    auto left = new TreeNode(2);
    auto right = new TreeNode(7);
    auto root = new TreeNode(4,left,right);
    invertTree(root);
    return 0;
}
