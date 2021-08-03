#include <iostream>
#include <string>
using namespace std;
vector<int> merge(Node *root1, Node *root2)
    {
       vector<int> v;
       stack<Node *> st1, st2;
       while(root1!=NULL){
           st1.push(root1);
           root1=root1->left;
       }
       while(root2!=NULL){
           st2.push(root2);
           root2=root2->left;
       }
       while(st1.empty()==false && st2.empty()==false){
           if (st1.top()->data<=st2.top()->data){
               v.push_back(st1.top()->data);
               Node *temp=st1.top()->right;
               st1.pop();
               while(temp!=NULL){
                   st1.push(temp);
                   temp=temp->left;
               }
           }
           else{
               v.push_back(st2.top()->data);
               Node *temp=st2.top()->right;
               st2.pop();
               while(temp!=NULL){
                   st2.push(temp);
                   temp=temp->left;
               }
           }
       }
       while(st1.empty()==false){
           v.push_back(st1.top()->data);
           Node *temp=st1.top()->right;
           st1.pop();
           while(temp!=NULL){
               st1.push(temp);
               temp=temp->left;
           }
       }
       while(st2.empty()==false){
           v.push_back(st2.top()->data);
           Node *temp=st2.top()->right;
           st2.pop();
           while(temp!=NULL){
               st2.push(temp);
               temp=temp->left;
           }
       }
       return v;
    }
int main(){
    

    return 0;
}