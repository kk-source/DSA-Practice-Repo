#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};
void iterativeInorder(Node *root){
    if (root==NULL)
    return ;
    stack<Node *> st;
    Node *curr=root;
    while(curr!=NULL || st.empty()==false){
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top(); st.pop();
        cout << curr->key << " ";
        curr=curr->right;
    }
}
void iterativePreorder(Node *root){ // better.
    stack<Node *> st;
    Node *curr=root;
    while(curr!=NULL || st.empty()==false){
        while(curr!=NULL){
            cout << curr->key << " ";
            if (curr->right)
            st.push(curr->right);
            curr=curr->left;
        }
        if(st.empty()==false){
            curr=st.top(); st.pop();
        }
    }
}
void iterativePreorder1(Node *root){ // more space.
    if (root==NULL)
    return ;
    stack<Node *> st;
    st.push(root);
    while(st.empty()==false){
        Node *curr=st.top();
        cout << curr->key << " ";
        st.pop();
        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left); // because left is to be printed first.
    }
}
void iterativePostorder(Node *root){
    
    stack<Node*> st;
    st.push(root);
    if (root->right)
    st.push(root->right);
    if (root->left)
    st.push(root->left);
    while(st.empty()==false){
        Node *curr=st.top();
        if (root->right)
        st.push(root->right);
        if (root->left)
        st.push(root->left);

    }
}
int main() {
	Node *root=new Node(10);
    root->left=new Node(20);   
    root->right=new Node(30);    
    root->left->left=new Node(50);   
    root->left->left->left=new Node(70);   
    root->right->right=new Node(60); 
    // root->right->right->left=new Node(80); 
    root->right->right->right=new Node(90); 
    root->right->right->right->right=new Node(40); 
	iterativePreorder(root);
	
}