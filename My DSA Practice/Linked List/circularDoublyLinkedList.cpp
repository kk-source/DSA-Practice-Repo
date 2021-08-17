#include <iostream>
#include <string>
using namespace std;
struct node {
    int data;
    node *next, *prev;
    node (int x){
        data=x;
        next=NULL;
        prev=NULL;
    }
};
void print(node *head){
    if (head==NULL)
    return ;
    node *curr=head;
    do{
        cout << curr->data << " ";
        curr=curr->next;
    }while(curr!=head);
}
node *insertbegin(node *head, int key){ 
    node *temp=new node(key);
    if (head==NULL){
        temp->next=temp;
        temp->prev=temp;
        return temp;
    }
    temp->prev=head->prev;
    temp->next=head;
    head->prev->next=temp;
    head->prev=temp;
    return temp;
}
node *insertend(node *head, int key){ // same as above.
    node *temp=new node(key);
    if (head==NULL){
        temp->next=temp;
        temp->prev=temp;
        return head;
    }
    temp->prev=head->prev;
    temp->next=head;
    head->prev->next=temp;
    head->prev=temp;
    return head;
}
int main(){
    node *head=new node(10);
    head->next=new node(20);
    head->next->prev=head;
    head->next->next=new node(30);
    head->next->next->prev=head->next;
    head->next->next->next=head;
    head->prev=head->next->next;
    head=insertbegin(head, 5);
    print(head);
    return 0;
}