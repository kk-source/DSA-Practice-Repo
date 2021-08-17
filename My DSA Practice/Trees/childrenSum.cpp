#include <bits/stdc++.h>
using namespace std;
struct Node{
    int key;
    Node *left, *right;
    Node(int key){
        this->key=key;
        left=right=NULL;
    }
};
bool property(Node *root){
    if (root==NULL || (root->left==NULL && root->right==NULL)) return true;
    int lval=(root->left)? root->left->key:0;
    int rval=(root->right)? root->right->key:0;
    if (root->key != lval+rval){
    return false;
    }
    return (property(root->left) && property(root->right));
}
int main(){
    Node *root=new Node(20);
    root->left=new Node(8);   
    root->right=new Node(12);   
    root->left->left=new Node(3);   
    root->left->right=new Node(5);   
    // root->left->right->left=new Node(9);   
    // root->left->right->right=new Node(15);   
    // root->right->right=new Node(6);   
    cout << property(root);
    return 0;
}