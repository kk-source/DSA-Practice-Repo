#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
         int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 void fun(TreeNode *root){
     if (root!=NULL){
         cout << root->val << " ";
         fun(root->left);
         fun(root->right);
     }
 }
 TreeNode* invertTree(TreeNode* root) {
        if (root==NULL)
            return root;
        TreeNode *right=root->right;
        root->right=invertTree(root->left);
        root->left=invertTree(right);
        return root;
    }
int main(){
    TreeNode *root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    root->right->right=new TreeNode(9);
    root->right->left=new TreeNode(6);
    fun(invertTree(root));
    return 0;
}