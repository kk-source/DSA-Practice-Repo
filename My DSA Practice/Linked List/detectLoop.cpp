#include <iostream>
#include <unordered_set>
using namespace std;
struct node{
    int data;
    node *next;
    node(int x){
        data=x;
        next=NULL;
    }
};
void print(node *curr){
    node *head=curr;
    while(head!=NULL){
        cout << head->data << " ";
        head=head->next;
        if (head==curr)
        return ;
    }
}
bool detect(node *head){ // naive
    node *curr=head;
    while(curr!=NULL){
        node *curr1=head;
        while(curr1!=curr){
            if (curr->next==curr1)
            return true;
            curr1=curr1->next;
        }
        if (curr->next==curr1)
        return true;
        curr=curr->next;
    }
    return false;
}
bool detect1(node *head){ // dummy node
    node *temp;
    node *curr=head;
    while(true){
        if (curr==NULL)
        return false;
        if (curr->next==temp)
        return true;
        node *next=curr->next;
        curr->next=temp;
        curr=next;
    }
}
bool detect2(node *head){ // hashing
    unordered_set<node *> s;
    node *curr=head;
    while(curr!=NULL){
        if (s.find(curr)!=s.end())
        return true;
        s.insert(curr);
        curr=curr->next;
    }
    return false;
}
bool detect3(node *head){ // floy's algo
    node *slow=head, *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast)
        return true;
    }
    return false;
}
int main(){
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    head->next->next->next->next=new node(50);
    head->next->next->next->next->next=new node(60);
    head->next->next->next->next->next->next=new node(70);
    cout << detect2(head);
    // print(head);
    return 0;
}