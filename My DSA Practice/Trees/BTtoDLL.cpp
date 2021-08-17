#include <iostream>
#include <string>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node (int key){
        data=key;
        left=right=NULL;
    }
};
void print(Node *root){
    while(root!=NULL){
        cout << root->data << " ";
        root=root->right;
    }
}
Node *DLL(Node *root){
    if(root==NULL)return root;
    static Node *prev=NULL;
    Node *head=DLL(root->left);
    if(prev==NULL){head=root;}
    else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    DLL(root->right);
    return head;
}
int main(){
    Node *root=new Node(10);
    root->left=new Node(8);    
    root->left->left=new Node(7);   
    root=DLL(root);
    print(root);
    return 0;
}