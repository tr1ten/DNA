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
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    auto temp = q;
    q = q->val > p->val ? q : p;
    p = temp->val > p->val ? p : temp;
    if (root == p || root == q || (root->val < q->val && root->val > p->val))
    {
        return root;
    }
    if (root->val > q->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    return lowestCommonAncestor(root->right, p, q);
}
int main()
{

    return 0;
}
