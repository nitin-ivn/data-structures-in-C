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
int FindMin(struct BstNode* root)
{
    if(root==NULL){
     printf("Error. Tree is empty \n");
    return -1;
    }
    else if(root->left == NULL){
        return root->data;
    }
    return FindMin(root->left);
}
int FindMax(struct BstNode* root)
{
    if(root==NULL){
     printf("Error. Tree is empty \n");
    return -1;
    }
    else if(root->right == NULL){
        return root->data;
    }
    return FindMax(root->right);
}
void printTree(struct BstNode* root)
{
    if (root->left) printTree(root->left);
    printf("%d\n", root->data);
    if (root->right) printTree(root->right);
}
int main()
{
struct BstNode* root=NULL;
root=Insert(root,25);
root=Insert(root,7);
root=Insert(root,9);
root=Insert(root,20);
root=Insert(root,2);
printTree(root);
int min,max;
min=FindMin(root);
max=FindMax(root);
printf("Minimum value = %d \n", min);
printf("Maximum value = %d \n", max);
return 0;
}
