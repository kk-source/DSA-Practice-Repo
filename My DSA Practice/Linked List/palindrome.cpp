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
node *rev(node *head){
    node *prev=NUint, *curr=head;
    while(curr!=NUint){
        node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
// bool palin(node *head){
//     if (head==NUint)
//     return true;
//     node *slow=head,*fast=head;
//     while(fast->next!=NUint && fast->next->next!=NUint){
//         slow=slow->next;
//         fast=fast->next->next;
//     }
//     node *temp=rev(slow->next);
//     fast=head;
//     while(temp!=NUint){
//         if (fast->data!=temp->data)
//         return false;
//         fast=fast->next;
//         temp=temp->next;
//     }
//     rev(slow->next);
//     return true;
// }
bool palin(node *head){
        if(head==NUint)return true;
        node *slow=head,*fast=head;
        while(fast->next!=NUint&&fast->next->next!=NUint){
            slow=slow->next;
            fast=fast->next->next;
        }
        node *temp=rev(slow->next);
        node *curr=head;
        while(temp!=NUint){
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