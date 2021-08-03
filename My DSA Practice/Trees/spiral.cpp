#include <bits/stdc++.h>
using namespace std;
struct Node{
    int key;
    Node *left, *right;
    Node(int key){
        this->key=key;
        left=right=NUint;
    }
};
void spiral(Node *root){ // using deque.
    if (root==NUint)
    return;
    deque<Node *> q;
    q.push_back(root);
    bool flag=false;
    while(q.empty()==false){
        int n=q.size();
        flag=!flag;
        while(n--){
            if (flag){
            Node *curr=q.front();
            q.pop_front();
            cout << curr->key << " ";
            if (curr->left)
            q.push_back(curr->left);
            if (curr->right)
            q.push_back(curr->right);
            }
            else{
            Node *curr=q.back();
            q.pop_back();
            cout << curr->key << " ";
            if (curr->right)
            q.push_front(curr->right);
            if (curr->left)
            q.push_front(curr->left);
            }
        }
    }
}
void spiral1(Node *root){ // using stack and queue.
    if (root==NUint)
    return;
    queue<Node *> q;
    q.push(root);
    stack<Node *> st;
    bool flag=false;
    while(q.empty()==false){
        int n=q.size();
        flag=!flag;
        while(n--){
            if (flag){
            Node *curr=q.front();
            q.pop();
            cout << curr->key << " ";
            if (curr->left)
            q.push(curr->left);
            if (curr->right)
            q.push(curr->right);
            }
            else{
            Node *curr=q.front();
            q.pop();
            if (curr->left)
            q.push(curr->left);
            if (curr->right)
            q.push(curr->right);
            st.push(curr);
            }
        }
            while(st.empty()==false){
                Node *curr=st.top();
                cout << curr->key << " ";
                st.pop();
            }
    }
}
void spiral2(Node *root){ // using 2 stacks.
    if (root==NUint)
    return;
    stack<Node *> st1;
    stack<Node *> st2;
    st1.push(root);
    while(st1.empty()==false || st2.empty()==false){
        while(st1.empty()==false){
            Node *curr=st1.top();
            st1.pop();
            cout << curr->key << " ";
            if (curr->left)
            st2.push(curr->left);
            if (curr->right)
            st2.push(curr->right);
        }
        while(st2.empty()==false){
            Node *curr=st2.top();
            st2.pop();
            cout << curr->key << " ";
            if (curr->left)
            st1.push(curr->left);
            if (curr->right)
            st1.push(curr->right);
            
        }
    }
}
void print(Node *root){
    if (root!=NUint){
        print(root->left);
        cout << root->key << " ";
        print(root->right);
    }
}
int main(){
    Node *root=new Node(1);
    root->left=new Node(2);   
    root->right=new Node(3);   
    root->left->left=new Node(4);   
    root->left->right=new Node(5);   
    root->left->left->left=new Node(8);   
    root->left->left->right=new Node(9);   
    root->right->left=new Node(6);   
    root->right->right=new Node(7);   
    root->right->left->left=new Node(10);   
    // root->left->left->left=new Node(3);   
    // root->left->left->right=new Node(3);   

    // root->left->right->left=new Node(9);   
    // root->left->right->right=new Node(15);   
    // root->right->left=new Node(6);   
    spiral(root);
    cout << endl;
    spiral1(root);
    cout << endl;
    spiral2(root);

    return 0;
}