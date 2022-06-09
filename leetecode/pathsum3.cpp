#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
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
// int rec(TreeNode *root, int csum, int targetSum)
// {
//     if (!root)
//     {
//         return 0;
//     }
//     if (csum + root->val == targetSum)
//     {
//         return 1 + rec(root->left, root->val, targetSum) + rec(root->right, root->val, targetSum);
//     }
//     int tempsum = ((csum + root->val) > targetSum ? root->val : csum + root->val);
//     if(tempsum > root->val)
//     {

//     return rec(root->left, tempsum, targetSum) + rec(root->right, tempsum, targetSum) + rec(root->left, root->val, targetSum) + rec(root->right, root->val, targetSum);
//     }
//     return rec(root->left, tempsum, targetSum) + rec(root->right, tempsum, targetSum);
// }
// int pathSum(TreeNode *root, int targetSum)
// {
//     return rec(root, 0, targetSum);
// }
// int pathSum(TreeNode* root, int sum) {
//     unordered_map<long long int,long long int> m;
//     m[0]++;

//     long long int total = 0;
//     helper(root, 0, sum, total, m);
//     return total;
// }

// void helper(TreeNode *p, long long int cur, long long int sum, long long int &total, unordered_map<long long int, long long int> &m) {
//     if (!p) return;

//     cur += p->val;
//     if (m.find(cur - sum) != m.end()) total += m[cur - sum];
//     m[cur]++;

//     helper(p->left, cur, sum, total, m);
//     helper(p->right, cur, sum, total, m);

//     m[cur]--;
// }
// O(N) 
int pathSum(TreeNode *root, int targetSum)
{
    int total = 0;
    unordered_map<int, int> hashmap;
    hashmap[0] = 1;
    rec(root, 0, targetSum, total, hashmap);
    return total;
}
void rec(TreeNode *root, int sum, int target, int &total, unordered_map<int, int> &hashmap)
{
    if (!root)
    {
        return;
    }
    int summ = sum + root->val;
    if (hashmap.count(summ - target))
    {
        total += hashmap[summ - target];
    }

    hashmap[summ] = hashmap.count(summ) ? hashmap[summ] + 1 : 1;

    rec(root->left, summ, target, total, hashmap);
    rec(root->right, summ, target, total, hashmap);
    hashmap[summ] -= 1;
    return;
}
int main()
{

    return 0;
}
