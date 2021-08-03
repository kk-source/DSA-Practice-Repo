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
Node* floor(Node* root, int key){
    Node *res=NULL;
    while(root!=NULL){
        if (root->data==key)
        return root;

        else if (root->data>key)
        root=root->left;
        
        else{
            res=root;
            root=root->right;
        }
    }
    return res;
}
void inOrder(Node *root){
    if (root==NULL)
    return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main(){
    Node *root=new Node(15);
    root->left=new Node(5);
    root->left->left=new Node(3);
    root->right=new Node(20);
    root->right->left=new Node(18);
    root->right->right=new Node(80);
    root->right->left->left=new Node(16);
    int key; cin >> key;
    if (floor(root, key))
    cout << floor(root, key)->data;
    return 0;
}