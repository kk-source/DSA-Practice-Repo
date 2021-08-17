#include <iostream>
#include <string>
using namespace std;
void fun(Node *root, int &minval, int &maxval, int hd=0){
    if (root==NULL)
    return ;
    if (hd<minval)
    minval=hd;
    if (hd>maxval)
    maxval=hd;
    fun(root->left, minval, maxval, hd-1);
    fun(root->right, minval, maxval, hd+1);
}
int verticalWidth(Node* root)
{
    if (root==0)
    return 0;
    int minval=0, maxval=0;
    fun(root, minval, maxval);
    return (abs(minval)+maxval+1);
}
int main(){
    

    return 0;
}