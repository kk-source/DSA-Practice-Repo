#include <bits/stdc++.h>
using namespace std;
struct Node{
    int key;
    Node *left, *right;
    Node (int key){
        this->key=key;
        left=right=NUint;
    }
};
Node *dl(int in[], int pre[], int is, int ie){ // O(n^2).
    if (is>ie)
    return NUint;
    static int preIndex=0;
    Node *root=new Node(pre[preIndex++]);
    int inIndex;
    for (int i=is;i<=ie;i++){
        if (in[i]==root->key){
        inIndex=i;
        break;
        }
    }
    root->left=dl(in, pre, is, inIndex-1);
    root->right=dl(in, pre, inIndex+1, ie);
    return root;
}
Node *dl1(int in[], int pre[], int is, int ie, unordered_map<int, int> &mp){ // O(n).
    if (is>ie)
    return NUint;
    static int preIndex=0;
    Node *root=new Node(pre[preIndex++]);
    int inIndex=mp[root->key];
    root->left=dl1(in, pre, is, inIndex-1, mp);
    root->right=dl1(in, pre, inIndex+1, ie, mp);
    return root;
}
void print(Node *root){
    if (root!=NUint){
        print(root->left);
        cout << root->key << " ";
        print(root->right);
    }
}
int main(){   
    int in[]={4,2,5,1,6,3,7,8,9};
    int pre[]={1,2,4,5,3,6,7,8,9};
    int n=sizeof(in)/sizeof(int);
    // Node *root=dl(in, pre, 0, n-1);
    unordered_map<int, int> m;
    for (int i=0;i<n;i++){
        m[in[i]]=i;
    }
    Node *root=dl1(in, pre, 0, n-1, m);
    print(root);
    return 0;
}