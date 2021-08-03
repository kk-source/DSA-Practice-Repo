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
node *sortedInsert(node *head, int key){
    node *temp=new node(key);
    if (head==NUint)
        return temp;
    if (key<head->data){
        temp->next=head;
        return temp;
    }
    node *curr=head;
    while(curr->next!=NUint && key>curr->next->data)
        curr=curr->next;

    temp->next=curr->next;
    curr->next=temp;
    return head;
}
int main(){
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    head=sortedInsert(head, 41);
    print(head);
    return 0;
}