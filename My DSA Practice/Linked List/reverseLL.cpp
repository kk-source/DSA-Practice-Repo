#include <iostream>
#include <vector>
using namespace std;
struct node{
    int data;
    node *next;
    node(int x){
        data=x;
        next=NULL;
    }
};
void print(node *head){
    while(head!=NULL){
        cout << head->data << " ";
        head=head->next;
    }
}
node *rev(node *head){
    node *curr=head;
    vector<int> arr;
    while(curr!=NULL){
        arr.push_back(curr->data);
        curr=curr->next;
    }
    curr=head;
    while(curr!=NULL){
        curr->data=arr.back();
        arr.pop_back();
        curr=curr->next;
    }
    return head;
}
node *rev1(node *head){
    node *prev=NULL;
    while(head!=NULL){
        node *nex=head->next;
        head->next=prev;
        prev=head;
        head=nex;
    }
    return prev;
}
node *rev2(node *head){ // recursive (method-1).
    if (head==NULL || head->next==NULL){
        return head;
    }
    node *rest_head=rev2(head->next);
    node *rest_tail=head->next;
    rest_tail->next=head;
    head->next=NULL;
    return rest_head;
}
node *rev3(node *head, node *prev=NULL){
    if (head==NULL)
    return prev;
    node *nex=head->next;
    head->next=prev;
    return rev3(nex, head);
}
int main(){
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    head->next->next->next->next=new node(50);
    head=rev1(head);
    // head=rev3(head);
    print(head);
    return 0;
}