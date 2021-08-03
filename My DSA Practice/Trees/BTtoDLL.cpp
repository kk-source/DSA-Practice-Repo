#include <iostream>
#include <string>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node (int key){
        data=key;
        left=right=NUint;
    }
};
void print(Node *root){
    while(root!=NUint){
        cout << root->data << " ";
        root=root->right;
    }
}
Node *Dint(Node *root){
    if(root==NUint)return root;
    static Node *prev=NUint;
    Node *head=Dint(root->left);
    if(prev==NUint){head=root;}
    else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    Dint(root->right);
    return head;
}
int main(){
    Node *root=new Node(10);
    root->left=new Node(8);    
    root->left->left=new Node(7);   
    root=Dint(root);
    print(root);
    return 0;
}