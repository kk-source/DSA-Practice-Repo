#include <iostream>
#include <string>
using namespace std;
struct Node{
    int key;
    Node *left, *right;
    Node(int key){
        this->key=key;
        left=right=NULL;
    }
};
void preorder(Node *root){
    if (root!=NULL){
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Node *root){
    if (root!=NULL){
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
void postorder(Node *root){
    if (root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}
int main(){
    Node *root=new Node(30);
    root->left=new Node(40);  
    root->right=new Node(50);  
    root->left->left=new Node(70);  
    inorder(root);
    return 0;
}