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
Node* constructBst(int arr[], int n)
{
    int i=0;
    Node *root=new Node(arr[i]);
    queue<pair<Node *, pair<int, int>>> s;
    s.push({root, {INT_MIN, INT_MAX}});
    i++;
    while(s.empty()==false){
        Node *curr=s.front().first;
        int minval=s.front().second.first;
        int maxval=s.front().second.second;
        s.pop();
        int a=2;
        while(a--){
        if (i<n && arr[i]<maxval && arr[i]>minval){
            if (arr[i]<curr->data){
            curr->left=new Node(arr[i]);
            s.push({curr->left, {minval, curr->data}});
            i++;
            }
            else if (arr[i]>curr->data){
            curr->right=new Node(arr[i]);
            s.push({curr->right, {curr->data, maxval}});
            i++;
            break;
            }
        }
        }
        if (i>=n)
        break;
    }
    return root;
}
int main(){
    int arr[]={7,4,12,3,6,8,1,5,10};
	int n=9;
	Node *root=constructBst(arr, n);
	inOrder(root);
    return 0;
}