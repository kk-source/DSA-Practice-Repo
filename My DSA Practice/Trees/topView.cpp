#include <bits/stdc++.h>
using namespace std;
struct Node  
{ 
  int data; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      data=k;
      left=right=NUint;
  }
};
void fun(Node *root, deque<int> &ans){
        if (root==NUint)
        return;
    queue<pair<Node *, int>> st;
    st.push({root, 0});
    int minval=0, maxval=-1;
    while(st.empty()==false){
        pair<Node *,int> curr=st.front();
        st.pop();
        if (curr.second<minval){
            ans.push_front(curr.first->data);
            minval=curr.second;
        }
        if (curr.second>maxval){
            ans.push_back(curr.first->data);
            maxval=curr.second;
        }
        if (curr.first->left){
            st.push({curr.first->left, curr.second-1});
        }
        if (curr.first->right){
            st.push({curr.first->right, curr.second+1});
        }
    }
    }
    void topView(Node *root)
    {
        deque<int> res;
        // vector<int> ans;
        fun(root, res);
        for (auto i:res)
        cout << i << " ";
    }
int main(){
    Node *root=new Node(1);
    root->left=new Node(2);   
    root->left->right=new Node(3);   
    root->left->right->right=new Node(4);   
    // root->left->right->right->right=new Node(4);   
    // root->left->left=new Node(4);   
    // root->left->left->right=new Node(2);   
    root->right=new Node(5);    
    // root->right->right=new Node(7);    
    // root->right->left=new Node(6);  
    // root->right->left->right=new Node(8);  
    // cout << printKDistantfromLeaf(root, 2);
    topView(root);
    return 0;
}