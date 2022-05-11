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
#define MAX 10001
int subtreeHt(TreeNode* root)
{
    if(!root)
    {
        return 0;
    }
    int leftHt = 1 + subtreeHt(root->left);
    int rightHt = 1 + subtreeHt(root->right);
    return abs(leftHt-rightHt) > 1 : MAX : max(leftHt,rightHt);


}
bool isBalanced(TreeNode* root) 
{
    return subtreeHt(root) == MAX ? true : false           
}
int main()
{
    
    return 0;
}
