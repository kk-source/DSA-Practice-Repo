#include <iostream>
#include <string>
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
    if (head==NULL)
    return;
    node *curr=head;
    do{
        cout << curr->data << " ";
        curr=curr->next;
    }while(curr!=head);
}
node *insertbegin(node *head, int key){ // theta(n).
    node *temp=new node(key);
    if (head==NULL)
    temp->next=temp;
    else{
        node *curr=head;
        while(curr->next!=head)
        curr=curr->next;
        curr->next=temp;
        temp->next=head;
    }
    return temp;
}
node *insertbegin1(node *head, int key){ // O(1).
    node *temp=new node(key);
    if (head==NULL){
    temp->next=temp;
    return temp;
    }
    temp->next=head->next;
    head->next=temp;
    swap(head->data, temp->data);
    return head;
}
node *insertend(node *head, int key){ // theta(n).
    node *temp=new node(key);
    if (head==NULL){
    temp->next=temp;
    return temp;
    }
    node *curr=head;
    while(curr->next!=head)
    curr=curr->next;
    curr->next=temp;
    temp->next=head;
    return head;
}
node *insertend1(node *head, int key){ // O(1).
    node *temp=new node(key);
    if (head==NULL){
        temp->next=temp;
        return temp;
    }
    temp->next=head->next;
    head->next=temp;
    swap(head->data, temp->data);
    return temp;
}
node *deletehead(node *head){ // theta(n).
    if (head==NULL)
    return NULL;
    if (head->next==head){
        delete head;
        return NULL;
    }
    node *curr=head;
    while(curr->next!=head)
        curr=curr->next;
    curr->next=head->next;
    delete head;
    return curr->next;
}
node *deletehead1(node *head){ // O(1).
    if (head==NULL)
    return NULL;
    if (head->next==head){
        delete head;
        return NULL;
    }
    head->data=head->next->data;
    node *curr=head->next;
    head->next=head->next->next;
    delete curr;
    return head;
}
node *deletekth(node *head, int k){
    if (head==NULL) return NULL;
    if (k==1) return deletehead1(head);
    int count=2;
    node *curr=head;
    while(count < k){
        curr=curr->next;
        count++;
        if (curr->next==head)
        break;
    }
    if (curr->next==head)
    return head;
    node *temp=curr->next;
    curr->next=curr->next->next;
    delete temp;
    return head;
}
int main(){
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=head;
    // head=insertend1(head, 5);
    // head=deletehead1(head);
    head=deletekth(head, 1);
    print(head);
    return 0;
}