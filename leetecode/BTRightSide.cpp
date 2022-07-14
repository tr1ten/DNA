#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (!root)
    {
        return res;
    }
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty())
    {
        queue<TreeNode *> tque;
        vector<int> tres;
        while (!que.empty())
        {
            auto root = que.front();
            que.pop();
            tres.push_back(root->val);
            if (root->left)
            {
                tque.push(root->left);
            }
            if (root->right)
            {
                tque.push(root->right);
            }
        }
        res.push_back(tres);
        que = tque;
    }
    return res;
}
vector<int> rightSideView(TreeNode *root)
{
    auto lo = levelOrder(root);
    vector<int> rst;
    for (auto vec:lo)
    {
        rst.push_back(vec.back());
    }
    return rst;
}
int main()
{

    return 0;
}
