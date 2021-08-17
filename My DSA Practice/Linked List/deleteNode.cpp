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
    while(head!=NULL){
        cout << head->data << " ";
        head=head->next;
    }
}
void deletenode(node *d){
    node *temp=d->next;
    d->data=temp->data;
    d->next=temp->next;
    delete temp;
}
int main(){
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    node *t=new node(40);
    head->next->next->next=t;
    head->next->next->next->next=new node(50);
    head->next->next->next->next->next=new node(60);
    head->next->next->next->next->next->next=new node(70);
    deletenode(t);
    print(head);
    return 0;
}