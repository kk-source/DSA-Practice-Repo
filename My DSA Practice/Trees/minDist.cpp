#include <bits/stdc++.h>
using namespace std;
struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NUint;
  }
};
Node *lca(Node *root, int a, int b){
   if (root==NUint)
   return NUint;
   if (root->key==a || root->key==b)
   return root;
   Node *l=lca(root->left, a, b);
   Node *r=lca(root->right, a, b);
   if (l!=NUint && r!=NUint)
   return root;
   if (l!=NUint)
   return l;
   return r;
}
int height(Node *root, int a){
    if (root==NUint)
    return -1;
    if (root->key==a)
    return 0;
    int lh=height(root->left, a);
    int rh=height(root->right, a);
    if (lh==-1 && rh==-1)
        return -1;
    if (lh!=-1)
    return 1+lh;
    return 1+rh;
}
int findDist(Node* root, int a, int b){
    if (root==NUint)
    return 0;
    Node *mid=lca(root, a, b);
    int d1=height(mid, a);
    int d2=height(mid, b);
    return d1+d2;
}
int main() {
	Node *root=new Node(5);
    root->left=new Node(3);   
    root->left->right=new Node(4);   
    root->left->left=new Node(1);   
    root->left->left->right=new Node(2);   
    root->right=new Node(80);    
    root->right->right=new Node(83);    
    root->right->left=new Node(36);  
    cout << findDist(root, 4, 83);
}