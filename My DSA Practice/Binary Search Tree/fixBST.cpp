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
Node* check1(Node *root, int minval, int maxval){
    if (root==NULL)
    return root;
    if (root->data>maxval || root->data<minval)
    return root;
    Node *ls=check1(root->left, minval, root->data);
    Node *rs=check1(root->right, root->data, maxval);
    if (ls!=NULL)
    return ls;
    return rs;
}
void fix1(Node *root){
    int minval=INT_MIN;
    int maxval=INT_MAX;
    Node *ls=(check1(root->left, minval, root->data));
    Node *rs=check1(root->right, root->data, maxval);
    if (ls==NULL && rs==NULL)
    return;
    else if (ls==NULL)
    swap(root->data, rs->data);
    else if (rs==NULL)
    swap(root->data, ls->data);
    else
    swap(ls->data, rs->data);
}
void check2(Node *root, Node* &prev, Node* &first, Node* &second){
    if (root==NULL)
    return;
    check2(root->left, prev, first, second);
    if (prev!=NULL && root->data<prev->data){
        if (first==NULL)
        first=prev;
        second=root;
    }
    prev=root;
    check2(root->right, prev, first, second);
}
void fix2(Node *root){
    Node *prev=NULL, *first=NULL, *second=NULL;
    check2(root, prev, first, second);
    swap(first->data, second->data);
}
int main(){
    Node *root=new Node(60);
    root->left=new Node(8);
    root->left->left=new Node(4);
    root->left->right=new Node(10);
    root->right=new Node(80);
    root->right->right=new Node(100);
    root->right->left=new Node(20);
    inOrder(root);
    cout << endl;
    fix2(root);
    inOrder(root);
    return 0;
}