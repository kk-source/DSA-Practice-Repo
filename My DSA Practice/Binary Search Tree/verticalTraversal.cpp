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
void sum(Node *root){
    map<int, vector<int>> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(q.empty()==false){
        auto curr=q.front();
        q.pop();
        int val=curr.second;
        mp[val].push_back(curr.first->data);
        if (curr.first->left){
            q.push({curr.first->left, val-1});
        }
        if (curr.first->right){
            q.push({curr.first->right, val+1});
        }
    }
    for (auto j: mp){
        vector<int> v=j.second;
        for (int i:v)
        cout << i << " ";
        cout << endl;
    }
}
int main(){
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->right->right->left=new Node(8);
    root->right->right->left->left=new Node(9);
    // inOrder(root);
    // cout << endl;
    sum(root);
    return 0;
}