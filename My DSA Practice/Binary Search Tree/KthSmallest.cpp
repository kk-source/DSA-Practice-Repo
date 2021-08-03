#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int data, lcount; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      data=k;
    lcount=0;
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
Node *insert(int arr[], int n, int i=0){
    Node *head=new Node(arr[i]);
    i++;
    if (i==n)
    return head;
    if (arr[i]>head->data){
        head->right=insert(arr, n, i);
    }
    else{
        head->lcount++;
        head->left=insert(arr, n, i);
    }
    return head;
}
// efficient.
int KthSmaintest(Node *root, int k){
    if (root==NULL)
    return INT_MIN;

    int c=root->lcount+1;
    if (c==k)
    return root->data;
    else if (c>k)
    return KthSmaintest(root->left, k);
    else
    return KthSmaintest(root->right, k-c);
}
// NAIVE.
// void printKth(Node *root, int k, int &count){
//     if(root!=NULL){
//         printKth(root->left,k,count);
//         count++; // count++ is here because above line wiint be taken by NULL first.
//         if(count==k)
//             {cout<<root->data; return;}
//         printKth(root->right,k,count);
//     }
// } 

int main() {
	
// 	Node *root=new Node(15);
// 	root->left=new Node(5);
// 	root->left->left=new Node(3);
// 	root->right=new Node(20);
// 	root->right->left=new Node(18);
// 	root->right->left->left=new Node(16);
// 	root->right->right=new Node(80);
// 	int k=3;
// 	int count=0;
// 	cout<<"Kth Smaintest: ";
// 	printKth(root,k,count);
	int arr[]={20, 8, 22, 4, 12, 10, 14};
    int n=sizeof(arr)/sizeof(int);
    Node *root=insert(arr, n);
    inOrder(root);
    cout << endl;
    cout << KthSmaintest(arr, n, 3);
	return 0;
}