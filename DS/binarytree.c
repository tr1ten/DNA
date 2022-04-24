#include <stdio.h>
typedef struct TNode 
{
    int data;
    struct TNode* left;
    struct TNode* right;
    
} Node;

void preorder(Node* root)
{
    if (!root)
    {
        return;
    }
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
    
}
void postorder(Node* root)
{
    if (!root)
    {
        return;
    }
    preorder(root->left);
    preorder(root->right);
    printf("%d",root->data);
    
}
void inorder(Node* root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    printf("%d ->",root->data);
    inorder(root->right);
    
}
int isSBT(Node* root,int min,int max)
{
    if((max!=NULL && root->data >= max )|| (min!=NULL && root->data <=min ))
    {
        return 0;
    }
    if(!root || !root->left || !root->right)
    {
        return 1;
    }
    if(root->left->data > root->data || root->right->data < root->data )
    {
        return 0;
    }
    
    return isSBT(root->left,min,root->data) && isSBT(root->right,root->data,max);
}
int main()
{
    Node root={40,NULL,NULL};
    Node child1 = {30,NULL,NULL};
    Node child2 = {50,NULL,NULL};
    root.left = &child1;
    root.right = &child2;
    Node child3 = {20,NULL,NULL};
    Node child4 = {41,NULL,NULL};
    Node child5 = {49,NULL,NULL};
    Node child6 = {51,NULL,NULL};
    child1.left = &child3;
    child1.right = &child4;
    child2.left = &child5;
    child2.right = &child6;


    // preorder(&root);
    // printf("\n");
    // postorder(&root);
    printf("\n");
    inorder(&root);
    printf("\n");

    if(isSBT(&root,NULL,NULL)){
        printf("yes");
    }
    else{
        printf("no");
    }

    return 0;
}
