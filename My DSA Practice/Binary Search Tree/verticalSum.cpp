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
void sum(Node *root, map<int, int> &mp, int lvl=0){
    if (root==NULL)
    return;
    // can take any traversal.
    sum(root->left, mp, lvl-1);
    mp[lvl]=mp[lvl]+root->data;
    sum(root->right, mp, lvl+1);
}
void bin(Node *root){
    map<int, int> mp;
    sum(root, mp);
    for (auto i: mp)
    cout << i.second << " ";
}
int main(){
    Node *root=new Node(0);
    root->left=new Node(15);
    root->right=new Node(25);
    root->left->left=new Node(35);
    root->left->left->left=new Node(40);
    root->left->right=new Node(20);
    root->left->right->right=new Node(75);
    root->left->right->right->right=new Node(80);
    bin(root);
    return 0;
}