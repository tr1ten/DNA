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
bool rec(TreeNode* root, TreeNode* subRoot,TreeNode* targetRoot)
{
    if(!root)
    {
        return !subRoot ? true : false;
    }
    if(!subRoot)
    {
        return rec(root,targetRoot,targetRoot);
    }
    if (root->val==subRoot->val)
    {
        return rec(root->left,subRoot->left,targetRoot) && rec(root->right,subRoot->right,targetRoot);
    }
    return rec(root->left,targetRoot,targetRoot) || rec(root->right,targetRoot,targetRoot);

    
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    return rec(root,subRoot,subRoot);
}
int main()
{
    
    return 0;
}
