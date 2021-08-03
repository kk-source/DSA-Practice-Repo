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
Node *insert(Node *root, int key){ // iterative.
    if (root==NULL){
        root=new Node(key);
        return root;
    }
    Node *curr=root;
    Node *prev=root;
    while(curr!=NULL){
        prev=curr;

        if (curr->data==key)
        return root;

        else if (curr->data<key)
        curr=curr->right;
        
        else
        curr=curr->left;
        
    }
    curr=new Node(key);
    
    (prev->left)? prev->right=curr:prev->left=curr;
    return root;
}
Node* insert1(Node* root, int key){ //recursive.
    if (root==NULL)
    return new Node(key);

    if (root->data<key)
    root->right=insert1(root->right, key);
    else if (root->data>key)
    root->left=insert1(root->left, key);

    return root;
}
void levelOrder(Node *root){
    if (root==NULL)
    return;
    queue<Node*> q;
    q.push(root);
    while(q.empty()==false){
        Node *curr=q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left)
        q.push(curr->left);
        if (curr->right)
        q.push(curr->right);
    }
}
int main(){
    Node *root=new Node(15);
    root->left=new Node(5);
    root->left->left=new Node(3);
    root->right=new Node(20);
    root->right->left=new Node(18);
    root->right->right=new Node(80);
    root->right->left->left=new Node(16);
    root=insert(root, 14);
    levelOrder(root);
    cout << endl;
    insert1(root, 14);
    levelOrder(root);
    return 0;
}