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
Node* insert(int arr[], int n, int i=0){
    Node *head=new Node(arr[i]);
    if (i==n-1)
    return head;
    i++;
    if (arr[i]<head->data){
        head->left=insert(arr, n, i);
    }
    else{
        head->right=insert(arr, n, i);
    }
    return head;
}
void ceil(int arr[], int n){
    Node *root=insert(arr, n);
    for (int i=0;i<n;i++){
        Node *curr=root;
        int res=INT_MAX;
        while(curr->data!=arr[i] && curr!=NULL){
            if (curr->data>arr[i] && res>curr->data)
            res=curr->data;
            
            if (curr->data>arr[i])
            curr=curr->left;
            else
            curr=curr->right;
        }
        if (res==INT_MAX)
        cout << -1 << " ";
        else
        cout << res << " ";
    }
}
void inOrder(Node *root){
    if (root==NULL)
    return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main(){
    int arr[]={2,8, 30, 15, 25, 12};
    int n=sizeof(arr)/sizeof(int);
    Node *root=NULL;
    root=insert(arr, n);
    inOrder(root);
    // cout << endl;
    // ceil (arr, n);
    return 0;
}