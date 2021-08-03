#include <bits/stdc++.h>
using namespace std;
struct Node  
{ 
  int data; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      data=k;
      left=right=NULL;
  }
};
void inOrder(Node *root){
    if (root==NULL)
    return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void print(Node *root){
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    map<int, int> ans;
    while(q.empty()==false){
        auto p=q.front();
        q.pop();
        Node *curr=p.first;
        int val=p.second;
        ans[val]=curr->data;
        if (curr->left)
        q.push({curr->left, val-1});
        if (curr->right)
        q.push({curr->right, val+1});
    }
    for (auto i:ans)
    cout << i.second << " ";
}
int main(){
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    // root->left->right->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    // root->right->right->left=new Node(8);
    // root->right->right->left->left=new Node(9);
    // inOrder(root);
    // cout << endl;
    print(root);
    return 0;
}