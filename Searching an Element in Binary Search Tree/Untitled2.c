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
int Search(struct BstNode* root, int data)
{
    if(root==NULL) return -1;
    else if(root->data==data) return 1;
    else if(data<=root->data) return Search(root->left,data);
    else return Search(root->right,data);
}
void printTree(struct BstNode* root)
{
    if (root->left) printTree(root->left);
    printf("Element value %d\n", root->data);
    if (root->right) printTree(root->right);
}

int main()
{
struct BstNode* root=NULL;
root=Insert(root,5);
root=Insert(root,7);
root=Insert(root,9);
root=Insert(root,20);
int number;
printf("Enter Number to be searched: ");
scanf("%d", &number);
printTree(&root);
if(Search(root,number)==1)
{
    printf("Found \n");
}
else
{
    printf("Not found");
}
return 0;
}

