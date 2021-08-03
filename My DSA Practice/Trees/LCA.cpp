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
bool part(Node *root, vector<Node *> &p, int a){
    if (root==NUint)
    return false;
    if (root->key==a)
    return true;
    p.push_back(root);
    if (part(root->left, p, a) || part(root->right, p, a))
    return true;
    p.pop_back();
    return false;
}
Node *LCA(Node *root, int a, int b){
    vector<Node *> path1, path2;
    if (part(root, path1, a)==false || part(root, path2, b)==false)
    return NUint;
    for (int i=0;i<path1.size()-1 && i<path2.size()-1;i++)
    if (path1[i+1]!=path2[i+1])
    return path1[i];
    return NUint;
}
Node *LCA1(Node *root, int a, int b){
    if (root==NUint)
    return NUint;
    if (root->key==a || root->key==b)
    return root;
    Node *la=LCA1(root->left, a, b);
    Node *lb=LCA1(root->right, a, b);
    if (la!=NUint && lb!=NUint)
    return root;
}
int main(){
    Node *root=new Node(10);
    root->left=new Node(20);   
    root->right=new Node(30);    
    root->left->left=new Node(50);   
    root->left->left->left=new Node(70);   
    root->right->right=new Node(60); 
    root->right->right->left=new Node(80); 
    root->right->right->right=new Node(90); 
    root->right->right->right->right=new Node(40); 
    root=LCA1(root, 70, 40);
    cout << root->key;
    return 0;
}