#include <bits/stdc++.h>
using namespace std;
struct Node  
{ 
  int data; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      data=k;
      left=right=NULL;
  }
};
void inOrder(Node *root){
    if (root==NULL)
    return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
Node* fun(Node *root, int &i, int k){
    if (root==NULL)
    return NULL;
    Node *l=fun(root->left, i, k);
    if (l!=NULL)
    return l;
    if (i==k)
    return root;
    i++;
    return fun(root->right, i, k);
}
int median(Node *root,int k){
    int i=1;
    Node *temp=fun(root, i, k);
    return temp->data;
}
int main(){
    Node *root=new Node(50);
    root->left=new Node(25);
    root->right=new Node(75);
    root->right->right=new Node(90);
    root->right->right->left=new Node(80);
    root->right->right->right=new Node(100);
    root->left->left=new Node(15);
    root->left->right=new Node(45);
    root->left->right->left=new Node(30);
    root->left->right->right=new Node(49);
    root->left->left->left=new Node(11);
    root->left->left->right=new Node(20);
	// inOrder(root);
    cout << median(root, 10);
    return 0;
}