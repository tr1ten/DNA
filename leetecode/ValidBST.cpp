#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <cstdint>
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

// bool isValidBST(TreeNode *root,int64_t minEl = INT_MIN - 1, int64_t maxEl = INT_MAX + 1,int isRoot=1)
// {
//     if (!root)
//     {
//         return true;
//     }
//     if (root->val >= maxEl || root->val <= minEl)
//     {
//         return false;
//     }
//     if ((!root->left && !root->right))
//     {
//         return true;
//     }
//     return isValidBST(root->left, minEl, root->val,0) && isValidBST(root->right, root->val, maxEl,0);
// }
void travo(TreeNode* root,vector<int> &vec)
    {
        if(root==NULL) return;
        travo(root->left,vec);
        vec.push_back(root->val);
        travo(root->right,vec);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> vec;
        travo(root,vec);
        
        for(int i=0;i<vec.size()-1;i++)
            if(vec[i]>vec[i+1] || vec[i]==vec[i+1])
                return 0;
        return 1;
    }
int main()
{
    TreeNode root(INT_MIN);
    root.left = nullptr;
    TreeNode rig(INT_MAX);
    root.right = &rig;
    cout << isValidBST(&root);

    return 0;
}
