#include <iostream>
#include <string>
using namespace std;
// can use minval and maxval logic also.
Node* constructTree(int pre[], int n)
{
    int i=0;
    Node *root=newNode(pre[i]);
    i++;
    stack<Node*> st;
    st.push(root);
    while(st.empty()==false && i<n){
        Node *curr=st.top();
        if (pre[i]<curr->data){
            curr->left=newNode(pre[i]);
            st.push(curr->left);
        }
        else{
            Node *temp=st.top();
            while(st.empty()==false && st.top()->data<pre[i]){
                temp=st.top();
                st.pop();
            }
            temp->right=newNode(pre[i]);
            st.push(temp->right);
        }
        i++;
    }
    return root;
}
int main(){
    float i = 123.0f;
    cout << i << endl;
    return 0;
}