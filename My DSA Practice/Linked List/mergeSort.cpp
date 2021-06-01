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
/* for doubly linked list.
 node *merge(node *head1, node *head2){
    node *head, *curr;
    if (head1->data<=head2->data){
        head=head1;
        curr=head;
        head1=head1->next;
    }
    else {
        head=head2;
        curr=head;
        head2=head2->next;
    }
    while(head1!=NULL && head2!=NULL){
        if (head1->data<=head2->data){
            
        curr->next=head1;
        curr->next->prev=curr;
        curr=curr->next;
        head1=head1->next;
    }
        else {
        curr->next=head2;
        curr->next->prev=curr;
        curr=curr->next;
        head2=head2->next;
    }
    }
    if (head1==NULL){
        curr->next=head2;
        curr->next->prev=curr;
        curr=curr->next;
    }
    if (head2==NULL){
        curr->next=head1;
        curr->next->prev=curr;
        curr=curr->next;
    }
    return head;
}
struct node *sortDoubly(struct node *head)
{
	if (head->next==NULL)
	return head;
	node *slow=head, *fast=head;
	while(fast->next!=NULL && fast->next->next!=NULL){
	    slow=slow->next;
	    fast=fast->next->next;
	    if (slow==fast)
	    break;
	}
	slow->next->prev=NULL;
	node *head2=sortDoubly(slow->next);
	slow->next=NULL;
	node *head1=sortDoubly(head);
	head1=merge(head1, head2);
	return head1;
}*/
node *merge(node *head1, node *head2){
        node *head, *curr;
        if (head1->data<=head2->data){
            head=head1;
            curr=head1; // or curr=head;
            head1=head1->next;
        }
        else {
            head=head2;
            curr=head2; // or curr=head;
            head2=head2->next;
        }
        while(head1!=NULL && head2!=NULL){
            if (head1->data<=head2->data){
                curr->next=head1;
                head1=head1->next;
                curr=curr->next;
            }
            else{
                curr->next=head2;
                head2=head2->next;
                curr=curr->next;
            }
        }
        if (head1==NULL){
            curr->next=head2;
        }
        if (head2==NULL){
            curr->next=head1;
        }
        return head;
    }
    node* mergeSort(node* head) {
        if (head->next==NULL)
        return head;
        node *slow=head, *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if (fast==slow){
                break;
            }
        }
        node *head2=mergeSort(slow->next);
        slow->next=NULL;
        node *head1=mergeSort(head);
        head1=merge(head1, head2);
        return head1;
    }
void print(node *head){
    while(head!=NULL){
        cout << head->data << " ";
        head=head->next;
    }
}
int main(){
    node *head=new node(3);
    head->next=new node(5);
    head->next->next=new node(2); 
    head->next->next->next=new node(4);
    head->next->next->next->next=new node(1);
    // head->next->next->next->next->next=new node(0);
    // head->next->next->next->next->next->next=new node(2);
    // head->next->next->next->next->next->next->next=new node(2);
    // head->next->next->next->next=new node(5);
    head=mergeSort(head);
    print(head);
    return 0;
}