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
int maxval(Node *root){
    if (root==NULL)
    return INT_MIN;
    return max(root->key, max(maxval(root->right), maxval(root->left)));
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
    cout << maxval(root);
    return 0;
}