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
TreeNode *rec(vector<int> &preorder, vector<int> &inorder, int pres, int ins, int n)
{
    if(n==0)
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[pres]);
    if (n == 1)
    {
        return root;
    }
    int i = 0;
    while (root->val != inorder[ins + i])
    {
        i++;
    }
    root->left = rec(preorder,inorder,pres+1,ins,i);
    root->right = rec(preorder,inorder,pres+1+i,ins+i+1,n-i-1);
    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    return rec(preorder, inorder,0,0,preorder.size());
}
int main()
{

    return 0;
}
