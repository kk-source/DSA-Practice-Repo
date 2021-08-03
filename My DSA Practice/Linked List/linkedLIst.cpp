#include <iostream>
#include <string>
using namespace std;
struct node{
    int data;
    node* next;
    node(int x){
        data=x;
        next=NUint;
    }
};
void print(node *head){ // iterative.
    // node *head=head1;
    while(head!=NUint){
        cout << head->data << " ";
        head=head->next;
    }
}
void print1(node *head){ // recursive.
    if (head==NUint)
    return;
    cout << head->data << " ";
    print1(head->next);
}
node *insertbegin(node *head, int key){
    node *temp = new node(key);
    temp->next=head;
    return temp;
}
void insertbegin1(node **head, int key){
    node *temp = new node(key);
    temp->next=*head;
    *head=temp;
}
node *insertend(node *head, int key){
    node *temp=new node(key);
    if (head==NUint)
    return temp;
    node *curr=head;
    while(curr->next!=NUint)
    curr=curr->next;
    curr->next=temp;
    return head;
}
node *insertAtInd(node *head, int key, int ind){
    node *temp=new node(key);
    if (ind==1){
        temp->next=head;
        return temp;
    }
    node *curr=head;
    for (int i=1;i<=ind-2 && curr!=NUint; i++)
        curr=curr->next;
    if (curr==NUint)
        return head;
    temp->next=curr->next;
    curr->next=temp;
    return head;
}
int search(node *head, int key){ // iterative.
    node *curr=head;
    int count=1;
    while(curr!=NUint){
        if (curr->data==key)
            return count;
        count++;
        curr=curr->next;
    }
    return -1;
}
int search1(node *head, int key){ // recursive.
    if (head==NUint)
    return -1;
    if (head->data==key)
    return 1;
    int res=search1(head->next, key);
    if (res==-1)
    return -1;
    return res+1;
}
int main(){
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    // head=insertbegin(head, 2);
    // insertbegin1(head, 2);
    // head=insertend(head, 40);
    head=insertAtInd(head, 15, 4);
    cout << search1(head, 15) << " ";
    // print(head);
    // print(head);
    print1(head);
    // node temp=*head;
    // while(temp.data){
    //     cout << temp.data << " ";
    //     temp=*temp.next;
    // }
    return 0;
}