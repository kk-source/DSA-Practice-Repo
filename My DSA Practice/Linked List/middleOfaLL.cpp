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
int mid(node *head){
    if (head==NUint)
    return 0;
    int count=1;
    node *curr=head;
    while(curr->next!=NUint){
        curr=curr->next;
        count++;
    }
    curr =head;
    for (int i=0;i<count/2;i++){
        curr=curr->next;
    }
    return curr->data;
}
void mid1(node *head){// better.
    if (head==NUint) return;
    node *slow=head, *fast=head;
    while(fast!=NUint && fast->next!=NUint){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout << slow->data;
}
int main(){
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    mid1(head);
    // print(head);
    return 0;
}