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
// iterative solution can be to use level order traversal.
int size(Node *root){
    if (root==NULL)
    return 0;
    return size(root->left)+size(root->right)+1;
}
int main(){
    Node *root=new Node(10);
    root->left=new Node(20);   
    root->right=new Node(30);   
    root->left->left=new Node(8);   
    root->left->right=new Node(7);   
    root->left->right->left=new Node(9);   
    root->left->right->right=new Node(15);   
    root->right->right=new Node(6);   
    cout << size(root);
    return 0;
}