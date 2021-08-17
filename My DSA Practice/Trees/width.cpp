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

int width(Node *root){
    if (root==NULL)
    return 1;
    queue<Node *> q;
    q.push(root);
    int maxval=0;
    while(q.empty()==false){
        int n=q.size();
        maxval=max(n, maxval);
        while(n--){
            Node *curr=q.front();
            q.pop();
            if (curr->left)
            q.push(curr->left);
            if (curr->right)
            q.push(curr->right);
        }
    }
    return maxval;
}
int main(){
    Node *root=new Node(20);
    root->left=new Node(8);   
    root->right=new Node(12);   
    root->left->left=new Node(3);   
    root->left->left->left=new Node(3);   
    root->right->left=new Node(12);   
    root->right->right=new Node(12);   
    // root->left->right=new Node(5);   
    // root->left->left->left=new Node(3);   

    // root->left->right->left=new Node(9);   
    // root->left->right->right=new Node(15);   
    // root->right->left=new Node(6);   
    // root->right->right->left=new Node(6);  
    cout << width(root);
    return 0;
}