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
int height(Node *root){
    if (root==NULL)
    return 0;
    return 1+max(height(root->left), height(root->right));
}
void fun(Node *root, int k, bool ans[], int *temp, int ind, int &res){
    if (root==NULL)
    return;
    temp[ind]=root->data;
    ans[ind]=false; // do dry run for below test case.
    cout << root->data << " " << ans[ind] << endl;
    if (root->left==NULL && root->right==NULL && ind-k>=0 && ans[ind-k]==false){
            res++;
            ans[ind-k]=true;
            return;
    }
    fun(root->left, k, ans, temp, ind+1, res);
    fun(root->right, k, ans, temp, ind+1, res);
}
int printKDistantfromLeaf(Node* root, int k)
{
    if (root==NULL || k<0)
    return 0;
	int h=height(root);
    int *arr=new int[h];
    bool ans[h]={false};
    int res=0;
	fun(root, k, ans, arr, 0, res);
	return res;
}
// Using set.
/* 
void fun(Node *root, int k, unordered_set<Node *> &ans, Node **temp, int ind){
    if (root==NULL)
    return;
    temp[ind]=root;
    if (root->left==NULL && root->right==NULL && ind-k>=0 && ans.find(temp[ind-k])==ans.end()){
            ans.insert(temp[ind-k]);
            return;
    }
    fun(root->left, k, ans, temp, ind+1);
    fun(root->right, k, ans, temp, ind+1);
}
int printKDistantfromLeaf(Node* root, int k)
{
    if (root==NULL || k<0)
    return 0;
	int h=height(root);
    Node **arr=new Node*[h];
    unordered_set<Node *> ans;
	fun(root, k, ans, arr, 0);
	return ans.size();
}
*/
int main(){
    Node *root=new Node(1);
    root->left=new Node(2);   
    root->left->left=new Node(4);   
    root->left->right=new Node(5);     
    root->right=new Node(3);    
    root->right->left=new Node(6);    
    root->right->right=new Node(7);       
    root->right->left->right=new Node(8);    
    cout << printKDistantfromLeaf(root, 1);
    return 0;
}
