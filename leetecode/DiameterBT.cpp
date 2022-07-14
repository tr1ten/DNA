#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int height(TreeNode *root, int h)
{
    if (!root)
    {
        return h - 1;
    }
    return max(height(root->left, h + 1), height(root->right, h + 1));
}
int diameterOfBinaryTree(TreeNode *root)
{
    if(!root)
    {
        -1;
    }
    int left = height(root->left, 1);
    int right = height(root->right, 1);
    if(left>right)
    {
        return max(diameterOfBinaryTree(root->left),left+right);
    }
    return max(diameterOfBinaryTree(root->right),left+right);
}
int main()
{

    return 0;
}
