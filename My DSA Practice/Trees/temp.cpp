// check subtree.
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
void preorder(Node *root, string &str){
        if (root==NULL){
            str+="*";
            return;
        }
        int data=root->data;
        string c=to_string(data);
        str+=c;
        preorder(root->left, str);
        preorder(root->right, str);
    }
    void inorder(Node *root, string &str){
        if (root==NULL){
            str+="*";
            return;
        }
        inorder(root->left, str);
        int data=root->data;
        string c=to_string(data);
        str+=c;
        inorder(root->right, str);
    }
    bool isSubTree(Node* T, Node* S) 
    {
        string Tstr, Sstr;
        preorder(T, Tstr);
        preorder(S, Sstr);
        if (Tstr.find(Sstr)==string::npos)
        return false;
        string Tstr1, Sstr1;
        inorder(T, Tstr1);
        inorder(S, Sstr1);
        if (Tstr1.find(Sstr1)==string::npos)
        return false;
        return true;
    }
int main(){
    Node *root=new Node(1);
    root->left=new Node(2); 
    // root->left->left=new Node(3); 
    // root->left->right=new Node(4); 
    // root->left->left->left=new Node(5); 
    // root->left->left->right=new Node(6);
    root->right=new Node(3); 
    Node *soot=new Node(1);
    soot->left=new Node(2); 
    soot->left->left=new Node(3); 
    soot->left->right=new Node(4); 
    soot->left->left->left=new Node(5); 
    soot->left->left->right=new Node(6);      
    cout << isSubTree(root, soot);
    return 0;
}