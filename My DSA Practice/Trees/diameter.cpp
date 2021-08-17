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
int height(Node *root){
    if (root==NULL)
    return 0;
    return 1+max(height(root->left), height(root->right));
}
int dia(Node *root){ // O(n^2).
    if (root==NULL)
    return 0;
    int d1=1+height(root->left)+height(root->right);
    int d2=dia(root->left);
    int d3=dia(root->right);
    return max(max(d1,d2), d3);
}
int height1(Node *root, int &res){
    if(root==NULL)
        return 0;
    int lh=height1(root->left, res);
    int rh=height1(root->right, res);
    res=max(res,1+lh+rh);
    
        return 1+max(lh,rh);
}
int main(){
    Node *root=new Node(10);
    root->left=new Node(20);   
    root->right=new Node(30);    
    root->left->left=new Node(20);   
    root->right->left=new Node(6); 
    int ans=INT_MIN;
    height1(root, ans);
    cout << ans;
    return 0;
}