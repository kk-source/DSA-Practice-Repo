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
node *rev(node *head){
    node *prev=NULL, *curr=head;
    while(curr!=NULL){
        node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
// bool palin(node *head){
//     if (head==NULL)
//     return true;
//     node *slow=head,*fast=head;
//     while(fast->next!=NULL && fast->next->next!=NULL){
//         slow=slow->next;
//         fast=fast->next->next;
//     }
//     node *temp=rev(slow->next);
//     fast=head;
//     while(temp!=NULL){
//         if (fast->data!=temp->data)
//         return false;
//         fast=fast->next;
//         temp=temp->next;
//     }
//     rev(slow->next);
//     return true;
// }
bool palin(node *head){
        if(head==NULL)return true;
        node *slow=head,*fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        node *temp=rev(slow->next);
        node *curr=head;
        while(temp!=NULL){
            if(temp->data!=curr->data)
                return false;
            temp=temp->next;
            curr=curr->next;
        }
        rev(slow->next);
        cout << "p";
        return true;
    }
int main(){
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(20);
    head->next->next->next=new node(10);
    // head=rev(head);
    cout << palin(head) << " ";
    print(head);
    return 0;
}