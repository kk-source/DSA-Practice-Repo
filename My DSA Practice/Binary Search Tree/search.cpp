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
bool search(Node *root, int data){ // recursive.
    if (root==NULL)
    return false;
    if (root->data==data)
    return true;
    return (root->data>data)? search(root->left, data): search(root->right, data);
}
bool search1(Node *root, int data){
    Node *curr=root;
    while(curr!=NULL){
        if (curr->data==data)
        return true;
        else if (curr->data<data)
        curr=curr->right;
        else 
        curr=curr->left;
    }
    return false;
}
int main(){
    Node *root=new Node(15);
    root->left=new Node(5);
    root->left->left=new Node(3);
    root->right=new Node(20);
    root->right->left=new Node(18);
    root->right->right=new Node(80);
    root->right->left->left=new Node(16);
    cout << search(root, 17);
    cout << search1(root, 17);
    return 0;
}