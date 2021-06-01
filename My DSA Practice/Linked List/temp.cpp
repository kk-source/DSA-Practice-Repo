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
node *rev(node *head){
    node *prev=NULL;
    while(head!=NULL){
        node *next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
    return prev;
}
node* addSameSize(node* head1, node* head2) 
{ 
	head1=rev(head1);
	head2=rev(head2);
	int val=(head1->data+head2->data);
	node *head=new node(val%10);
	node *curr=head;
	val/=10;
	head1=head1->next;
	head2=head2->next;
	while(head1!=NULL && head2!=NULL){
	    val+=(head1->data+head2->data);
	    node *temp=new node (val%10);
	    curr->next=temp;
	    curr=curr->next;
	    val/=10;
	    head1=head1->next;
	    head2=head2->next;
	}
	while (head1!=NULL){
	    val+=head1->data;
	    node *temp=new node(val%10);
	    curr->next=temp;
	    curr=curr->next;
	    val/=10;
	    head1=head1->next;
	}
	while (head2!=NULL){
	    val+=head2->data;
	    node *temp=new node(val%10);
	    curr->next=temp;
	    curr=curr->next;
	    val/=10;
	    head2=head2->next;
	}
	head=rev(head);
	return head;
} 
int main(){
    node *head=new node(3);
    node *curr=head;
    // head->next=new node(5);
    // head->next->next=new node(2); 
    // head->next->next->next=new node(4);
    // head->next->next->next->next=new node(1);
    // head->next->next->next->next->next=new node(0);
    // head->next->next->next->next->next->next=new node(2);
    // head->next->next->next->next->next->next->next=new node(2);
    // head->next->next->next->next=new node(5);
    // for (int i=0;i<76;i++){
    //     int n;
    //     cin >> n;
    //     node *temp=new node(n);
    //     curr->next=temp;
    //     curr=curr->next;
    // }
    // node *head1=new node(3);
    // curr=head1;
    // for (int i=0;i<19;i++){
    //     int n;
    //     cin >> n;
    //     node *temp=new node(n);
    //     curr->next=temp;
    //     curr=curr->next;
    // }
    // head=addSameSize(head, head1);
    // print(head);
    return 0;
}