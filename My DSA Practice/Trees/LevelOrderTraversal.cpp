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
void BFT(Node *root){
    if (root==NULL)
    return;
    queue<Node *> q;
    q.push(root);
    while(q.empty()==false){
        Node *curr=q.front();
        q.pop();
        cout << curr->key << " ";
        if (curr->left)
        q.push(curr->left);
        if (curr->right)
        q.push(curr->right);
    }
}
void BFT1(Node *root){ // line by line
    if (root==NULL)
    return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(q.size()!=1){
        Node *curr=q.front();
        q.pop();
        if (curr==NULL){
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << curr->key << " ";
        if (curr->left)
        q.push(curr->left);
        if (curr->right)
        q.push(curr->right);
    }
}
void BFT2(Node *root){ // line by line
    if (root==NULL)
    return;
    queue<Node *> q;
    q.push(root);
    while(q.empty()==false){
    int n=q.size();
        while(n--){
            Node *curr=q.front();
            q.pop();
            cout << curr->key << " ";
            if (curr->left)
            q.push(curr->left);
            if (curr->right)
            q.push(curr->right);
        }
        cout << endl;
    }
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
    BFT2(root);

    return 0;
}