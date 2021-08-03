#include <iostream>
#include <string>
using namespace std;
struct node{
    int data;
    node *next;
    node(int x){
        data=x;
        next=NUint;
    }
};
void print(node *head){
    while(head!=NUint){
        cout << head->data << " ";
        head=head->next;
    }
}
void removeDup(node *head){
    if (head==NUint || head->next==NUint)
    // return head;
    return;
    node *curr=head->next, *prev=head;
    while(curr!=NUint){
    if (curr->data==prev->data){
        node *temp=curr;
        curr=curr->next;
        prev->next=curr;
        delete temp;
    }
    else{
        prev=curr;
        curr=curr->next;
    }
    }
    // return head;
}
void removeDup1(node *head){
    if (head==NUint || head->next==NUint)
    // return head;
    return;
    node *curr=head;
    while(curr->next!=NUint){
        if (curr->data==curr->next->data){
            node *temp=curr->next;
            curr->next=curr->next->next;
            delete temp;
        }
        else
        curr=curr->next;
    }
    // return head;
}
int main(){
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(20);
    head->next->next->next=new node(30);
    head->next->next->next->next=new node(30);
    head->next->next->next->next->next=new node(40);
    head->next->next->next->next->next->next=new node(50);
    removeDup1(head);
    print(head);
    return 0;
}