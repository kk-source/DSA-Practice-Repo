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
Node *insert(Node *root, int k){
    if (root==NULL)
    return new Node(k);
    else if (root->data<k){
        root->right=insert(root->right, k);
    }
    else if(root->data>k){
        root->left=insert(root->left, k);
    }
    return root;
}
bool check(Node *root, Node *curr){ // inefficient.
    if (curr==NULL)
    return true;
    Node *temp=root;
    while(temp!=NULL){
        if(temp->data==curr->data)
        break;
        else if (temp->data<curr->data)
        temp=temp->right;
        else
        temp=temp->left;
    }
    if (temp==NULL)
    return false;
    return (check(root, curr->left) && check(root, curr->right));
}
bool check1(Node *root, int minval=INT_MIN, int maxval=INT_MAX){
    if (root==NULL)
    return true;
    return (root->data<maxval && root->data>minval) && check1(root->left, minval, root->data) && check1(root->right, root->data, maxval);
}
bool check2(Node *root, int &prev){
    if (root==NULL)
    return true;
    if (check2(root->left, prev)==false)
    return false;
    if (root->data<prev)
    return false;
    prev=root->data;
    return check2(root->right, prev);
}
int main(){
    // int arr[]={10,8,20,13,24};
    // int n=sizeof(arr)/sizeof(int);
    // Node *root=NULL;
    // for (auto i:arr)
    // root=insert(root, i);
    Node *root=new Node(20);
    root->left=new Node(8);
    root->right=new Node(30);
    root->right->right=new Node(35);
    root->left->right=new Node(18);
    // cout << check(root, root);
    // cout << check1(root);
    int prev=INT_MIN;
    cout << check2(root, prev);
    return 0;
}