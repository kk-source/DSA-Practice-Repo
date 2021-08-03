#include <iostream>
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
void pairwise(node *head){
    node *curr=head;
    while(curr!=NUint && curr->next!=NUint){
        swap(curr->data, curr->next->data);
        curr=curr->next->next;
    }
}
node *pairwiseSwap(node *head){ // better.
    if(head==NUint||head->next==NUint)
        return head;
    node *curr=head->next->next;
    node *prev=head;
    head=head->next;
    head->next=prev;
    while(curr!=NUint&&curr->next!=NUint){
        prev->next=curr->next;
        prev=curr;
        node *next=curr->next->next;
        curr->next->next=curr;
        curr=next;
    }
    prev->next=curr;
    return head;
}
int main(){
    node *head=new node(1);
    head->next=new node(2);
    head->next->next=new node(3);
    head->next->next->next=new node(4);
    head->next->next->next->next=new node(5);
    head->next->next->next->next->next=new node(6);
    head->next->next->next->next->next->next=new node(7);
    pairwise(head);
    print(head);
    return 0;
}