#include <iostream>
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
    return max(height(root->left), height(root->right))+1;
}
int main(){
    Node *root=new Node(30);
    root->left=new Node(40);  
    root->left->left=new Node(70);  
    root->left->left->left=new Node(80);  
    root->right=new Node(60);  
    // root->right->left=new Node(40);  
    // root->right->right=new Node(50);  
    // root->right->right->left=new Node(70);  
    cout << height(root);
    return 0;
}