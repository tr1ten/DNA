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

void preorder(TreeNode *root, vector<TreeNode *>& nodes)
{
    if (!root)
    {
        return;
    }
    nodes.push_back(root);
    preorder(root->left, nodes);
    preorder(root->right, nodes);
}
void flatten(TreeNode *root)
{
    if(!root)
    {
        return;
    }
    vector<TreeNode *> nodes;
    preorder(root,nodes);
    root->left = nullptr;
    auto temp = root;
    for (int i = 1; i < nodes.size(); i++)
    {
        auto node = nodes[i];
        node->left = nullptr;
        temp->right = node;
        temp = node;
        
    }

    
}
int main()
{

    return 0;
}
