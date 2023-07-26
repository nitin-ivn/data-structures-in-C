#include <stdio.h>
#include <stdlib.h>
struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};
struct BstNode* GetNewNode(int data){
         struct BstNode* newNode=(struct BstNode*)malloc(sizeof(struct BstNode));
          newNode->data=data;
          newNode->left=newNode->right=NULL;
          return newNode;
}
struct BstNode* Insert(struct BstNode* root, int data){
   if(root==NULL)
    {
        root=GetNewNode(data);
    }
    else if(data<=root->data)
    {
        root->left=Insert(root->left,data);
    }
    else
    {
        root->right=Insert(root->right,data);
   }
   return root;
}
void Preorder(struct BstNode* root)
{
    if(root==NULL) return;
    printf("%d  ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(struct BstNode* root)
{
    if(root==NULL) return;
    Inorder(root->left);
    printf("%d  ", root->data);
    Inorder(root->right);
}
void Postorder(struct BstNode* root)
{
    if(root==NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d  ", root->data);
}
int main()
{
struct BstNode* root=NULL;
root=Insert(root,25);
root=Insert(root,7);
root=Insert(root,9);
root=Insert(root,10);
root=Insert(root,2);
root=Insert(root,14);
printf("Preorder = ");
Preorder(root);
printf("\nInorder = ");
Inorder(root);
printf("\nPostorder = ");
Postorder(root);
return 0;
}
