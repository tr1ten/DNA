#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
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
// timeout on bfs
#define NULLME -1001
// class CBTInserter
// {
//     TreeNode *root;

// public:
//     CBTInserter(TreeNode *root)
//     {
//         this->root = root;
//     }

//     void insert(int val)
//     {
//         queue<TreeNode *> que;
//         TreeNode *newNode;
//         newNode = new TreeNode(val);
//         if (!root)
//         {
//             this->root = newNode;
//             return;
//         }
//         que.push(root);
//         while (!que.empty())
//         {
//             auto r = que.front();
//             que.pop();
//             if (r->left)
//             {
//                 if (r->left->val != NULLME)
//                 {

//                     que.push(r->left);
//                 }
//             }
//             else
//             {
//                 r->left = newNode;
//                 return;
//             }
//             if (r->right)
//             {
//                 if (r->right->val != NULLME)
//                 {

//                     que.push(r->right);
//                 }
//             }
//             else
//             {
//                 r->right = newNode;
//                 return;
//             }
//         }
//     }
//     TreeNode *get_root()
//     {
//         return this->root;
//     }
// };

// void sanitize(TreeNode *root)
// {
//     if (!root)
//     {
//         return;
//     }
//     if (root->left && root->left->val == NULLME)
//     {
//         root->left = nullptr;
//     }
//     if (root->right && root->right->val == NULLME)
//     {
//         root->right = nullptr;
//     }
//     sanitize(root->left);
//     sanitize(root->right);
// }
// vector<int> levelOrder(TreeNode *root)
// {
//     vector<int> res;
//     if (!root)
//     {
//         return res;
//     }
//     queue<TreeNode *> que;
//     que.push(root);
//     while (!que.empty())
//     {
//         auto r = que.front();
//         que.pop();
//         if (!r)
//         {
//             res.push_back(NULLME);
//             continue;
//         }
//         else
//         {

//             res.push_back(r->val);
//         }
//         que.push(r->left);
//         que.push(r->right);
//     }
//     return res;
// }


// string serialize(TreeNode *root)
// {
//     auto vec = levelOrder(root);
//     return serializeVector(vec);
// }

// // Decodes your encoded data to tree.
// TreeNode *deserialize(string data)
// {
//     vector<int> levelOrder = deserializeVector(data);
//     CBTInserter tree(nullptr);
//     for (auto v : levelOrder)
//     {
//         tree.insert(v);
//     }
//     auto root = tree.get_root();
//     sanitize(root);
//     return root;
// }

// dfs
string serializeVector(vector<int> &vec)
{
    int n = vec.size();
    if (!n)
    {
        return "";
    }
    string res;
    for (int i = 0; i < n; i++)
    {
        res += (to_string(vec[i]) + ",");
    }
    return res;
}
vector<int> deserializeVector(string s)
{
    int start = 0;
    int end = 0;
    vector<int> res;
    while (start < s.size())
    {
        end = s.find(",", start);
        int a = atoi(s.substr(start, end - start).c_str());
        res.push_back(a);
        start = end + 1;
    }
    return res;
}
void preorder(TreeNode *root, vector<int> &res)
{
    if (!root)
    {
        res.push_back(NULLME);
        return;
    }
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
}
string serialize(TreeNode *root)
{
    vector<int> vec;
    preorder(root, vec);
    return serializeVector(vec);
}

void rec(TreeNode **root, int &i, vector<int> &vec)
{
    if (i >= vec.size() || vec[i] == NULLME)
    {
    *root = nullptr;    
        return;
    }
    *root = new TreeNode(vec[i]);
    i++;
    rec(&((*root)->left), i, vec);
    i++;
    rec(&((*root)->right), i, vec);
}
// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    auto vec = deserializeVector(data);
    TreeNode *root;
    int i=0;
    rec(&root,i,vec);
    return root;
}
int main()
{
    // generate this tree [1,2,3,null,null,4,5]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    auto s = serialize(root);
    cout << s<< endl;
    auto boot = deserialize(s);
    return 0;
}
