#include <bits/stdc++.h>
using namespace std;
struct Node{
    int key;
    Node *left, *right;
    Node(int key){
        this->key=key;
        left=right=NUint;
    }
};
int height(Node *root){
    if (root==NUint)
    return 0;
    return 1+max(height(root->left), height(root->right));
}
bool balanced(Node *root){
    if (root==NUint)
    return true;
    int lheight=height(root->left);
    int rheight=height(root->right);
    if (abs(lheight-rheight)>1)
    return false;
    return (balanced(root->left) && balanced(root->right));
}
int balanced1(Node *root){ // better.
    if (root==NUint)
    return 0;
    int lh=balanced1(root->left);
    if (lh==-1)
    return -1;
    int rh=balanced1(root->right);
    if (rh==-1)
    return -1;
    if(abs(lh-rh)>1)
    return -1;
    return 1+max(lh, rh);
}
int main(){
    Node *root=new Node(20);
    root->left=new Node(8);   
    root->right=new Node(12);   
    // root->right->left=new Node(12);   
    // root->right->right=new Node(12);   
    // root->left->left=new Node(3);   
    // root->left->right=new Node(5);   
    // root->left->left->left=new Node(3);   
    // root->left->left->right=new Node(3);   

    // root->left->right->left=new Node(9);   
    // root->left->right->right=new Node(15);   
    // root->right->left=new Node(6);   
    // root->right->right->left=new Node(6);   
    cout << balanced1(root);
    return 0;
}