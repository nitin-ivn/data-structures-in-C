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
int IsSubTreeLesser(struct BstNode* root,int value)
{
    if(root==NULL) return 1;
    if(root->data <= value && IsSubTreeLesser(root->left,value) && IsSubTreeLesser(root->right,value))
        return 1;
    else return 0;
}
int IsSubTreeGreater(struct BstNode* root,int value)
{
    if(root==NULL) return 1;
    if(root->data > value && IsSubTreeGreater(root->left,value) && IsSubTreeGreater(root->right,value))
        return 1;
    else return 0;
}
int IsBinarySearchTree(struct BstNode* root)
{
    if(root==NULL) return 1;
    if(IsSubTreeLesser(root->left, root->data)==1 && IsSubTreeGreater(root->right,root->data)==1 && IsBinarySearchTree(root->left)==1 && IsBinarySearchTree(root->right)==1)
        return 1;
    else
        return 0;
}
int main()
{
struct BstNode* root=NULL;
root=Insert(root,15);
root=Insert(root,24);
root=Insert(root,25);
root=Insert(root,19);
root=Insert(root,14);
root=Insert(root,27);
root=Insert(root,15);
if(IsBinarySearchTree(root)==1)
    printf("Given Tree is a Binary Search Tree");
else
    printf("Given Tree is not a Binary Search Tree");
return 0;
}
