#include <iostream>
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
node *merge(node *h1, node *h2){
    if (h1==NULL || h2==NULL)
        return (h1==NULL)? h2:h1;
    node *head;
    if (h1->data<=h2->data){
        head=h1; h1=h1->next;
    }
    else{
        head=h2; h2=h2->next;
    }
    node *curr=head;
    while(h1!=NULL && h2!=NULL){
        if (h1->data<=h2->data){
            curr->next=h1;
            h1=h1->next;
        }
        else{
            curr->next=h2;
            h2=h2->next;
        }
            curr=curr->next;
    }
    if (h1==NULL)
        curr->next=h2;
    
    if (h2!=NULL)
        curr->next=h1;
    return head;
}
int main(){
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    node *head1=new node(5);
    head1->next=new node(15);
    head1->next->next=new node(17);
    head1->next->next->next=new node(18);
    head1->next->next->next->next=new node(35);
    head=merge(head, head1);
    print(head);
    return 0;
}