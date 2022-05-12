#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==p || root==q || !root){
        return root;
    }
    TreeNode *left = lowestCommonAncestor(root->left,p,q);
    TreeNode *right = lowestCommonAncestor(root->right,p,q);
    if(left && right)
    {
        return root;
    }
    if((left && !right) || (!left && right)){
        return left ? left : right;
    }
    return nullptr;
    

}
int main()
{
    
    return 0;
}
