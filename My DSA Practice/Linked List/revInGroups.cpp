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
node *rev(node *head, int k){ // recursive.
    node *curr=head, *prev=NULL, *next=NULL;
    int count=0;
    while(curr!=NULL && count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if (next!=NULL){
        node *rest_head=rev(next, k);
        head->next=rest_head;
    }
    return prev;
}
node *rev1(node *head, int k){ // iterative.
    node *curr=head, *prevfirst=NULL;
    bool flag=true;
    while(curr!=NULL){
        node *first=curr, *prev=NULL;
        int count=0;
        while(curr!=NULL && count<k){
            node *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if (flag){head=prev; flag=false;}
        else{prevfirst->next=prev;}
        prevfirst=first;
    }
    return head;
}
int main(){
    node *head=new node(10);
    // head->next=new node(20);
    // head->next->next=new node(30);
    // head->next->next->next=new node(40);
    // head->next->next->next->next=new node(50);
    // head->next->next->next->next->next=new node(60);
    // head->next->next->next->next->next->next=new node(70);
    // head=rev(head, 3);
    print(head);
    return 0;
}