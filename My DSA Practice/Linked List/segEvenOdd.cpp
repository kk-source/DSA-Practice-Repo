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
void segEvenOdd(node *head){ // naive.
    node *prev=head, *curr=head;
    while(curr!=NULL){
        if (curr->data%2==0){
            int temp=prev->data;
            prev->data=curr->data;
            node *t=prev->next;
            while(t!=curr->next){
                swap(temp, t->data);
                t=t->next;
            }
            prev=prev->next;
        }
        curr=curr->next;
    }
}
node *segEvenOdd1(node *head){ // recursive.
    node *eS=NULL, *eE=NULL, *oS=NULL, *oE=NULL;
    for (node *curr=head;curr!=NULL;curr=curr->next){
        int x=curr->data;
        if (x%2==0){
            if (eS==NULL){
                eS=curr;
                eE=curr;
            }
            else{
                eE->next=curr;
                eE=eE->next;
            }
        }
        else{
            if (oS==NULL){
                oS=curr;
                oE=curr;
            }
            else{
                oE->next=curr;
                oE=oE->next;
            }
        }
    }
    if (oS==NULL || eS==NULL)
    return head;
    eE->next=oS;
    oE->next=NULL;
    return eS;
}
int main(){
    node *head=new node(1);
    head->next=new node(3);
    head->next->next=new node(5);
    head->next->next->next=new node(12);
    head->next->next->next->next=new node(10);
    head->next->next->next->next->next=new node(5);
    head->next->next->next->next->next->next=new node(4);
    head=segEvenOdd1(head);
    print(head);
    return 0;
}