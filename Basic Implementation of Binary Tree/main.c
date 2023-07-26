#include <stdio.h>
#include <stdlib.h>
struct BtNode {
  int data;
  struct BtNode* left;
  struct BtNode* right;
};
struct BtNode* GetNewNode(int data) {
  struct BtNode* newNode=(struct BtNode*)malloc(sizeof(struct BtNode));
  newNode->data=data;
  newNode->left=newNode->right=NULL;

  return newNode;
}
struct BtNode* InsertLeft(struct BtNode* root,int data) {
  root->left = GetNewNode(data);
  return root->left;
}
struct BtNode* InsertRight(struct BtNode* root,int data) {
  root->right = GetNewNode(data);
  return root->right;
}
void Print(struct BtNode* root) {
  if (root == NULL) return;
  printf("%d  ", root->data);
  Print(root->left);
  Print(root->right);
}
int main() {
  struct BtNode* root = GetNewNode(1);
  InsertLeft(root,5);
  InsertRight(root,3);
  InsertLeft(root->left,8);
  Print(root);
 return 0;
}
