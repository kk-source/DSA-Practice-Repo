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
Node *del1(Node *root, int key){
    if (root==NULL)
    return root;

    if (root->data<key)
    root->right=del1(root->right, key);

    else if (root->data>key)
    root->left=del1(root->left, key);

    else {
        // if (root->left==NULL && root->right==NULL){ // leaf node.
        // delete root;
        // return NULL;
        // }
        if (root->left==NULL || root->right==NULL){ // either side NULL.
            Node *next=(root->left)? root->left:root->right;
            delete root;
            return next;
        }
        else{ // two children.
            Node *temp=root->right;
            while(temp->left!=NULL)
            temp=temp->left;
            root->data=temp->data;
            root->right=del1(root->right, temp->data);

            // Node *temp=root->left;
            // while(temp->right!=NULL)
            // temp=temp->right;
            // root->data=temp->data;
            // root->left=del1(root->left, temp->data);
        }
    }
    return root;
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
    inOrder(root);
    cout << endl;
    root=del1(root, 15);
    inOrder(root);
    return 0;
}