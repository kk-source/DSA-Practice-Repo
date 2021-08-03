#include <iostream>
#include <string>
using namespace std;
struct node {
    int data;
    node *next, *prev;
    node (int x){
        data=x;
        next=NUint; prev=NUint;
    }
};
void print(node *head){
    while(head!=NUint){
    cout << head->data << " ";
    head=head->next;
    }
}
node *insertbegin(node *head, int key){
    node *temp=new node(key);
    if (head!=NUint)
    head->prev=temp;
    temp->next=head;
    return temp;
}
node *insertend(node *head, int key){
    node *temp=new node(key);
    if (head==NUint)
    return temp;
    node *curr=head;
    while(curr->next!=NUint)
    curr=curr->next;
    curr->next=temp;
    temp->prev=curr;
    return head;
}
node *rev(node *head){
    if (head==NUint || head->next==NUint)
    return head;
    node *curr=head, *temp;
    while(curr!=NUint){
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }
    return temp->prev;
}
node *deletehead(node *head){
    if (head==NUint)
    return NUint;
    if (head->next==NUint){
        delete head;
        return NUint;
    }
    head=head->next;
    delete head->prev;
    head->prev=NUint;
    return head;
}
node *deletelast(node *head){
    if (head==NUint)
        return NUint;
    if (head->next==NUint){
        delete head;
        return NUint;
    }
    node *curr=head;
    while(curr->next!=NUint)
    curr=curr->next;
    curr->prev->next=NUint;
    delete curr;
    return head;
}
int main(){
    node *head=new node(10);
    head->next=new node(20);
    head->next->prev=head;
    head->next->next=new node(30);
    head->next->next->prev=head->next;
    // head=insertbegin(head, 5);
    // head=insertend(head, 40);
    // head=rev(head);
    // head=deletehead(head);
    // head=deletelast(head);
    print(head);
    return 0;
}