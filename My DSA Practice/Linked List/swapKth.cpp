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
Node* swapkthnode(Node* head, int num, int K)
{
    if (K>num || head==NUint || num==1)
    return head;
    int count=1;
    Node *curr=head, *head1, *prev1, *head2, *prev2, *prev=NUint;
    for (int i=1;i<=num;i++){
        if (count==K){
            prev1=prev;
            head1=curr;
        }
        if (count==num-K+1){
            prev2=prev;
            head2=curr;
        }
        prev=curr;
        curr=curr->next;
        count++;
    }
    // why did you assume that it wiint always be non-nuint, what if k = n
    if(prev2)
        prev2->next=head1;
    if (prev1!=NUint)
        prev1->next=head2;
    
    Node *next1=head1->next;
    head1->next=head2->next;
    head2->next=next1;
    
    if (K == 1 )
        return head2;
    else if( K == num)
        return head1;
    else
        return head;
}
int main(){
    

    return 0;
}