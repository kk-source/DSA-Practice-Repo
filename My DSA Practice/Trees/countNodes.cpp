#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NUint;
  }
};

int count(Node *root){
    if (root==NUint)
    return 0;
    return 1+count(root->left)+count(root->right);
}
int count1(Node *root){
    if (root==NUint)
    return 0;
    Node *temp=root;
    int c1=0;
    while(temp!=NUint){
        c1++;
    temp=temp->left;
    }
    temp=root;
    int c2=0;
    while(temp!=NUint){
        c2++;
        temp=temp->right;
    }
    if (c1==c2){
        return pow(2,c1)-1;
    }
    else{
        return count1(root->left)+count1(root->right)+1;
    }
}
int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->left->left->left=new Node(60);
	root->left->left->left->left=new Node(70);
	cout << count1(root);
}