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
int rec(TreeNode *root, int k, vector<int> &list)
{
    if (list.size() >= k)
    {
        return list[k - 1];
    }
    if (!root)
    {
        return -1;
    }
    int left = rec(root->left, k, list);
    list.push_back(root->val);
    int right = rec(root->right, k, list);
    return max(left, right);
}
int kthSmallest(TreeNode *root, int k)
{
    vector<int> list;
    return rec(root, k, list);
}
int main()
{

    return 0;
}
