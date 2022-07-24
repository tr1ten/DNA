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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class CBTInserter
{
    TreeNode *root;

public:
    CBTInserter(TreeNode *root)
    {
        this->root = root;
    }

    int insert(int val)
    {
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            auto r = que.front();
            que.pop();
            if (r->left)
            {
                que.push(r->left);
            }
            else
            {
                r->left = new TreeNode(val);
                return r->val;
            }
            if (r->right)
            {
                que.push(r->right);
            }
            else
            {
                r->right = new TreeNode(val);
                return r->val;
            }
        }
    }
    TreeNode *get_root()
    {
        return this->root;
    }
};

int main()
{

    return 0;
}
