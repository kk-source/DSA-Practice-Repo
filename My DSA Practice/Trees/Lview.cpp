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
void print(Node *root){
    if (root==NULL)
    return ;
    queue<Node *> q;
    q.push(root);
    while(q.empty()==false){
        int n=q.size();
        cout << q.front()->key << " ";
        while(n--){
            Node *curr=q.front();
            q.pop();
            if (curr->left)
            q.push(curr->left);
            if (curr->right)
            q.push(curr->right);
        }
    }
}
int maxLevel=0;
void printLeft(Node *root,int level){ // theta(n) and theta(h).
    if (root!=NULL){
    if(maxLevel<level){
        cout<<root->key<<" ";
        maxLevel=level;
    }
    printLeft(root->left,level+1);
    printLeft(root->right,level+1);
    }
}
int main(){
    Node *root=new Node(10);
    root->left=new Node(20);   
    root->right=new Node(30);   
    root->left->left=new Node(40);   
    root->left->right=new Node(50);   
    // root->left->right->left=new Node(9);   
    // root->left->right->right=new Node(15);   
    // root->right->right=new Node(60);   
    // print1(root);
    printLeft(root, 1);
    return 0;
}