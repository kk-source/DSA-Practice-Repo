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
    node * mergeKLists(node *arr[], int K)
    {
        node *head=arr[0];
           for (int i=1;i<K;i++)
               head=merge(head, arr[i]);
           
        return head;
    }
int main(){
    node *head1=new node(1);
    head1->next=new node(2);
    head1->next->next=new node(3); 
    node *head2=new node(4);
    head2->next=new node(5);
    node *head3=new node(5);
    head3->next=new node(6);
    // head3->next->next=new node(3); 
    node *head4=new node(7);
    head4->next=new node(8);
    // head4->next->next=new node(3); 
    node *arr[]={head1, head2, head3, head4};
    // head->next->next->next=new node(40);
    // head->next->next->next->next=new node(50);
    // head->next->next->next->next->next=new node(60);
    // head1=mergeKLists(arr, 4);
    head1=mergeKLists(arr, 4);
    print(head1);
    return 0;
}