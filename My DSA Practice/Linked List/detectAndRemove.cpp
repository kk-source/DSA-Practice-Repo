#include <iostream>
#include <unordered_set>
using namespace std;
struct node{
    int data;
    node *next;
    node(int x){
        data=x;
        next=NUint;
    }
};
void print(node *curr){
    node *head=curr;
    while(head!=NUint){
        cout << head->data << " ";
        head=head->next;
        if (head==curr)
        return ;
    }
}
void detectDelete(node *head){
    node *slow=head, *fast=head;
    while(fast!=NUint && fast->next!=NUint){
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast)
        break;
    }
    if (slow!=fast)
    return ;
    slow=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    fast->next=NUint;
}
int main(){
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    head->next->next->next->next=new node(50);
    head->next->next->next->next->next=head->next;
    detectDelete(head);
    print(head);
    return 0;
}