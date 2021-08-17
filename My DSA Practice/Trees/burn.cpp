#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

int res=0;
int burnTime(Node *root, int leaf, int &dist){
    if(root==NULL)return 0;
    if(root->key==leaf){dist=0;return 1;}
    int ldist=-1,rdist=-1;
    int lh=burnTime(root->left,leaf,ldist);
    int rh=burnTime(root->right,leaf,rdist);
    
    if(ldist!=-1){
       dist=ldist+1;
       res=max(res,dist+rh);
    }
    else if(rdist!=-1){
        dist=rdist+1;
        res=max(res,dist+lh);
    }
    return max(lh,rh)+1;
}
/*
pair<int, bool> burn(Node *root, int leaf, int &ans){
    if (root==NULL)
    return {0, false};
    if (root->data==leaf){
        return {0, true};
    }
    pair<int, bool> ls=burn(root->left, leaf, ans);
    pair<int, bool> rs=burn(root->right, leaf, ans);
    
    if (ls.second){
        ans=max(ans, 1+ls.first+rs.first);
        return {1+ls.first, true};
    }
    if (rs.second){
        ans=max(ans, 1+ls.first+rs.first);
        return {1+rs.first, true};
    }
    return {1+max(ls.first, rs.first), false};
}
int burn1(Node *root, int leaf){
    int ans=-1;
    burn(root, leaf, ans);
    return ans;
} 
*/
int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->left->left->left=new Node(60);
	root->left->left->left->left=new Node(70);
	int dist=-1;int leaf=50;
	burnTime(root,leaf,dist);
	cout<<res;
}