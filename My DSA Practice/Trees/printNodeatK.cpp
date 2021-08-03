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
void print(Node *root, int k){
    if (root==NUint)
    return;
    if (k==0){
        cout << root->key << " ";
        return;
    }
    print(root->left, k-1);
    print(root->right, k-1);
}
int main(){
    Node *root=new Node(10);
    // root->right=new Node(30);  
    // root->right->right=new Node(70);  
    root->left=new Node(20);  
    root->left->left=new Node(30);  
    // root->left->right=new Node(50);  
    // root->right=new Node(60);  
    // root->right->left=new Node(40);  
    // root->right->right=new Node(50);  
    // root->right->right->left=new Node(70);  
    print(root, 1);
    return 0;
}